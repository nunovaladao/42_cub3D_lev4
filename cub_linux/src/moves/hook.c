/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/31 21:07:15 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int keyboard_hook(int keycode, t_mlx *m)
{
    if (keycode == XK_Escape)
        mlx_exit(m);
    if (keycode == XK_S || keycode == XK_s)
        m->data->flag_down = 1;
    if (keycode == XK_W || keycode == XK_w)
        m->data->flag_up = 1;   
    if (keycode == XK_A || keycode == XK_a)
        m->data->flag_left = 1;   
    if (keycode == XK_D || keycode == XK_d)
        m->data->flag_right = 1;
    if (keycode == XK_Left)
        m->data->flag_rot_left = 1;
    if (keycode == XK_Right)
        m->data->flag_rot_right = 1;

    return (0);
}

int keyboard_keyrelease(int keycode, t_mlx *m)
{
    if (keycode == XK_S || keycode == XK_s)
        m->data->flag_down = 0;
    if (keycode == XK_W || keycode == XK_w)
        m->data->flag_up = 0;   
    if (keycode == XK_A || keycode == XK_a)
        m->data->flag_left = 0;   
    if (keycode == XK_D || keycode == XK_d)
        m->data->flag_right = 0;
    if (keycode == XK_Left)
        m->data->flag_rot_left = 0;
    if (keycode == XK_Right)
        m->data->flag_rot_right = 0;

    return (0);
}
