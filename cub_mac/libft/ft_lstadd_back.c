/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:43:26 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/19 17:38:33 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_lstlast(*(lst));
			last->next = new;
		}
	}
}

/*int main()
{
	t_list *head;
	t_list *dois;
	t_list *tres;
	t_list *quatro;

	if(!(head = malloc(sizeof(t_list))))
		return 0;
	head->content = "-- UM --";
	head->next = NULL;

	if(!(dois = malloc(sizeof(t_list))))
		return 0;
	dois->content = "-- DOIS --";
	dois->next = NULL;

	if(!(tres = malloc(sizeof(t_list))))
		return 0;
	tres->content = "-- TRES --";
	tres->next = NULL;

	if(!(quatro = malloc(sizeof(t_list))))
		return 0;
	quatro->content = "-- QUATRO --";
	quatro->next = NULL;


	head->next = dois;
	head->next->next = tres;

	printf("All Numbers %s %s %s %p", (char *)head->content, \
	(char *)head->next->content,
									(char *)head->next->next->content,
									head->next->next->next);

	ft_lstadd_back(&head, quatro);

	printf("\nAll Numbers %s %s %s %s %p", (char *)head->content, \ 
	(char *)head->next->content,
										(char *)head->next->next->content,
										(char *)head->next->next->next->content,
										head->next->next->next->next);
}*/