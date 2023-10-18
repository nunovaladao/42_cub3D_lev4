/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:29 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/21 17:05:50 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contar_palavras(const char *s, char c)
{
	int	i;
	int	adiciona;

	i = 0;
	adiciona = 0;
	while (*s)
	{
		if (*s != c && adiciona == 0)
		{
			adiciona = 1;
			i++;
		}
		else if (*s == c)
			adiciona = 0;
		s++;
	}
	return (i);
}

static char	*cria_arr(const char *s, int start, int end)
{
	char	*pal;
	int		i;

	i = 0;
	pal = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		pal[i++] = s[start++];
	pal[i] = '\0';
	return (pal);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((contar_palavras(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = cria_arr(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

/*int main()
{
	char	s[] = "ooo oo o";
	char	**result = ft_split(s, ' ');

	int	i = 0;
	for(; result[i]; i++)
		printf("result[%d] = \'%s\'\n", i, result[i]);
	printf("words[%d]\n", i);
}*/