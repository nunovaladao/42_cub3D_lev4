/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:39:38 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/02 11:34:30 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void move_camera(t_data *d)
{
    if (d->flag_up == 1)
        move_forward(d->mlx);
    if (d->flag_down == 1)
        move_backward(d->mlx);
    if (d->flag_left == 1)
        move_left(d->mlx);
    if (d->flag_right == 1)
        move_right(d->mlx);
    if (d->flag_rot_left == 1)
        rotate_left(d->mlx);
    if (d->flag_rot_right == 1)
        rotate_right(d->mlx);
}