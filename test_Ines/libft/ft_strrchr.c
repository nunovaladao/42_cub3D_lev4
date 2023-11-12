/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:50:04 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/15 19:05:56 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	*dest;
	int		i;

	i = 0;
	temp = (char *)s;
	dest = NULL;
	while (temp[i])
	{
		if (temp[i] == c)
			dest = &temp[i];
		i++;
	}
	if (temp[i] == c)
		return (&temp[i]);
	return (dest);
}

/*int	main(void)
{
	const char s[] = "teste";
	const char c = 'e';

	printf("%s", ft_strrchr(s, c));
}*/
