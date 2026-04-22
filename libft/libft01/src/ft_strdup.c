/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:39 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 17:34:30 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		src_count;

	if (!src)
		return (NULL);
	src_count = ft_strlen(src) + 1;
	dest = malloc(src_count);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, src_count);
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char	*dest1;
	char	*dest2;

	dest1 = strdup("123+adfas");
	dest2 = ft_strdup("123+adfas");

	printf("strdup: %s\n", dest1);
	printf("ft_strdup: %s\n", dest2);
	free(dest1);
	free(dest2);
} */