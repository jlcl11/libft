/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/23 12:09:58 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_back_to_front(char *dest, const char *source, size_t len)
{
	while (len > 0)
	{
		len--;
		dest[len] = source[len];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*source;

	dest = (char *) dst;
	source = (const char *) src;
	if (dest == source || len == 0)
		return (dst);
	if (dest < source)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
		ft_memmove_back_to_front(dest, source, len);
	return (dst);
}

/*
#include <stdio.h>

int	main(void)
{
char	buf[] = "hola mundo";

ft_memmove(buf + 1, buf, 4);
printf("%s\n", buf);
return (0);
}*/
