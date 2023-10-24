/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:16:18 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/16 22:22:31 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	st = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[st]) && st <= end)
		st++;
	if (st > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - st + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[st], end - st + 2);
	return (str);
}
