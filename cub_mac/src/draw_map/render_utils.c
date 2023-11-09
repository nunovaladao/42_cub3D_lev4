/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:16:56 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/08 17:43:07 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void draw_texture(t_data *d) // Draw the texture to the screen.
{
	// How much to increase the texture coordinate per screen pixel
	d->map->step = 1.0 * texHeight / d->lineHeight;
	// Starting texture coordinate
	d->map->texPos = (d->drawStart - (double)screenHeight / 2 \
	+ (double)d->lineHeight / 2) * d->map->step;

	d->y = d->drawStart - 1;
	while (++d->y < d->drawEnd)
	{
		d->texY = (int)d->map->texPos & (texHeight - 1);
		d->map->texPos += d->map->step;

		if (d->side == '0' && d->rayDirX > 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[SOUTH], d->texX, d->texY));
		else if (d->side == '0' && d->rayDirX < 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[NORTH], d->texX, d->texY));
		else if (d->side == '1' && d->rayDirY > 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[EAST], d->texX, d->texY));
		else if (d->side == '1' && d->rayDirY < 0)
			my_mlx_pixel_put(d->mlx, d->x, d->y, (unsigned int) \
			my_mlx_pixel_get(&d->text[WEST], d->texX, d->texY));
	}
}

void calc_wall_pixel(t_data *d) // Calculate the height of the wall.
{
	// The value of screenHeight will make the walls look like cubes
    //Calculate height of line to draw on screen
	d->lineHeight = (int)(screenHeight / d->perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	d->drawStart = -d->lineHeight / 2 + screenHeight / 2;

	if (d->drawStart < 0)
		d->drawStart = 0; // if these points lie outside the screen

	d->drawEnd = d->lineHeight / 2 + screenHeight / 2;

	if (d->drawEnd >= screenHeight)
		d->drawEnd = screenHeight - 1; // if these points lie outside the screen

	// calculate value of wallX
	// where exactly the wall was hit
	// This is required to know which x-coordinate of the texture we have to use.
	if (d->side == '0')
		d->map->wallX = d->posY + d->perpWallDist * d->rayDirY;
	else
		d->map->wallX = d->posX + d->perpWallDist * d->rayDirX;
	d->map->wallX -= floor((d->map->wallX));

	//x coordinate on the texture
    d->texX = (int)(d->map->wallX * (double)texWidth); 
	if (d->side == '0' && d->rayDirX > 0) 
		d->texX = texWidth - d->texX - 1;
	if (d->side == '1' && d->rayDirY < 0) 
		d->texX = texWidth - d->texX - 1;
}

void check_side(t_data *d)
{
    if (d->rayDirX < 0) 
    {
        d->stepX = -1; 
        d->sideDistX = (d->posX - d->mapX) * d->deltaDistX; // Distance to the next x or y-side
    }
    else
    {
        d->stepX = 1;
        d->sideDistX = (d->mapX + 1.0 - d->posX) * d->deltaDistX; // Distance to the next x or y-side
    }
    if (d->rayDirY < 0)
    {
        d->stepY = -1;
        d->sideDistY = (d->posY - d->mapY) * d->deltaDistY; // Distance to the next x or y-side
    }
    else
    {
        d->stepY = 1;
        d->sideDistY = (d->mapY + 1.0 - d->posY) * d->deltaDistY; // Distance to the next x or y-side
    }
}

void calculations(t_data *d) // Calculate the ray position and direction.
{
    d->cameraX = 2 * (double)d->x / (double)screenWidth - 1; //d->-coordinate in camera space
    d->rayDirX = d->dirX + d->planeX * d->cameraX; // Ray direction
    d->rayDirY = d->dirY + d->planeY * d->cameraX; // Ray direction
    d->mapX = (int)d->posX; // Current square on the map
    d->mapY = (int)d->posY; // Current square on the map
    d->deltaDistX = fabs(1.0 / d->rayDirX); // Length of ray from one x or y-side to next x or y-side
    d->deltaDistY = fabs(1.0 / d->rayDirY); // Length of ray from one x or y-side to next x or y-side

    check_side(d); // Check side of the wall
}

void perform_dda(t_data *d) // Perform DDA algorithm.
{
    d->hit = '0'; //was there a wall hit?
	// It's a loop that increments the ray with 1 square every time, until a wall is hit.
	// It always jumps 1 square at once, either in x-direction or in y-direction
    while (d->hit == '0') 
	{
			//jump to next map square, either in x-direction, or in y-direction
		if (d->sideDistX < d->sideDistY)
		{
			d->sideDistX += d->deltaDistX;
			d->mapX += d->stepX;
			d->side = '0';
		}
		else
		{
			d->sideDistY += d->deltaDistY;
			d->mapY += d->stepY;
            d->side = '1';
		}
		//Check if ray has hit a wall, when the ray has hit a wall, the loop ends
		if (d->map->worldMap[d->mapX][d->mapY] > '0')
			d->hit = '1';
	}
	// Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
    if (d->side == '0') 
		d->perpWallDist = (d->sideDistX - d->deltaDistX);
    else
		d->perpWallDist = (d->sideDistY - d->deltaDistY);
}
