/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:06:00 by nsoares-          #+#    #+#             */
/*   Updated: 2022/12/13 12:24:47 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (write(1, "0", 1));
	str = ft_utoa(n);
	len = print_str(str);
	free (str);
	return (len);
}
