/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/09 16:41:33 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*source;

	i = 0;
	source = (const unsigned char *) s;
	while (i < n)
	{
		if (source[i] == (unsigned char) c)
			return ((void *) &source[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", (char *)ft_memchr("hola mundo", 'm', 11));
	return (0);
}
*/
