/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inesalves <inesalves@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:21:42 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/23 21:21:00 by inesalves        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			printf("%c\n", map_test[i]);
			printf("Error!\nMap: Character not valid\n");
			return (1);
		}
		if (valid_characters(map_test[i], 1))
			a++;
		i++;
	}
	if (a == 0 || a > 1)
	{
		if (a == 0)
			printf("Map: There is no spot for the player\n");
		else
			printf("Map: More than one player\n");
		return (1);
	}
	return (0);
}

char	**build_map(char *map_test, int lines, int max_length)
{
	char	**map;
	int		i;
	int		j;
	char	*test;

	i = 0;
	map = malloc(sizeof(char *) * (lines + 1));
	while (i < lines)
	{
		map[i] = malloc(sizeof(char) * (max_length + 1));
		i++;
	}
	i = 0;
	j = 0;
	while (i < lines)
	{
		test = copy_map(map_test, &j, max_length);
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
	map->worldmap = build_map(map_test, s_map.lines, s_map.max_length);
	free(map_test);
	if (floodfill(map->worldmap, s_map))
		return (1);
	int i = 0;
    while (map->worldmap[i] != 0)
    {
        printf("%d, %s\n", i, map->worldmap[i]);
        i++;
    }
	return (0);
}

int	start_map(char *test, int fd, t_map *map)
{
	char	*map_test;

	map_test = ft_strdup(test);
	while (test)
	{
		free(test);
		test = NULL;
		test = get_next_line(fd);
		map_test = ft_strjoin(map_test, test);
	}
	ft_strtrim(map_test, "\n");
	if (parse_map(map_test, map))
		return (1);
	return (0);
}

/* int i = 0;
    while (map->worldmap[i] != 0)
    {
        printf("%d, %s\n", i, map->worldmap[i]);
        i++;
    }*/