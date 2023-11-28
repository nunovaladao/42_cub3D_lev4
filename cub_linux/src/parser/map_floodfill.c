/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:29:20 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/28 16:58:24 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/**
 * @brief checks invalid characters surrounding 0
 * @param map 
 * @param x ->position
 * @param y -> position
 * @return int -> 0 if ok.
 */
int	check_if_wall(char **map, int x, int y)
{
	if (map[y - 1][x] == ' ' || map[y][x - 1] == ' ')
		return (1);
	else if (map[y + 1][x] == ' ' || map[y][x + 1] == ' ')
		return (1);
	else if (map[y - 1][x] == '\0' || map[y][x - 1] == '\0')
		return (1);
	else if (map[y + 1][x] == '\0' || map[y][x + 1] == '\0')
		return (1);
	return (0);
}

/**
 * @brief inserts and F instead of 0
 * @param map 
 * @param ms 
 * @param x 
 * @param y 
 * @return int 
 */
int	f_fill(char **map, t_size_map ms, int x, int y)
{
	if (x < 0 || y < 0 || x > (ms.max_length - 1) || y > (ms.lines - 1))
		return (0);
	if (map[y][x] == 'F' || map[y][x] != '0')
		return (0);
	if (y == 0 || y == (ms.lines - 1) || x == 0 || x == (ms.max_length - 1))
	{
		printf("Error!\nMap: Unclosed map.\n");
		return (1);
	}
	map[y][x] = 'F';
	if (check_if_wall(map, x, y))
	{
		printf("Error!\nMap: Invalid.\n");
		return (1);
	}
	if (f_fill(map, ms, x - 1, y))
		return (1);
	if (f_fill(map, ms, x + 1, y))
		return (1);
	if (f_fill(map, ms, x, y - 1))
		return (1);
	if (f_fill(map, ms, x, y + 1))
		return (1);
	return (0);
}

/**
 * @brief finds a char in map character
 * @param map 
 * @param x 
 * @param y 
 * @param find -> character to find
 * @return int 
 */
int	find_char(char **map, int *x, int *y, char find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != 0)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == find)
			{
				*x = i;
				*y = j;
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

/**
 * @brief checks that player isn't outside the map
 * @param map 
 * @param ms 
 * @param x 
 * @param y 
 * @return int 
 */
int	final_check_character(char **map, t_size_map ms, int x, int y)
{
	x = 0;
	y = 0;
	if (find_char(map, &x, &y, 'N'))
		if (find_char(map, &x, &y, 'S'))
			if (find_char(map, &x, &y, 'W'))
				find_char(map, &x, &y, 'E');
	if (y == 0 || x == 0 || y == (ms.lines - 1) || x == (ms.max_length - 1))
	{
		printf("Map: Player: Invalid map.\n");
		return (1);
	}
	else if (check_if_wall(map, x, y))
	{
		printf("Error!\nMap: Player: Has to be inside the map.\n");
		return (1);
	}
	return (0);
}

int	floodfill(char **map, t_size_map ms)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (!find_char(map, &x, &y, '0'))
	{
		if (f_fill(map, ms, x, y))
			return (1);
	}
	if (final_check_character(map, ms, x, y))
		return (1);
	x = 0;
	y = 0;
	while (!find_char(map, &x, &y, 'F'))
	{
		if (f_fill_part2(map, ms, x, y))
			return (1);
	}
	return (0);
}
