/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memset.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jocorral <jocorral@42malaga.com>          #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/01 17:54:56 by jocorral         #+#    #+#              */
/*   Updated: 2026/09/02 10:01:13 by jocorral        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// volver

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	buf[10];

	ft_memset(buf, 'x', 9);
	buf[9] = '\0';
	printf("%s\n", buf);
	return (0);
}
*/
