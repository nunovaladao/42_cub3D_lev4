/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:29:31 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/30 18:52:51 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void move_forward(t_data *d)
{
    if(d->map->worldMap[(int)(d->posX + d->dirX * d->moveSpeed)][(int)d->posY] == '0')
        d->posX += d->dirX * d->moveSpeed;
    if(d->map->worldMap[(int)d->posX][(int)(d->posY + d->dirY * d->moveSpeed)] == '0')
        d->posY += d->dirY * d->moveSpeed;
}

void move_backward(t_data *d)
{
    if(d->map->worldMap[(int)(d->posX - d->dirX * d->moveSpeed)][(int)d->posY] == '0')
        d->posX -= d->dirX * d->moveSpeed;
    if(d->map->worldMap[(int)d->posX][(int)(d->posY - d->dirY * d->moveSpeed)] == '0')
        d->posY -= d->dirY * d->moveSpeed;
}

void move_left(t_data *d)
{
    if(d->map->worldMap[(int)(d->posX - d->dirY * d->moveSpeed)][(int)d->posY] == '0')
        d->posX -= d->planeX * d->moveSpeed;
    if(d->map->worldMap[(int)(d->posX)][(int)(d->posY - d->dirY * d->moveSpeed)] == '0')
        d->posY -= d->planeY * d->moveSpeed;
}

void move_right(t_data *d)
{
    if(d->map->worldMap[(int)(d->posX + d->dirY * d->moveSpeed)][(int)d->posY] == '0')
        d->posX += d->planeX * d->moveSpeed;
    if(d->map->worldMap[(int)(d->posX)][(int)(d->posY + d->dirY * d->moveSpeed)] == '0')
        d->posY += d->planeY * d->moveSpeed;
}
