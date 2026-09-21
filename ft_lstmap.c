/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:26:42 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/15 12:26:42 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>

static void	del(void *content)
{
	free(content);
}

static void	*duplicate(void *content)
{
	int	*n;

	n = malloc(sizeof(int));
	if (n)
		*n = *(int *)content;
	return (n);
}

int	main(void)
{
	t_list	*lst;
	t_list	*copy;
	int		a;

	a = 7;
	lst = ft_lstnew(&a);
	copy = ft_lstmap(lst, duplicate, del);
	printf("%d\n", *(int *)copy->content);
	free(lst);
	ft_lstclear(&copy, del);
	return (0);
}
*/
