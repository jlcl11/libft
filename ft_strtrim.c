/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 00:00:00 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/10 16:54:12 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	devolver_pos_ini(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && is_in_set(s1[i], set))
		i++;
	return (i);
}

static int	devolver_pos_final(char const *s1, char const *set)
{
	int	i;

	if (s1[0] == '\0')
		return (-1);
	i = ft_strlen(s1) - 1;
	while (i >= 0 && is_in_set(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		posini;
	int		posfinal;
	size_t	i;
	size_t	len;
	char	*ret;

	posini = devolver_pos_ini(s1, set);
	posfinal = devolver_pos_final(s1, set);
	if (posfinal < posini)
		len = 0;
	else
		len = posfinal - posini + 1;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[posini + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_strtrim("   hola mundo   ", " ");
	printf("[%s]\n", s);
	free(s);
	return (0);
}
*/
