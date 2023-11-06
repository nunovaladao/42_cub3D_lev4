/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:45:29 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/06 17:48:58 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int render_next_frame(void *param)
{
	t_data *d = param;

    background(d->mlx);
	d->x = -1;
	while (++d->x < SCREENWIDTH)
    {
		calculations(d);
		perform_dda(d);
		calc_wall_pixel(d);
		draw_texture(d);
	}
    return (0);
}
