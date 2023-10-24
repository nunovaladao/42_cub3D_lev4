/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:22:54 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/24 11:37:13 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_mlx(t_map *map)
{
    map->x = 200;
    map->y = 100;
    map->wall = "textures/file.xpm";
    map->img_width = 300;
    map->img_height = 64;
    map->tile_size = 32;
    map->map_width = 18;
    map->map_height = 12;
    map->map = (int **)malloc(map->map_height * sizeof(int *));
}