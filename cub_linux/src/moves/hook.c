/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/29 14:14:32 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int keyboard_hook(int keycode, t_mlx *m)
{
    if (keycode == XK_Escape)
        mlx_exit(m);
    if (keycode == XK_S || keycode == XK_s)
        move_backward(m);
    else if (keycode == XK_W || keycode == XK_w)
        move_forward(m);    
    else if (keycode == XK_A || keycode == XK_a)
        move_left(m);   
    else if (keycode == XK_D || keycode == XK_d)
        move_right(m);
    else if (keycode == XK_Left)
        rotate_left(m);
    else if (keycode == XK_Right)
        rotate_right(m);

    return (0);
}

int	hook_events(t_mlx *m)
{
	mlx_hook(m->mlx_win, 17, 0, (void *)mlx_exit, m);
	// mlx_key_hook(m->mlx_win, &keyboard_hook, m);
    //mlx_hook(m->mlx_win, 2, 1L << 0, &keyboard_hook, &m);
	return (0);
}
