/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:08:46 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/10 22:46:01 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = (unsigned int)(n * -1);
	}
	else
		number = (unsigned int)n;
	if (number >= 10)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd((char)(number % 10 + 48), fd);
}

/*int main()
{
    ft_putnbr_fd(20, 0);
}*/
