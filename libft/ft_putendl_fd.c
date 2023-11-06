/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:16 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/10 22:28:11 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
	ft_putchar_fd('\n', fd);
}

/*int main()
{
    ft_putendl_fd("test", 0);
}*/
