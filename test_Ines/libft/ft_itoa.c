/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:23:15 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/16 17:58:04 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valor_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	tamanho(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		++l;
	while (n != 0)
	{
		++l;
		n = n / 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		size;

	size = tamanho(n);
	string = malloc(sizeof(char) * (size + 1));
	if (string == NULL)
		return (NULL);
	string[size] = '\0';
	if (n < 0)
		string[0] = '-';
	if (n == 0)
		string[0] = '0';
	while (n != 0)
	{
		--size;
		string[size] = valor_abs(n % 10) + '0';
		n = n / 10;
	}
	return (string);
}

/*int main(void)
{
	printf("funcao: %s\n", ft_itoa(010));
}*/
