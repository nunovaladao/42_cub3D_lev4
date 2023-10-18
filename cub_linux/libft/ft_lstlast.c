/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:13:16 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/18 15:40:35 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int main()
{
	t_list *head;
	t_list *dois;
	t_list *tres;
	t_list *quatro;
	t_list *last;

	head = ft_lstnew("UM");
	dois = ft_lstnew("DOIS");
	tres = ft_lstnew("TRES");
	quatro = ft_lstnew("QUATRO");

	head->next = dois;
	dois->next = tres;
	tres->next = quatro;

	printf("\nO ultimo t_list eh -- %s -- e tem pointer de %p \n",\ 
	(char *)quatro->content, quatro->next);

	last = ft_lstlast(head);

	printf("O ultimo t_list eh -- %s -- e tem pointer de %p \n",\
	(char *)last->content, last->next);
}*/
