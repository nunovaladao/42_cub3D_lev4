/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inesalves <inesalves@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:48:23 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/23 21:02:51 by inesalves        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map_strings(t_map *map)
{
	int	i;

	i = 0;
	while (map->worldmap != 0)
	{
		free(map->worldmap[i]);
		i++;
	}
	free(map->worldmap);
}

void	free_map(t_map *map)
{
	if (map->e_texture)
		free (map->e_texture);
	if (map->color_c)
		free(map->color_c);
	if (map->color_f)
		free(map->color_f);
	if (map->w_texture)
		free(map->w_texture);
	if (map->s_texture)
		free(map->s_texture);
	if (map->n_texture)
		free(map->n_texture);
	if (map->worldmap)
		free_map_strings(map);
	free(map);
}

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}
