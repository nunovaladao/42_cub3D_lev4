/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:00:15 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/15 11:06:17 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*#include <string.h>
int main()
{
    const char src[50] = "avaliação";
    char dest[50];

    strcpy(dest, "teste");
    
    printf("Antes memcpy dest = %s\n", dest);
    ft_memcpy(dest, src, ft_strlen(src)+1);
    printf("Agora memcpy dest = %s\n", dest);
}*/