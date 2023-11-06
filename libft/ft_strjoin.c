/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:05:16 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/16 17:42:23 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1)
		return (NULL);
	if (!s2 && s1)
		return ((char *)s1);
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest)
	{
		ft_memcpy (dest, s1, ft_strlen(s1));
		ft_memcpy (dest + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	}
	return (dest);
}

/*int main()
{
	printf("%s", ft_strjoin("ft", "_join"));
}*/