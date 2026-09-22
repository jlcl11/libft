/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocorral <jocorral@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:54:56 by jocorral          #+#    #+#             */
/*   Updated: 2026/09/21 17:09:31 by jocorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	aux;

	aux = '\0';
	ft_memset(s, aux, n);
}

/*#include <stdio.h>

int	main(void)
{
char	buf[6] = "hola!";

ft_bzero(buf, 6);
printf("%d %d %d\n", buf[0], buf[1], buf[5]);
return (0);
}*/
