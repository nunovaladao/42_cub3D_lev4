/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:01:09 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/29 11:23:42 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_file(char *file, t_map *map)
{
	map->fd = open(file, O_RDONLY);
	if (map->fd == -1)
	{
		printf("Error!\nFile not found...\n");
		return (1);
	}
	return (0);
}

int	check_file_extension_part2(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] != 'b' || file[i - 2] != 'u' || \
	file[i - 3] != 'c' || file[i - 4] != '.')
	{
		printf("Error!\nFile extension not valid...\n");
		return (1);
	}
	return (0);
}

int	check_file_extension(char *file_name)
{
	char	*file;
	int		i;
	int		start;

	i = -1;
	while (file_name[++i] != '\0')
		if (file_name[i] == '/')
			start = i;
	if (i == (int)ft_strlen(file_name))
		start = -1;
	file = ft_substr(file_name, start + 1, ft_strlen(file_name));
	if (ft_strlen(file) < 5)
	{
		printf("Error!\nFile extension not valid...\n");
		return (1);
	}
	i = 0;
	if (check_file_extension_part2(file))
		return (1);
	return (0);
}
