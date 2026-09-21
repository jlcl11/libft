/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 00:00:00 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/10 11:31:03 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strjoin_copy(char *dst, const char *src, size_t start)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	return (start + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	end;
	char	*ret;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ret = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ret)
		return (NULL);
	end = ft_strjoin_copy(ret, s1, 0);
	end = ft_strjoin_copy(ret, s2, end);
	ret[end] = '\0';
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_strjoin("hola ", "mundo");
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
