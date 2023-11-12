/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:59:27 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/02 15:30:31 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

/*int	main(void)
{
	char str[] = "ola";
	printf("no: %ld", ft_strlen(str));
	return (0);
}*/
