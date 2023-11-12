/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:16:56 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/10 10:31:19 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_texture(t_data *d)
{
	d->map->step = 1.0 * TEXTHEIGHT / d->lineheight;
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

void	calc_wall_pixel(t_data *d)
{
	d->lineheight = (int)(SCREENHEIGHT / d->perpwalldist);
	d->drawstart = -d->lineheight / 2 + SCREENHEIGHT / 2;
	if (d->drawstart < 0)
		d->drawstart = 0;
	d->drawend = d->lineheight / 2 + SCREENHEIGHT / 2;
	if (d->drawend >= SCREENHEIGHT)
		d->drawend = SCREENHEIGHT - 1;
	if (d->side == '0')
		d->map->wall_x = d->pos_y + d->perpwalldist * d->raydir_y;
	else
		d->map->wall_x = d->pos_x + d->perpwalldist * d->raydir_x;
	d->map->wall_x -= floor((d->map->wall_x));
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
		d->sidedist_x = (d->pos_x - d->map_x) * d->deltadist_x;
	}
	else
	{
		d->step_x = 1;
		d->sidedist_x = (d->map_x + 1.0 - d->pos_x) * d->deltadist_x;
	}
	if (d->raydir_y < 0)
	{
		d->step_y = -1;
		d->sidedist_y = (d->pos_y - d->map_y) * d->deltadist_y;
	}
	else
	{
		d->step_y = 1;
		d->sidedist_y = (d->map_y + 1.0 - d->pos_y) * d->deltadist_y;
	}
}

void	calculations(t_data *d)
{
	d->camera_x = 2 * (double)d->x / (double)SCREENWIDTH - 1;
	d->raydir_x = d->dir_x + d->plane_x * d->camera_x;
	d->raydir_y = d->dir_y + d->plane_y * d->camera_x;
	d->map_x = (int)d->pos_x;
	d->map_y = (int)d->pos_y;
	d->deltadist_x = fabs(1.0 / d->raydir_x);
	d->deltadist_y = fabs(1.0 / d->raydir_y);
	check_side(d);
}

void	perform_dda(t_data *d)
{
	d->hit = '0';
	while (d->hit == '0')
	{
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
		if (d->map->worldmap[d->map_x][d->map_y] > '0')
			d->hit = '1';
	}
	if (d->side == '0')
		d->perpwalldist = (d->sidedist_x - d->deltadist_x);
	else
		d->perpwalldist = (d->sidedist_y - d->deltadist_y);
}
