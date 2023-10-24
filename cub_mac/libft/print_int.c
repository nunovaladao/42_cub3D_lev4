/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:57:41 by nsoares-          #+#    #+#             */
/*   Updated: 2022/12/12 18:22:53 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = print_str(str);
	free (str);
	return (len);
}
