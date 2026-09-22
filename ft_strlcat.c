/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:04:18 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/22 13:50:53 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	d;

	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	i = dstlen;
	d = 0;
	while (src[d] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[d];
		i++;
		d++;
	}
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}

/*#include <stdio.h>

int	main(void)
{
char	dst[10] = "hola ";

printf("return: %zu\n", ft_strlcat(dst, "mundo", sizeof(dst)));
printf("dst: %s\n", dst);
return (0);
}*/
