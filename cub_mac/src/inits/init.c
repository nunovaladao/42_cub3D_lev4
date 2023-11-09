/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:22:54 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/08 17:22:36 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_mlx(t_mlx *m, t_data *data)
{
    m->mlx = NULL;
    m->mlx_win = NULL;
    m->data = data;
}
void init_other_data(t_data *data, t_mlx *m, struct s_map *map)
{
    data->y = 0;
    data->texX = 0;
    data->texY = 0;
    data->dex = 0.0;
    data->dey = 0.0;
    data->rot = 0.0;
    data->totalrots = 0.0;
    data->mlx = m;
    data->map = map;
    data->text = malloc(4 * sizeof(t_texture));
    if (!data->text)
        exit(EXIT_FAILURE);
}

void init_data(t_data *data, t_mlx *m, struct s_map *map)
{
    data->x = 0;
    data->posX = 22;
    data->posY = 12;
    data->dirX = -1;
    data->dirY = 0.0;
    data->planeX = 0.0;
    data->planeY = 0.66;
    data->cameraX = 0.0;
    data->rayDirX = 0.0;
    data->rayDirY = 0.0;
    data->mapX = 0;
    data->mapY = 0;
    data->sideDistX = 0.0;
    data->sideDistY = 0.0;
    data->deltaDistX = 0.0;
    data->deltaDistY = 0.0;
    data->perpWallDist = 0.0;
    data->stepX = 0;
    data->stepY = 0;
    data->hit = 0;
    data->side = 0;
    data->lineHeight = 0;
    data->drawStart = 0;
    data->drawEnd = 0;
    init_other_data(data, m, map);
}

void init_map(t_map *map, t_data *data)
{
    map->wallX = 0.0;
    map->fd = 0;
    map->nr_rows = 0;
    map->worldMap = NULL;
    map->map_file = NULL;
    map->line = NULL;
    map->n_texture = "textures/N1.xpm";
    map->s_texture = "textures/S1.xpm";
    map->w_texture = "textures/W1.xpm";
    map->e_texture = "textures/E1.xpm";
    map->floor_texture = NULL;
    map->ceiling_texture = NULL;
    map->data = data;
}

void init_all(t_mlx *m, t_data *data, t_map *map)
{
    init_mlx(m, data);
    init_data(data, m, map);
    init_map(map, data);
}