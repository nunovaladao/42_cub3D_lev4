/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:54:18 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/25 18:47:40 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	max_length_line(char *map_test)
{
	int	i;
	int	a;
	int	max_length;

	i = 0;
	a = 0;
	max_length = 0;
	while (map_test[i] != '\0')
	{
		if (map_test[i] == '\n')
		{
			if (max_length < (i - a))
				max_length = i - a;
			a = i + 1;
		}
		i++;
	}
	if (max_length < i - a)
		max_length = i - a;
	return (max_length);
}

int	number_of_lines(char *map_test)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (map_test[i] != '\0')
	{
		if (map_test[i] == '\n')
			line++;
		i++;
	}
	return (line + 1);
}

char	*copy_map(char *map_test, int *j, int max_length)
{
	int		i;
	char	*new_map;

	i = 0;
	new_map = malloc(sizeof(char) * (max_length + 1));
	while (map_test[(*j)] != '\0' && map_test[(*j)] != '\n')
	{
		new_map[i] = map_test[(*j)];
		i++;
		(*j)++;
	}
	while (i < max_length)
	{
		new_map[i] = ' ';
		i++;
	}
	(*j)++;
	new_map[i] = '\0';
	return (new_map);
}
