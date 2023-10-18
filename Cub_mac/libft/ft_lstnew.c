/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:30:22 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/18 10:51:48 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (new)
	{
		new ->content = content;
		new ->next = NULL;
	}
	return (new);
}

/*int main()
{
    t_list *node;
    int a = 3;

    node = ft_lstnew((void *)&a);
    while(node)
    {
        printf("%d", *(int*)node ->content);
        node = node ->next;
    }
    free(node);
}*/
