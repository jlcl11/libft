/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/21 11:37:05 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char) s1[i] > (unsigned char) s2[i])
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
printf("%d\n", ft_strncmp("hola", "holanda", 4));
printf("%d\n", ft_strncmp("hola", "holanda", 5));
return (0);
}
*/
