/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:31:19 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/30 18:50:58 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void rotate_left(t_data *d)
{
    d->oldDirX = d->dirX;
    d->dirX = d->dirX * cos(d->rotSpeed) - d->dirY * sin(d->rotSpeed);
    d->dirY = d->oldDirX * sin(d->rotSpeed) + d->dirY * cos(d->rotSpeed);
    d->oldPlaneX = d->planeX;
    d->planeX = d->planeX * cos(d->rotSpeed) - d->planeY * sin(d->rotSpeed);
    d->planeY = d->oldPlaneX * sin(d->rotSpeed) + d->planeY * cos(d->rotSpeed);
}

void rotate_right(t_data *d)
{
    d->oldDirX = d->dirX;
    d->dirX = d->dirX * cos(-d->rotSpeed) - d->dirY * sin(-d->rotSpeed);
    d->dirY = d->oldDirX * sin(-d->rotSpeed) + d->dirY * cos(-d->rotSpeed);
    d->oldPlaneX = d->planeX;
    d->planeX = d->planeX * cos(-d->rotSpeed) - d->planeY * sin(-d->rotSpeed);
    d->planeY = d->oldPlaneX * sin(-d->rotSpeed) + d->planeY * cos(-d->rotSpeed);
}