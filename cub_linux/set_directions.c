/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:36:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/28 19:15:07 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void directions(t_data *data, char x)
{
    data->pos_x = ?;
    data->pos_y = ?;

    if (x == 'N')
    {
		data->plane_x = 0;
		data->plane_y = 0.66;
        data->dir_x = -1;
		data->dir_y = 0;
    }
    else if (x == 'S')
    {
		data->plane_x = 0;
		data->plane_y = -0.66;
        data->dir_x = 1;
		data->dir_y = 0;
    }
    else if (x == 'W')
    {
		data->plane_x = -0.66;
		data->plane_y = 0;
        data->dir_x = 0;
		data->dir_y = -1;
    }
    else if (x == 'E')
    {
		data->plane_x = 0.66;
		data->plane_y = 0;
        data->dir_x = 0;
		data->dir_y = 1;
    }
}
