/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:57:32 by nsoares-          #+#    #+#             */
/*   Updated: 2022/12/13 15:36:39 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tamanho_hex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (print_char('0'));
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*hex_utoa(unsigned long n, char *base)
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

int	print_ptr(void *n, char *base)
{
	char			*str;
	int				len;
	unsigned long	nb;

	nb = (unsigned long)n;
	if (nb == 0)
		return (write(1, "(nil)", 5));
	str = hex_utoa(nb, base);
	write(1, "0x", 2);
	len = print_str(str);
	free (str);
	return (len + 2);
}
