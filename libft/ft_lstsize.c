/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:07:19 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/18 14:07:23 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int main()
{
	t_list *first;
	t_list *second;
	
	int a = 4;
	int b = 5;
	int len;
	
	first = ft_lstnew((void *)&a);
	second = ft_lstnew((void *)&b);
	first->next = second;
	
	len = ft_lstsize(first);
	
	printf("%d", len);
}*/
