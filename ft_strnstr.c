/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/09 14:12:54 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	d;
	size_t	j;

	if (little[0] == '\0')
		return ((char *) big);
	d = 0;
	while (big[d] != '\0' && d < len)
	{
		j = 0;
		while (little[j] != '\0' && d + j < len && big[d + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *) &big[d]);
		d++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("hola mundo", "mundo", 20));
	return (0);
}
*/
