/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:44:12 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/15 19:50:33 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	count;

	count = 0;
	index = 0;
	if ((!dst || !src) && size == 0)
		return (0);
	while (src[count] != '\0')
		count++;
	if (size == 0)
		return (count);
	else if (size != '\0')
	{
		while (index < (size - 1) && src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
	}
	dst[index] = '\0';
	return (count);
}

/*#include <string.h>
int	main(void)
{
	char	src[] = "teste";
	char	dest[] = "testeeeee";
	
	printf("função: %ld\n", ft_strlcpy(dest, src, 0));
	printf("correção: %ld", strlcpy(dest, src, 0));
}*/
