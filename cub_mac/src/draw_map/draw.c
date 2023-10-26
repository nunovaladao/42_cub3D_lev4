/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:52:49 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/26 10:16:04 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_floor(t_mlx *m)
{
    int x;
    int y;
    
    x = 0;
    while (x < screenWidth)
    {
        y = screenHeight / 2;
        while (y < screenHeight)
        {
            my_mlx_pixel_put(m, x, y, 0x000000);
            y++;
        }
        x++;
    }
}

void ceiling(t_mlx *m)
{
    int x;
    int y;
    
    x = 0;
    while (x < screenWidth)
    {
        y = 0;
        while (y < screenHeight / 2)
        {
            my_mlx_pixel_put(m, x, y, 0xFFFFFF);
            y++;
        }
        x++;
    }
}

void background(t_mlx *m)
{
    ceiling(m);
    draw_floor(m);
    mlx_put_image_to_window(m->mlx, m->mlx_win, m->img, 0, 0);
}