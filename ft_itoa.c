/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 00:00:00 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/14 13:03:42 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_fill(char *ret, int i, long num)
{
	if (num == 0)
		ret[i] = '0';
	while (num > 0)
	{
		ret[i--] = num % 10 + '0';
		num = num / 10;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*ret;

	num = n;
	len = ft_intlen(num);
	if (num < 0)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (num < 0)
	{
		ret[0] = '-';
		num = -num;
	}
	ft_itoa_fill(ret, len - 1, num);
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_itoa(-4212);
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
