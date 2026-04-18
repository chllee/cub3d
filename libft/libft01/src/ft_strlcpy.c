/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:07:23 by pang              #+#    #+#             */
/*   Updated: 2025/05/13 19:44:33 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	src_len;

	count = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size > 0)
	{
		while (src[count] != '\0' && count < size -1)
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (src_len);
}

/* #include <bsd/string.h>
#include <stdio.h>

int main()
{
	char s1[] = "TESTSTRINGabc!@#$^";
	char d1[10];
	
	printf("dest null\n");
	printf("   strlcpy srclen: %zu\n", strlcpy(d1, s1, 10));
	printf("   strlcpy src: %s\n", s1);
	printf("   strlcpy dest: %s\n", d1);
	printf("ft_strlcpy srclen: %d\n", ft_strlcpy(d1, s1, 10));
	printf("ft_strlcpy src: %s\n", s1);
	printf("ft_strlcpy dest: %s\n\n", d1);

	// Null src
	char s2[] = "";
	char d2[] = "test test";
	
	printf("null src\n");
	printf("   strlcpy srclen: %zu\n", strlcpy(d2, s2, 10));
	printf("   strlcpy src: %s\n", s2);
	printf("   strlcpy dest: %s\n", d2);

	printf("ft_strlcpy srclen: %d\n", ft_strlcpy(d2, s2, 10));
	printf("ft_strlcpy src: %s\n", s2);
	printf("ft_strlcpy dest: %s\n\n", d2);

	// src and dest
	char s3[] = "TESTSTRINGabc!@#$^";
	char d3[] = "test test";
	
	printf("src and dest\n");
	printf("   strlcpy srclen: %zu\n", strlcpy(d3, s3, 10));
	printf("   strlcpy src: %s\n", s3);
	printf("   strlcpy dest: %s\n", d3);

	printf("ft_strlcpy srclen: %d\n", ft_strlcpy(d3, s3, 5));
	printf("ft_strlcpy src: %s\n", s3);
	printf("ft_strlcpy dest: %s\n\n", d3);

	// size = 0
	printf("If size == 0\n");
	printf("   strlcpy srclen: %zu\n", strlcpy(d3, s3, 0));
	printf("   strlcpy src: %s\n", s3);
	printf("   strlcpy dest: %s\n", d3);
	printf("ft_strlcpy srclen: %d\n", ft_strlcpy(d3, s3, 0));
	printf("ft_strlcpy src: %s\n", s3);
	printf("ft_strlcpy dest: %s\n\n", d3);

	return 0;
}
 */
