/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/09 16:54:02 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*first;
	const unsigned char	*second;

	first = (const unsigned char *) s1;
	second = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (first[i] != second[i])
		{
			if (first[i] > second[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_memcmp("abc", "abd", 3));
	printf("%d\n", ft_memcmp("abc", "abc", 3));
	return (0);
}
*/
