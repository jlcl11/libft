/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/09 17:06:46 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*puntero;

	if (nmemb != 0 && size > (size_t) -1 / nmemb)
		return (NULL);
	puntero = malloc(nmemb * size);
	if (!puntero)
		return (NULL);
	ft_memset(puntero, 0, nmemb * size);
	return (puntero);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*arr;
	int	i;

	arr = ft_calloc(5, sizeof(int));
	i = 0;
	while (i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}
*/
