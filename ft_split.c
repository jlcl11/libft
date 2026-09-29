/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 00:00:00 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/22 16:40:22 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
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

static void	free_mem(char **split)
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

static int	fill_split(char const *s, char c, char **ret)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			len = len_until_next_char(s + j, c);
			ret[i] = ft_substr(s, j, len);
			if (!ret[i])
				return (-1);
			i++;
			j += len;
		}
	}
	ret[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	ret = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	if (fill_split(s, c, ret) == -1)
	{
		free_mem(ret);
		return (NULL);
	}
	return (ret);
}

/*#include <stdio.h>

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
}*/
