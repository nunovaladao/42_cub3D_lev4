/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/31 20:49:08 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int keyboard_hook(int keycode, t_mlx *m)
{
    if (keycode == 53)
        mlx_exit(m);
    if (keycode == 13)
        m->data->flag_up = 1;
    if (keycode == 1)
        m->data->flag_down = 1;
    if (keycode == 2)
        m->data->flag_right = 1;
    if (keycode == 0)
        m->data->flag_left = 1;
    if (keycode == 123)
        m->data->flag_rot_left = 1;
    if (keycode == 124)
        m->data->flag_rot_right = 1;
    return (0);
}

int keyboard_keyrelease(int keycode, t_mlx *m)
{
    if (keycode == 13)
        m->data->flag_up = 0;
    if (keycode == 1)
        m->data->flag_down = 0;
    if (keycode == 0)
        m->data->flag_left = 0;
    if (keycode == 2)
        m->data->flag_right = 0;
    if (keycode == 123)
        m->data->flag_rot_left = 0;
    if (keycode == 124)
        m->data->flag_rot_right = 0;
    return (0);
}

int	hook_events(t_mlx *m)
{
	mlx_hook(m->mlx_win, 17, 0, (void *)mlx_exit, m);
    //mlx_hook(m->mlx_win, 2, 1L << 0, &keyboard_hook, &m);
	//mlx_hook(m->mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	//mlx_key_hook(m->mlx_win, &keyboard_hook, m);
	return (0);
}
