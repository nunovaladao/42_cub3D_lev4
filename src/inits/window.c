/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:58:07 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/02 14:13:59 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void open_window(t_mlx *m)
{
    m->mlx = mlx_init();
	m->mlx_win = mlx_new_window(m->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	m->img = mlx_new_image(m->mlx, SCREENWIDTH, SCREENHEIGHT);
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length,
								&m->endian);
}