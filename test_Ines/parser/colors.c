/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inesalves <inesalves@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:02:34 by inesalves         #+#    #+#             */
/*   Updated: 2023/11/25 22:55:17 by inesalves        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
 
 /**
  * @brief Get the factors rgb object
  * e, g and b factors in colors
  * @param i -> index in string
  * @param test 
  * @return int -> returns in test
  */
int	get_factors_rgb(int *i, char *test)
{
	int		init;
	int		final;
	int		number;
	char	*str;

	init = *i;
	while (test[*i] >= '0' && test[*i] <= '9')
		(*i)++;
	if (*i == init)
		return (-1);
	final = *i;
	if (clear_spaces(i, test, 1) < 0)
		return (-1);
	str = ft_substr(test, init, final - init);
	number = ft_atoi(str);
	free(str);
	str = NULL;
	return (number);
}

/** @brief with a base transform rgb to hexa
* */
void	get_hexa_parts(int *i, char **hexa, int color)
{
	char	*base;
	char	*str;
	int		j;

	j = 0;
	base = ft_strdup("0123456789ABCDEF");
	str = malloc(sizeof(char) * 3);
	str[j] = base[color / 16];
	j++;
	str[j] = base[color % 16];
	j++;
	str[j] = '\0';
	j = 0;
	while (str[j] != '\0')
	{
		*(*(hexa) + (*i)) = str[j];
		j++;
		(*i)++;
	}
	free(str);
	free(base);
}

/** @brief returns a string of an hexa
* */
char	*get_hexa(t_rgb color)
{
	char	*hexa;
	int		i;

	if (color.r < 0 || color.r > 255 || color.g < 0 || \
	color.g > 255 || color.b < 0 || color.b > 255)
	{
		printf("Error!\nRGB needs to be between 0 and 255\n");
		return (NULL);
	}
	hexa = ft_calloc(sizeof(char), 9);
	i = 0;
	get_hexa_parts(&i, &hexa, color.r);
	get_hexa_parts(&i, &hexa, color.g);
	get_hexa_parts(&i, &hexa, color.b);
	hexa[i] = '\0';
	return (hexa);
}

/**
 * @brief clears the spaces or tabs
 * @param i 
 * @param test 
 * @param a 
 * @return int 
 */
int	clear_spaces(int *i, char *test, int a)
{
	if (a == 0)
	{
		*i = 2;
		if (test[1] != ' ' && test[1] != '\t')
		{
			printf("Error\nColor: Character not valid\n");
			return (1);
		}
		while ((test[*i] == ' ' || test[*i] == '\t') && \
		test[*i] != '\n' && test[*i] != '\0')
			(*i)++;
	}
	else
	{
		while (test[*i] != ',' && test[*i] != '\n' && test[*i] != '\0')
		{
			if (test[*i] != ' ' && test[*i] != '\t')
				return (-1);
			(*i)++;
		}
		(*i)++;
	}
	return (0);
}

/** @brief first creates rgb then the hexa 
* */
int	get_colors(char *test, t_map *map)
{
	int		i;
	char	*str;
	t_rgb	color;

	if (clear_spaces(&i, test, 0))
		return (1);
	color.r = get_factors_rgb(&i, test);
	color.g = get_factors_rgb(&i, test);
	color.b = get_factors_rgb(&i, test);
	if (color.r < 0 || color.g < 0 || color.b < 0)
	{
		printf("Error!\nColor: Rgb not valid!\n");
		return (1);
	}
	str = get_hexa(color);
	if (!str)
		return (1);
	if (ft_strchr(test, 'F'))
		map->color_f = str;
	else
		map->color_c = str;
	return (0);
}
