/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:56:24 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/18 16:05:50 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int main()
{
	t_list *head;
	if(!(head = malloc(sizeof(t_list))))
		return 0;

	head->content = (char *)"olah";
	head->next = NULL;

	t_list *new;
	if(!(new = malloc(sizeof(t_list))))
		return 0;

	new->content = (char *)"adeus";
	new->next = NULL;

	printf("\nHead -> %s\n", (char *)head->content);

	ft_lstadd_front(&head, new);

	printf("Head -> %s\n", (char *)head->content);
}*/
