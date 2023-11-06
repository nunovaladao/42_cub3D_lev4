/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:58:07 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/06 15:26:36 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_textures(t_data *d)
{
    d->text[NORTH].img = mlx_xpm_file_to_image(d->mlx->mlx, d->map->n_texture, &d->text[NORTH].t_w, &d->text[NORTH].t_h);
    d->text[NORTH].addr = mlx_get_data_addr(d->text[NORTH].img, &d->text[NORTH].bits_per_pixel, &d->text[NORTH].line_length, &d->text[NORTH].endian);
    d->text[SOUTH].img = mlx_xpm_file_to_image(d->mlx->mlx, d->map->s_texture, &d->text[SOUTH].t_w, &d->text[SOUTH].t_h);
    d->text[SOUTH].addr = mlx_get_data_addr(d->text[SOUTH].img, &d->text[SOUTH].bits_per_pixel, &d->text[SOUTH].line_length, &d->text[SOUTH].endian);
    d->text[WEST].img = mlx_xpm_file_to_image(d->mlx->mlx, d->map->w_texture, &d->text[WEST].t_w, &d->text[WEST].t_h);
    d->text[WEST].addr = mlx_get_data_addr(d->text[WEST].img, &d->text[WEST].bits_per_pixel, &d->text[WEST].line_length, &d->text[WEST].endian);
    d->text[EAST].img = mlx_xpm_file_to_image(d->mlx->mlx, d->map->e_texture, &d->text[EAST].t_w, &d->text[EAST].t_h);
    d->text[EAST].addr = mlx_get_data_addr(d->text[EAST].img, &d->text[EAST].bits_per_pixel, &d->text[EAST].line_length, &d->text[EAST].endian);
}

void open_window(t_mlx *m)
{
    m->mlx = mlx_init();
	m->mlx_win = mlx_new_window(m->mlx, screenWidth, screenHeight, "cub3D");
	m->img = mlx_new_image(m->mlx, screenWidth, screenHeight);
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length,
								&m->endian);
}