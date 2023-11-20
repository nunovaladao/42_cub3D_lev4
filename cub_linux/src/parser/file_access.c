/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:01:09 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/20 15:38:08 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\nFile not found...\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	check_file_extension(char *file_name)
{
	int	i;
	int start;
	char *file;

	i = -1;
	while (file_name[++i] != '\0')
		if (file_name[i] == '/')
			start = i;
	file = ft_substr(file_name, start + 1, ft_strlen(file_name));
	if (ft_strlen(file) < 5)
	{
		printf("Error!\nFile extension not valid...\n");
		return (1);
	}
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
