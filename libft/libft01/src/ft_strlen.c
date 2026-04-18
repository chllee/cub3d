/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:35:54 by pang              #+#    #+#             */
/*   Updated: 2025/05/13 19:44:49 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

/* #include <string.h>
#include <stdio.h>

 int	main(void)
{
	printf("%ld\n", strlen("Into the new world!"));
	printf("%d\n", ft_strlen("Into the new world!"));
	printf("%ld\n", strlen("Into\nthe new world!  "));
	printf("%d\n", ft_strlen("Into\nthe n3w w0rld!  "));
	printf("%ld\n", strlen(""));
	printf("%d\n", ft_strlen(""));
} */
