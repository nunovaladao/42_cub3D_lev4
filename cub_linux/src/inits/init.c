/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:22:54 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/23 10:53:45 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_mlx(t_data *data)
{
    data->x = 200;
    data->y = 100;
    data->wall = "textures/file.xpm";
    data->img_width = 300;
    data->img_height = 64;
    data->tile_size = 32;
    data->map_width = 18;
    data->map_height = 12;
    data->map = (int **)malloc(data->map_height * sizeof(int *));
}