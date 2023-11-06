/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:10:09 by nsoares-          #+#    #+#             */
/*   Updated: 2023/03/03 17:02:01 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	u;

	u = 0;
	while (s1[u] == s2[u] && s1[u] != '\0')
		u++;
	return ((unsigned char)(s1[u]) - (unsigned char)(s2[u]));
}

/* #include <string.h>
int main()
{
    char s1[] = "nuno";
    char s2[] = "nun";

    printf("%d\n", ft_strcmp(s1, s2));
    printf("%d\n", strcmp(s1, s2));
    
} */