/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inesalves <inesalves@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:48:23 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/25 22:57:21 by inesalves        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/**
 * @brief frees a string of strings
 * @param map -> struct
 */
void	free_map_strings(t_map *map)
{
	int	i;

	i = 0;
	while (map->worldmap[i] != 0)
	{
		free(map->worldmap[i]);
		i++;
	}
	free(map->worldmap);
}

/**
 * @brief free all map
 * @param map 
 */
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

/**
 * @brief creates the map of string
 * @param test -> gnl string
 * @param fd -> file descriptor
 * @return char* -> map as string
 */
char	*cleaning_func_part2(char *test, int fd)
{
	char	*aux;
	char	*map_test;

	map_test = ft_strdup(test);
	while (test)
	{
		free(test);
		test = NULL;
		test = get_next_line(fd);
		if (test)
		{
			aux = ft_strjoin(map_test, test);
			free(map_test);
			map_test = NULL;
			map_test = ft_strdup(aux);
			free(aux);
			aux = NULL;
		}
	}
	return (map_test);
}

/**
 * @brief clears newlines of the map string
 * @param map_test 
 * @return char* 
 */
char	*cleaning_func_part3(char *map_test)
{
	char	*aux;

	aux = ft_strtrim(map_test, "\n");
	free(map_test);
	map_test = NULL;
	map_test = ft_strdup(aux);
	free(aux);
	aux = NULL;
	return (map_test);
}

int	final_check_player(int a)
{
	if (a == 0 || a > 1)
	{
		if (a == 0)
			printf("Error!\nMap: There is no player\n");
		else
			printf("Error!\nMap: More than one player\n");
		return (1);
	}
	return (0);
}
