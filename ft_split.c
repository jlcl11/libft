/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 00:00:00 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/14 15:59:38 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_splitter(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

static int	len_until_next_char(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	free_mem(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char *) * (ft_count_splitter(s, c) + 2));
	if (!ret)
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			len = len_until_next_char(s + j, c);
			ret[i] = ft_substr(s, j, len);
			i++;
			j += len;
		}
	}
	ret[i] = NULL;
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**parts;
	int		i;

	parts = ft_split("hola  mundo cruel", ' ');
	i = 0;
	while (parts[i])
	{
		printf("[%s]\n", parts[i]);
		i++;
	}
	free_mem(parts);
	return (0);
}
*/
