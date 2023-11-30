/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:01:07 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/30 14:47:26 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_string(char *test, int *i)
{
	if (test[0] != ' ' && test[0] != '\t')
	{
		printf("Error!\nTexture: Invalid character\n");
		return (1);
	}
	while ((test[*i] == ' ' || test[*i] == '\t') && test[*i] != '\0')
		(*i)++;
	return (0);
}

int	check_textures_extension(char *new, int fd, int length)
{
	int	i;

	if (fd < 0)
	{
		printf("Error!\nTexture: no path found\n");
		return (1);
	}
	if (new[length] != 'm' || new[length - 1] != 'p' \
	|| new[length - 2] != 'x' || new[length - 3] != '.')
	{
		printf("Error!\nThe textures have to be .xpm\n");
		return (1);
	}
	i = 0;
	while (new[i] != '/' && new[i] != '\0')
		i++;
	if (i == length + 1)
		i = -1;
	if ((length - 4) == i)
	{
		printf("Error!\nThe file .xpm is invalid!\n");
		return (1);
	}
	return (0);
}

/** @brief gets string from test for the textures
* Checks first if there is a path. THen mallocs
* a new string and writes in it
* @returns NULL on error.
* */
char	*get_string(char *test)
{
	int		i;
	int		j;
	char	*new;
	int		fd;

	i = 0;
	if (check_string(test, &i))
		return (NULL);
	j = i + 2;
	while (test[j] != ' ' && test[j] != '\t' \
	&& test[j] != '\n' && test[j] != '\0')
		j++;
	new = ft_substr(test, i, j - i);
	fd = open(new, O_RDONLY);
	if (check_textures_extension(new, fd, (int)ft_strlen(new) - 1))
	{
		free(new);
		if (fd > -1)
			close(fd);
		return (NULL);
	}
	return (new);
}

/** @brief checks which texture to get
* @returns 1 on error, else 0
* */
int	get_textures(char *test, t_map *map)
{
	char	*texture;

	texture = get_string(&test[2]);
	if (!texture)
		return (1);
	if (!ft_strncmp(test, "NO", 2) && !map->n_texture)
		map->n_texture = texture;
	else if (!ft_strncmp(test, "SO", 2) && !map->s_texture)
		map->s_texture = texture;
	else if (!ft_strncmp(test, "WE", 2) && !map->w_texture)
		map->w_texture = texture;
	else if (!ft_strncmp(test, "EA", 2)  && !map->e_texture)
		map->e_texture = texture;
	else
	{
		printf("Error!\nDouble textures\n");
		return (1);
	}
	return (0);
}

/** @brief separates the options between all the options
* @return 1 on error else 0
* */
int	save_value(char *test, t_map *map)
{
	int	i;

	i = 0;
	if (!ft_strncmp(test, "NO", 2) || !ft_strncmp(test, "SO", 2) \
	|| !ft_strncmp(test, "EA", 2) || !ft_strncmp(test, "WE", 2))
		return (get_textures(test, map));
	else if (!ft_strncmp(test, "F", 1) || !ft_strncmp(test, "C", 1))
		return (get_colors(test, map));
	else if (ft_strncmp("\n", test, 1))
	{
		while ((test[i] == ' ' || test[i] == '\t') && test[i] != '\n')
			i++;
		if (i == (int)ft_strlen(test))
			return (0);
		printf("Error!\nTextures and colors incomplete!\n");
		return (1);
	}
	return (0);
}
