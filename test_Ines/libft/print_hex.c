/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:57:22 by nsoares-          #+#    #+#             */
/*   Updated: 2022/12/13 13:54:19 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tamanho_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*hex_utoa(unsigned int n, char *base)
{
	char	*str;
	int		size;

	size = tamanho_hex(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = base[n % 16];
		n /= 16;
		size--;
	}
	return (str);
}

int	print_hex(unsigned int n, char *base)
{
	char	*str;
	int		len;

	str = hex_utoa(n, base);
	len = print_str(str);
	free(str);
	return (len);
}
