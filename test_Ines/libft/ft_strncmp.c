/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:57:16 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/15 21:34:54 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	u;

	u = 0;
	if (n == 0)
		return (0);
	while (s1[u] == s2[u] && s1[u] != '\0')
	{
		if (u < (n - 1))
			u++;
		else
			return (0);
	}
	return ((unsigned char)(s1[u]) - (unsigned char)(s2[u]));
}

/*#include <string.h>
int	main(void)
{
	char s1[] = "a";
	char s2[] = "a";
	
	printf("funcao: %d\n", ft_strncmp(s1, s2, 4));
	printf("correcao: %d\n", strncmp(s1, s2, 4));
}*/
