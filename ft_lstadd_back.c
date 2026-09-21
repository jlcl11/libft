/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:26:42 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/15 12:26:42 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst;
	int		a;
	int		b;

	a = 1;
	b = 2;
	lst = ft_lstnew(&a);
	ft_lstadd_back(&lst, ft_lstnew(&b));
	printf("%d -> %d\n", *(int *)lst->content, *(int *)lst->next->content);
	return (0);
}
*/
