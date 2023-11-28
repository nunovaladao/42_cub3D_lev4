/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:52:49 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/28 16:12:47 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	my_mlx_pixel_get(t_texture *t, int x, int y)
{
	return (*(unsigned int *)((t->addr + (y * t->line_length) + \
		(x * t->bits_per_pixel / 8))));
}

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor(t_mlx *m)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREENWIDTH)
	{
		y = SCREENHEIGHT / 2;
		while (y < SCREENHEIGHT)
		{
			my_mlx_pixel_put(m, x, y, m->data->map->f_color);
			y++;
		}
		x++;
	}
}

void	ceiling(t_mlx *m)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREENWIDTH)
	{
		y = 0;
		while (y < SCREENHEIGHT / 2)
		{
			my_mlx_pixel_put(m, x, y, m->data->map->c_color);
			y++;
		}
		x++;
	}
}

void	background(t_mlx *m)
{
	ceiling(m);
	draw_floor(m);
}
