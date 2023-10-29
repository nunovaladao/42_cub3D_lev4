/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:31:19 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/27 13:31:40 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void rotate_left(t_mlx *m)
{
    m->data->oldDirX = m->data->dirX;
    m->data->dirX = m->data->dirX * cos(m->data->rotSpeed) - m->data->dirY * sin(m->data->rotSpeed);
    m->data->dirY = m->data->oldDirX * sin(m->data->rotSpeed) + m->data->dirY * cos(m->data->rotSpeed);
    m->data->oldPlaneX = m->data->planeX;
    m->data->planeX = m->data->planeX * cos(m->data->rotSpeed) - m->data->planeY * sin(m->data->rotSpeed);
    m->data->planeY = m->data->oldPlaneX * sin(m->data->rotSpeed) + m->data->planeY * cos(m->data->rotSpeed);
}

void rotate_right(t_mlx *m)
{
    m->data->oldDirX = m->data->dirX;
    m->data->dirX = m->data->dirX * cos(-m->data->rotSpeed) - m->data->dirY * sin(-m->data->rotSpeed);
    m->data->dirY = m->data->oldDirX * sin(-m->data->rotSpeed) + m->data->dirY * cos(-m->data->rotSpeed);
    m->data->oldPlaneX = m->data->planeX;
    m->data->planeX = m->data->planeX * cos(-m->data->rotSpeed) - m->data->planeY * sin(-m->data->rotSpeed);
    m->data->planeY = m->data->oldPlaneX * sin(-m->data->rotSpeed) + m->data->planeY * cos(-m->data->rotSpeed);
}