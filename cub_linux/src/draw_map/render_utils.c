/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:16:56 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/10 00:22:19 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_texture(t_data *d) // Draw the texture to the screen.
{
	// How much to increase the texture coordinate per screen pixel
	d->map->step = 1.0 * TEXTHEIGHT / d->lineheight;
	// Starting texture coordinate
	d->map->tex_pos = (d->drawstart - (double)SCREENHEIGHT / 2 \
	+ (double)d->lineheight / 2) * d->map->step;

	d->y = d->drawstart - 1;
	while (++d->y < d->drawend)
	{
		d->tex_y = (int)d->map->tex_pos & (TEXTHEIGHT - 1);
		d->map->tex_pos += d->map->step;

		if (d->side == '0' && d->raydir_x > 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[SOUTH], d->tex_x, d->tex_y));
		else if (d->side == '0' && d->raydir_x < 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[NORTH], d->tex_x, d->tex_y));
		else if (d->side == '1' && d->raydir_y > 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[EAST], d->tex_x, d->tex_y));
		else if (d->side == '1' && d->raydir_y < 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[WEST], d->tex_x, d->tex_y));
	}
}

void	calc_wall_pixel(t_data *d) // Calculate the height of the wall.
{
	// The value of SCREENHEIGHT will make the walls look like cubes
    //Calculate height of line to draw on screen
	d->lineheight = (int)(SCREENHEIGHT / d->perpwalldist);

	//calculate lowest and highest pixel to fill in current stripe
	d->drawstart = -d->lineheight / 2 + SCREENHEIGHT / 2;

	if (d->drawstart < 0)
		d->drawstart = 0; // if these points lie outside the screen

	d->drawend = d->lineheight / 2 + SCREENHEIGHT / 2;

	if (d->drawend >= SCREENHEIGHT)
		d->drawend = SCREENHEIGHT - 1; // if these points lie outside the screen

	// calculate value of wall_x
	// where exactly the wall was hit
	// This is required to know which x-coordinate of the texture we have to use.
	if (d->side == '0')
		d->map->wall_x = d->pos_y + d->perpwalldist * d->raydir_y;
	else
		d->map->wall_x = d->pos_x + d->perpwalldist * d->raydir_x;
	d->map->wall_x -= floor((d->map->wall_x));

	//x coordinate on the texture
	d->tex_x = (int)(d->map->wall_x * (double)TEXWIDTH);
	if (d->side == '0' && d->raydir_x > 0)
		d->tex_x = TEXWIDTH - d->tex_x - 1;
	if (d->side == '1' && d->raydir_y < 0)
		d->tex_x = TEXWIDTH - d->tex_x - 1;
}

void	check_side(t_data *d)
{
	if (d->raydir_x < 0)
	{
		d->step_x = -1;
		d->sidedist_x = (d->pos_x - d->map_x) * d->deltadist_x; // Distance to the next x or y-side
	}
	else
	{
		d->step_x = 1;
		d->sidedist_x = (d->map_x + 1.0 - d->pos_x) * d->deltadist_x; // Distance to the next x or y-side
	}
	if (d->raydir_y < 0)
	{
		d->step_y = -1;
		d->sidedist_y = (d->pos_y - d->map_y) * d->deltadist_y; // Distance to the next x or y-side
	}
	else
	{
		d->step_y = 1;
		d->sidedist_y = (d->map_y + 1.0 - d->pos_y) * d->deltadist_y; // Distance to the next x or y-side
	}
}

void	calculations(t_data *d) // Calculate the ray position and direction.
{
	d->camera_x = 2 * (double)d->x / (double)SCREENWIDTH - 1; //d->-coordinate in camera space
	d->raydir_x = d->dir_x + d->plane_x * d->camera_x; // Ray direction
	d->raydir_y = d->dir_y + d->plane_y * d->camera_x; // Ray direction
	d->map_x = (int)d->pos_x; // Current square on the map
	d->map_y = (int)d->pos_y; // Current square on the map
	d->deltadist_x = fabs(1.0 / d->raydir_x); // Length of ray from one x or y-side to next x or y-side
	d->deltadist_y = fabs(1.0 / d->raydir_y); // Length of ray from one x or y-side to next x or y-side

	check_side(d); // Check side of the wall
}

void	perform_dda(t_data *d) // Perform DDA algorithm.
{
	d->hit = '0'; //was there a wall hit?
	// It's a loop that increments the ray with 1 square every time, until a wall is hit.
	// It always jumps 1 square at once, either in x-direction or in y-direction
	while (d->hit == '0')
	{
			//jump to next map square, either in x-direction, or in y-direction
		if (d->sidedist_x < d->sidedist_y)
		{
			d->sidedist_x += d->deltadist_x;
			d->map_x += d->step_x;
			d->side = '0';
		}
		else
		{
			d->sidedist_y += d->deltadist_y;
			d->map_y += d->step_y;
            d->side = '1';
		}
		//Check if ray has hit a wall, when the ray has hit a wall, the loop ends
		if (d->map->worldmap[d->map_x][d->map_y] > '0')
			d->hit = '1';
	}
	// Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
	if (d->side == '0') 
		d->perpwalldist = (d->sidedist_x - d->deltadist_x);
	else
		d->perpwalldist = (d->sidedist_y - d->deltadist_y);
}
