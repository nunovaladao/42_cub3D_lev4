/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:46:04 by idias-al          #+#    #+#             */
/*   Updated: 2023/11/25 18:46:28 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int test_16(int i)
{
    int a;
    int result;

    a = 5;
    result = 1;
    while (a > i)
    {
        result *= 16;
        a--;
    }
    return (result);
}

int get_10(char c, char *base)
{
    int j;

    j = 0;
    while (j < 16)
    {
        if (c == base[j])
            return (j);
        j++;
    }
    return (0);
}

int get_base_10(char *color)
{
    int number;
    int i;

    i = 0;
    number = 0;
    while (color[i] != '\0')
    {
        number += get_10(color[i], "0123456789ABCDEF") * test_16(i);
        i++;
    }
    return (number);
}

char	*cleaning_func(char *test)
{
	char	*aux;

	aux = ft_strtrim(test, " ");
	free(test);
	test = NULL;
	test = ft_strdup(aux);
	free(aux);
	aux = NULL;
	aux = ft_strtrim(test, "\t");
	free(test);
	test = NULL;
	test = ft_strdup(aux);
	free(aux);
	aux = NULL;
	return (test);
}

char	*test_spaces(char *test)
{
    int i;

    i = 0;
	while ((test[i] == ' ' || test[i] == '\t') && test[i] != '\0')
		i++;
	if (i == (int)ft_strlen(test))
	{
		free(test);
		test = NULL;
	}
	return (test);
}
