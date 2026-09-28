/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:26:42 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/15 13:02:10 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
	ft_lstadd_front(&lst, ft_lstnew(&b));
	printf("%d -> %d\n", *(int *)lst->content, *(int *)lst->next->content);
	return (0);
}
*/
