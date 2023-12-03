/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/12/03 01:33:18 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void update_moves(t_data *data, double rot)
{
    double olddir_x;
    double oldplane_x;
    double margin;

    margin = 0.1;
    olddir_x = data->dir_x;
    data->dir_x = data->dir_x * cos(rot) - data->dir_y * sin(rot);
    data->dir_y = olddir_x * sin(rot) + data->dir_y * cos(rot);
    oldplane_x = data->plane_x;
    data->plane_x = data->plane_x * cos(rot) - data->plane_y * sin(rot);
    data->plane_y = oldplane_x * sin(rot) + data->plane_y * cos(rot);
    if (!ft_strchr("1", data->map->worldmap[(int)(data->pos_x + \
    data->dir_x * data->dey)][(int)(data->pos_y)]))
        data->pos_x += (data->dir_x * data->dey) * (1.0 - margin);
    if (!ft_strchr("1", data->map->worldmap[(int)(data->pos_x)]\
    [(int)(data->pos_y + data->dir_y * data->dey)]))
        data->pos_y += (data->dir_y * data->dey) * (1.0 - margin);
    if (!ft_strchr("1", data->map->worldmap[(int)(data->pos_x + \
    data->plane_x * data->dex)][(int)data->pos_y]))
        data->pos_x += (data->plane_x * data->dex) * (1.0 - margin);
    if (!ft_strchr("1", data->map->worldmap[(int)data->pos_x][(int)\
    (data->pos_y + data->plane_y * data->dex)]))
        data->pos_y += (data->plane_y * data->dex) * (1.0 - margin);
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
        m->data->rot = 0.03;
    if (keycode == RIGHT)
        m->data->rot = -0.03;
    return (0);
}

int keyboard_keyrelease(int keycode, t_mlx *m)
{
    if (keycode == W)
        m->data->dey = 0;
    if (keycode == S)
        m->data->dey = 0;
    if (keycode == A)
        m->data->dex = 0;
    if (keycode == D)
        m->data->dex = 0;
    if (keycode == LEFT)
        m->data->rot = 0;
    if (keycode == RIGHT)
        m->data->rot = 0;
    return (0);
}
