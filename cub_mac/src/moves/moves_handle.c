/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/06 11:52:19 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	update_moves(t_data *data, double rot)
{
	double	olddirX;
	double	oldplanex;

	olddirX = data->dirX;
	data->totalrots += rot;
	data->dirX = data->dirX * cos(rot) - data->dirY * sin(rot);
	data->dirY = olddirX * sin(rot) + data->dirY * cos(rot);
	oldplanex = data->planeX;
	data->planeX = data->planeX * cos(rot) - data->planeY * sin(rot);
	data->planeY = oldplanex * sin(rot) + data->planeY * cos(rot);
	if (!ft_strchr("1", data->map->worldMap[(int)(data->posX + \
			data->dirX * data->dey)][(int)(data->posY)]))
		data->posX += data->dirX * data->dey;
	if (!ft_strchr("1", data->map->worldMap[(int)(data->posX)] \
			[(int)(data->posY + data->dirY * data->dey)]))
		data->posY += data->dirY * data->dey;
	if (!ft_strchr("1", data->map->worldMap[(int)(data->posX + \
			data->planeX * data->dex)][(int)data->posY]))
		data->posX += data->planeX * data->dex;
	if (!ft_strchr("1", data->map->worldMap[(int)data->posX] \
			[(int)(data->posY + data->planeY * data->dex)]))
		data->posY += data->planeY * data->dex;
}

int keyboard_hook(int keycode, t_mlx *m)
{
    if (keycode == ESC)
        mlx_exit(m);
    if (keycode == W)
        m->data->dey = 0.05;
    if (keycode == S)
        m->data->dey = -0.05;
    if (keycode == A)
        m->data->dex = -0.05;
    if (keycode == D)
        m->data->dex = 0.05;
    if (keycode == LEFT)
        m->data->rot = 0.05;
    if (keycode == RIGHT)
        m->data->rot = -0.05;
    return (0);
}

int keyboard_keyrelease(int keycode, t_mlx *m)
{
    if (keycode == 13)
        m->data->dey = 0;
    if (keycode == 1)
        m->data->dey = 0;
    if (keycode == 2)
        m->data->dex = 0;
    if (keycode == 0)
        m->data->dex = 0;
    if (keycode == 123)
        m->data->rot = 0;
    if (keycode == 124)
        m->data->rot = 0;
    return (0);
}
