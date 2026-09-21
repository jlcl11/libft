/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:26:42 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/15 13:07:04 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst;
	int		a;

	a = 1;
	lst = ft_lstnew(&a);
	ft_lstadd_front(&lst, ft_lstnew(&a));
	printf("size: %u\n", ft_lstsize(lst));
	return (0);
}
*/
