/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:22:54 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/03 16:19:57 by nsoares-         ###   ########.fr       */
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
    data->oldDirX = 0.0;
    data->oldPlaneX = 0.0;
    data->texX = 0;
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