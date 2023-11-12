/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:50:06 by nsoares-          #+#    #+#             */
/*   Updated: 2022/11/20 20:49:02 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*head;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	head = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_lst = new_lst->next;
	}
	return (head);
}

/*void *f(void *nome)
{
	char *a = "-- Olah --";
	return ((char *)ft_strlcpy(nome, a, ft_strlen(a) + 1));
}

void	del(void *c)
{
	free (c);
}

int		main()
{
	t_list *head;
	t_list *um;
	t_list *dois;
	t_list *tres;


	char *c1 = ft_strdup("-- Adeus Um --");
	char *c2 = ft_strdup("-- Adeus Dois --");
	char *c3 = ft_strdup("-- Adeus Tres --");ahh ---- Asd ---- Dswh ---- W
	char *c4 = ft_strdup("-- Adeus Quatro --");

	head = ft_lstnew(c1);
	um = ft_lstnew(c2);
	dois = ft_lstnew(c3);
	tres = ft_lstnew(c4);

	ft_lstadd_back(&head, um);
	ft_lstadd_back(&head, dois);
	ft_lstadd_back(&head, tres);

	printf("\n%s%s%s%s\n", (char *)head->content, (char *)head->next->content,
										(char *)head->next->next->content,
										(char *)head->next->next->next->content);

	t_list *nova = ft_lstmap(head, f, del);

	printf("\n%s%s%s%s\n", (char *)head->content, (char *)head->next->content,
										(char *)head->next->next->content,
										(char *)head->next->next->next->content);


	nova->content = "-- Bahh --";
	nova->next->content = "-- Asd --";
	nova->next->next->content = "-- Dswh --";
	nova->next->next->next->content = "-- Wrq --";
	printf("\n%s%s%s%s\n", (char *)nova->content, (char *)nova->next->content,
										(char *)nova->next->next->content,
										(char *)nova->next->next->next->content);

	return (0);
}*/
