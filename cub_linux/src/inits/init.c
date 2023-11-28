/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:22:54 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/28 16:11:43 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_mlx(t_mlx *m, t_data *data)
{
	m->mlx = NULL;
	m->mlx_win = NULL;
	m->data = data;
}

void	init_other_data(t_data *data, t_mlx *m, struct s_map *map)
{
	data->y = 0;
	data->tex_x = 0;
	data->tex_y = 0;
	data->dex = 0.0;
	data->dey = 0.0;
	data->rot = 0.0;
	data->mlx = m;
	data->map = map;
	data->text = malloc(4 * sizeof(t_texture));
	if (!data->text)
		exit(EXIT_FAILURE);
}

void	init_data(t_data *data, t_mlx *m, struct s_map *map)
{
	data->x = 0;
	data->pos_x = 22;
	data->pos_y = 12;
	data->dir_x = -1;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.66;
	data->camera_x = 0.0;
	data->raydir_x = 0.0;
	data->raydir_y = 0.0;
	data->map_x = 0;
	data->map_y = 0;
	data->sidedist_x = 0.0;
	data->sidedist_y = 0.0;
	data->deltadist_x = 0.0;
	data->deltadist_y = 0.0;
	data->perpwalldist = 0.0;
	data->step_x = 0;
	data->step_y = 0;
	data->hit = 0;
	data->side = 0;
	data->lineheight = 0;
	data->drawstart = 0;
	data->drawend = 0;
	init_other_data(data, m, map);
}

void	init_map(t_map *map, t_data *data)
{
	map->wall_x = 0.0;
	map->fd = 0;
	map->worldmap = 0;
	map->map_file = NULL;
	map->n_texture = NULL;
	map->s_texture = NULL;
	map->w_texture = NULL;
	map->e_texture = NULL;
	map->data = data;
}

void	init_all(t_mlx *m, t_data *data, t_map *map)
{
	init_mlx(m, data);
	init_data(data, m, map);
	init_map(map, data);
}
