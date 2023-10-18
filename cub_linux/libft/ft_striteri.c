/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:15 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/16 18:49:56 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void function(unsigned int i, char *c)
{
	i = 0;
	
	if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int main()
{
	char s[] = "TEst";
	ft_striteri(s, function);
	printf("%s", s);
}*/
