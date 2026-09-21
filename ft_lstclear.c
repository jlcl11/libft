/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:26:42 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/15 12:26:42 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

/*
#include <stdio.h>

static void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	int		*a;
	int		*b;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	*a = 1;
	*b = 2;
	lst = ft_lstnew(a);
	ft_lstadd_front(&lst, ft_lstnew(b));
	ft_lstclear(&lst, del);
	printf("lst == NULL: %d\n", lst == NULL);
	return (0);
}
*/
