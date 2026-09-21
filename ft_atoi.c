/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/08 13:22:39 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signo;
	int	ret;

	i = 0;
	signo = 1;
	ret = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signo = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	return (ret * signo);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("   -42 texto"));
	printf("%d\n", ft_atoi("+123"));
	return (0);
}
*/
