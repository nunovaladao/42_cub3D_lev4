/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:22:54 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/28 13:08:30 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_mlx(t_mlx *m, t_data *data)
{
    m->mlx = NULL;
    m->mlx_win = NULL;
    m->data = data;
}

void init_data(t_data *data, t_mlx *m, struct s_map *map)
{
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
    data->moveSpeed = 0.0;
    data->rotSpeed = 0.0;
    data->oldDirX = 0.0;
    data->oldPlaneX = 0.0;
    
    data->mlx = m;
    data->map = map;
}

void init_map(t_map *map, t_data *data)
{
    map->wallX = 0.0;
    map->fd = 0;
    map->nr_rows = 0;
    map->worldMap = NULL;
    map->data = data;
}

void init_all(t_mlx *m, t_data *data, t_map *map)
{
    init_mlx(m, data);
    init_data(data, m, map);
    init_map(map, data);
}