/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/27 15:26:42 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int keyboard_hook(int keycode, t_mlx *m)
{
    if (keycode == ESC)
        mlx_exit(m);
    else if (keycode == S)
    {
        move_backward(m);
        /* if(worldMap[(int)(m->data->posX - m->data->dirX * m->data->moveSpeed)][(int)m->data->posY] == 0)
			m->data->posX -= m->data->dirX * m->data->moveSpeed;
		if(worldMap[(int)m->data->posX][(int)(m->data->posY - m->data->dirY * m->data->moveSpeed)] == 0)
			m->data->posY -= m->data->dirY * m->data->moveSpeed; */
    }
    else if (keycode == W)
	{
        move_forward(m);
		/* if(worldMap[(int)(m->data->posX + m->data->dirX * m->data->moveSpeed)][(int)m->data->posY] == 0)
			m->data->posX += m->data->dirX * m->data->moveSpeed;
		if(worldMap[(int)m->data->posX][(int)(m->data->posY + m->data->dirY * m->data->moveSpeed)] == 0)
			m->data->posY += m->data->dirY * m->data->moveSpeed; */
	}    
    else if (keycode == A)
	{
        move_left(m);
        /* if(worldMap[(int)(m->data->posX - m->data->dirY * m->data->moveSpeed)][(int)m->data->posY] == 0)
		    m->data->posX -= m->data->planeX * m->data->moveSpeed;
        if(worldMap[(int)(m->data->posX)][(int)(m->data->posY - m->data->dirY * m->data->moveSpeed)] == 0)
            m->data->posY -= m->data->planeY * m->data->moveSpeed; */
	}   
    else if (keycode == D)
	{
        move_right(m);
        /* if(worldMap[(int)(m->data->posX + m->data->dirY * m->data->moveSpeed)][(int)m->data->posY] == 0)
		    m->data->posX += m->data->planeX * m->data->moveSpeed;
        if(worldMap[(int)(m->data->posX)][(int)(m->data->posY + m->data->dirY * m->data->moveSpeed)] == 0)
            m->data->posY += m->data->planeY * m->data->moveSpeed; */
	}
    else if (keycode == LEFT)
    {
        rotate_left(m);
        /* m->data->oldDirX = m->data->dirX;
        m->data->dirX = m->data->dirX * cos(m->data->rotSpeed) - m->data->dirY * sin(m->data->rotSpeed);
        m->data->dirY = m->data->oldDirX * sin(m->data->rotSpeed) + m->data->dirY * cos(m->data->rotSpeed);
        m->data->oldPlaneX = m->data->planeX;
        m->data->planeX = m->data->planeX * cos(m->data->rotSpeed) - m->data->planeY * sin(m->data->rotSpeed);
        m->data->planeY = m->data->oldPlaneX * sin(m->data->rotSpeed) + m->data->planeY * cos(m->data->rotSpeed); */
    }
    else if (keycode == RIGHT)
    {
        rotate_right(m);
        /* m->data->oldDirX = m->data->dirX;
        m->data->dirX = m->data->dirX * cos(-m->data->rotSpeed) - m->data->dirY * sin(-m->data->rotSpeed);
        m->data->dirY = m->data->oldDirX * sin(-m->data->rotSpeed) + m->data->dirY * cos(-m->data->rotSpeed);
        m->data->oldPlaneX = m->data->planeX;
        m->data->planeX = m->data->planeX * cos(-m->data->rotSpeed) - m->data->planeY * sin(-m->data->rotSpeed);
        m->data->planeY = m->data->oldPlaneX * sin(-m->data->rotSpeed) + m->data->planeY * cos(-m->data->rotSpeed); */
    }

    return (0);
}

int	hook_events(t_mlx *m)
{
	mlx_hook(m->mlx_win, 17, 0, (void *)mlx_exit, m);
	mlx_key_hook(m->mlx_win, &keyboard_hook, m);
	return (0);
}
