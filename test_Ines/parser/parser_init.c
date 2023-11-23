/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inesalves <inesalves@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:40:19 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/23 21:22:24 by inesalves        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/**
 * @brief loops until every value is saved
 * @param test -> for gnl
 * @param map -> struct of map
 * @param fd -> file descriptor
 * @return int 
 */
int	check_text(char *test, t_map *map, int fd)
{
	while (!map->e_texture || !map->w_texture || !map->s_texture \
	|| !map->n_texture || !map->color_c || !map->color_f)
	{
		test = get_next_line(fd);
		if (!test)
		{
			printf("Error!\nMissing Values\n");
			return (1);
		}
		test = ft_strtrim(test, " ");
		test = ft_strtrim(test, "\t");
		if (save_value(test, map))
		{
			free(test);
			return (1);
		}
		free(test);
	}
	return (0);
}

char	*get_to_map(char *test, int fd)
{
	int	i;

	i = 0;
	if (test[i] == ' ' || test[i] == '\t' || test[i] == '\n')
	{
		if (test[0] == '\n')
			free_str(&test);
		else
		{
			while (test[i] == ' ' || test[i] == '\t')
				i++;
			if (i == (int)ft_strlen(test) - 1 && test[i - 1] == '\n')
				free_str(&test);
			else if (i == (int)ft_strlen(test))
				free_str(&test);
		}
	}
	if (!test)
	{
		test = get_next_line(fd);
		if (!test)
			return (NULL);
		get_to_map(test, fd);
	}
	return (test);
}

/**
 * @brief main function
 * @param fd -> file descriptor
 * @param map -> map struct
 * @return int 
 */
int	parse_gnl(int fd, t_map *map)
{
	char	*test;

	test = get_next_line(fd);
	if (!test)
	{
		printf("Error!\nFile Empty\n");
		return (1);
	}
	if (save_value(test, map))
	{
		free(test);
		return (1);
	}
	if (check_text(test, map, fd))
		return (1);
	test = get_next_line(fd);
	if (!get_to_map(test, fd))
	{
		printf("Error!\nMap: No map!\n");
		return (1);
	}
	if (start_map(test, fd, map))
		return (1);
	return (0);
}

int	start_parser(char *argv[])
{
	int		fd;
	t_map	*map;

	fd = open(argv[1], O_RDWR);
	map = (t_map *)malloc(sizeof(t_map));
	if (parse_gnl(fd, map))
	{
		free_map(map);
		return (1);
	}
	//free_map(map);
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	if (start_parser(argv))
		return (1);
	return (0);
}
