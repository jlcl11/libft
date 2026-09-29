/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:26:42 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/15 12:26:42 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>

static void	print_int(void *content)
{
	printf("%d\n", *(int *)content);
}

int	main(void)
{
	t_list	*lst;
	int		a;
	int		b;

	a = 1;
	b = 2;
	lst = ft_lstnew(&a);
	ft_lstadd_front(&lst, ft_lstnew(&b));
	ft_lstiter(lst, print_int);
	return (0);
}
*/
