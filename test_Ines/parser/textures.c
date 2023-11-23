/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inesalves <inesalves@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:01:07 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/23 21:08:42 by inesalves        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_string(char *test, int *i)
{
	if (test[0] != ' ' && test[0] != '\t')
	{
		printf("Texture: Invalid character\n");
		return (1);
	}
	while (test[*i] != '.' && test[*i] != '\0')
	{
		if (test[*i] != ' ' && test[*i] != '\t')
		{
			printf("Texture: Invalid character\n");
			return (1);
		}
		(*i)++;
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

	i = 0;
	if (check_string(test, &i))
		return (NULL);
	if (i == (int)ft_strlen(test) || test[i + 1] != '/')
	{
		printf("Texture: no path found\n");
		return (NULL);
	}
	j = i + 2;
	while (test[j] != ' ' && test[j] != '\t' \
	&& test[j] != '\n' && test[j] != '\0')
		j++;
	new = ft_substr(test, i + 2, j - i - 2);
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
	if (!ft_strncmp(test, "NO", 2))
		map->n_texture = texture;
	else if (!ft_strncmp(test, "SO", 2))
		map->s_texture = texture;
	else if (!ft_strncmp(test, "WE", 2))
		map->w_texture = texture;
	else if (!ft_strncmp(test, "EA", 2))
		map->e_texture = texture;
	return (0);
}

/** @brief separates the options between all the options
* @return 1 on error else 0
* */
int	save_value(char *test, t_map *map)
{
	int	i;	

	i = 0;
	test = ft_strtrim(test, " ");
	test = ft_strtrim(test, "\t");
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
		printf("Error!\nCharacters not known\n");
		return (1);
	}
	return (0);
}
