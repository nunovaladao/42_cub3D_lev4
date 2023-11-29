/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:21:42 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/29 16:01:25 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	valid_characters(char c, int i)
{
	if (i == 0)
	{
		if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'E' && \
		c != 'W' && c != 'S' && c != '\n')
			return (1);
		return (0);
	}
	else
	{
		if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			return (1);
		return (0);
	}
	return (0);
}

int	check_characters(char *map_test)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (map_test[i] != '\0')
	{
		if (valid_characters(map_test[i], 0))
		{
			printf("Error!\nMap: Character not valid\n");
			return (1);
		}
		if (valid_characters(map_test[i], 1))
			a++;
		i++;
	}
	if (final_check_player(a))
		return (1);
	return (0);
}

char	**build_map(char *map_test, t_size_map	*s_map)
{
	char	**map;
	int		i;
	int		j;
	char	*test;

	i = 0;
	map = malloc(sizeof(char *) * (s_map->lines + 1));
	i = 0;
	j = 0;
	while (i < s_map->lines)
	{
		test = copy_map(map_test, &j, s_map->max_length);
		if (!test)
		{
			s_map->max_length = -1;
			break ;
		}
		map[i] = ft_strdup(test);
		free(test);
		test = NULL;
		i++;
	}
	map[i] = 0;
	return (map);
}

int	parse_map(char *map_test, t_map *map)
{
	t_size_map	s_map;

	if (check_characters(map_test))
		return (1);
	s_map.max_length = max_length_line(map_test);
	s_map.lines = number_of_lines(map_test);
	map->worldmap = build_map(map_test, &s_map);
	if (s_map.max_length == -1)
	{
		printf("Error!\nMap: Empty line!\n");
		return (1);
	}
	if (floodfill(map->worldmap, s_map))
		return (1);
	return (0);
}

int	start_map(char *test, t_map *map)
{
	char	*map_test;
	int		i;

	i = 0;
	map_test = cleaning_func_part2(test, map);
	map_test = cleaning_func_part3(map_test);
	if (parse_map(map_test, map))
	{
		free(map_test);
		map_test = NULL;
		return (1);
	}
	free(map_test);
	map_test = NULL;
	return (0);
}
