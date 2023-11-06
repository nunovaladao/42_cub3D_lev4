/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:29:31 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/02 17:21:07 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void move_forward(t_mlx *m)
{
    if(m->data->map->worldMap[(int)(m->data->posX + m->data->dirX * MARGIN)][(int)m->data->posY] == '0')
        m->data->posX += m->data->dirX * m->data->moveSpeed;
    if(m->data->map->worldMap[(int)m->data->posX][(int)(m->data->posY + m->data->dirY * MARGIN)] == '0')
        m->data->posY += m->data->dirY * m->data->moveSpeed;
}

void move_backward(t_mlx *m)
{
    if(m->data->map->worldMap[(int)(m->data->posX - m->data->dirX * MARGIN)][(int)m->data->posY] == '0')
        m->data->posX -= m->data->dirX * m->data->moveSpeed;
    if(m->data->map->worldMap[(int)m->data->posX][(int)(m->data->posY - m->data->dirY * MARGIN)] == '0')
        m->data->posY -= m->data->dirY * m->data->moveSpeed;
}

void move_left(t_mlx *m)
{
    if(m->data->map->worldMap[(int)(m->data->posX - m->data->dirY * MARGIN)][(int)m->data->posY] == '0')
        m->data->posX -= m->data->planeX * m->data->moveSpeed;
    if(m->data->map->worldMap[(int)(m->data->posX)][(int)(m->data->posY - m->data->dirY * MARGIN)] == '0')
        m->data->posY -= m->data->planeY * m->data->moveSpeed;
}

void move_right(t_mlx *m)
{
    if(m->data->map->worldMap[(int)(m->data->posX + m->data->dirY * MARGIN)][(int)m->data->posY] == '0')
        m->data->posX += m->data->planeX * m->data->moveSpeed;
    if(m->data->map->worldMap[(int)(m->data->posX)][(int)(m->data->posY + m->data->dirY * MARGIN)] == '0')
        m->data->posY += m->data->planeY * m->data->moveSpeed;
}
