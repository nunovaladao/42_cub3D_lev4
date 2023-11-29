/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:36:13 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/29 11:56:21 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	position_player(t_data *data)
{
	char	pos;
	int		i;
	int		j;

	i = -1;
	while (data->map->worldmap[++i] != 0)
	{
		j = 0;
		while (data->map->worldmap[i][j] != '\0')
		{
			if (data->map->worldmap[i][j] == 'N' || \
			data->map->worldmap[i][j] == 'S' || \
			data->map->worldmap[i][j] == 'W' || \
			data->map->worldmap[i][j] == 'E')
			{
				pos = data->map->worldmap[i][j];
				data->map->worldmap[i][j] = '0';
				data->pos_x = i + 0.5;
				data->pos_y = j + 0.5;
				break ;
			}
			j++;
		}
	}
	return (pos);
}

void	check_north_sul(t_data *data, int pos)
{
	if (pos == 'N')
	{
		data->plane_x = 0;
		data->plane_y = 0.66;
		data->dir_x = -1;
		data->dir_y = 0;
	}
	else if (pos == 'S')
	{
		data->plane_x = 0;
		data->plane_y = -0.66;
		data->dir_x = 1;
		data->dir_y = 0;
	}
}

void	check_west_east(t_data *data, int pos)
{
	if (pos == 'W')
	{
		data->plane_x = -0.66;
		data->plane_y = 0;
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (pos == 'E')
	{
		data->plane_x = 0.66;
		data->plane_y = 0;
		data->dir_x = 0;
		data->dir_y = 1;
	}
}

void	directions(t_data *data)
{
	char	pos;

	pos = position_player(data);
	check_north_sul(data, pos);
	check_west_east(data, pos);
}
