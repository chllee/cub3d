/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:58:06 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 17:34:28 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			count;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	count = 0;
	if (n == 0 || dest == src)
		return (dest);
	if (d < s)
	{
		while (count < n)
		{
			d[count] = s[count];
			count++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}

/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char test1[] = "123456789";
    char test2[] = "123456789";

    // Normal overlapping (dest < src)
    memmove(test1 + 2, test1, 5);
    ft_memmove(test2 + 2, test2, 5);
    printf("Standard memmove : %s\n", test1);
    printf("Custom ft_memmove: %s\n\n", test2);

    // Overlapping (dest > src)
    char test3[] = "abcdef";
    char test4[] = "abcdef";
    memmove(test3, test3 + 2, 4);
    ft_memmove(test4, test4 + 2, 4);
    printf("Standard memmove : %s\n", test3);
    printf("Custom ft_memmove: %s\n\n", test4);

    // Zero bytes copy
    char test5[] = "abc";
    char test6[] = "abc";
    memmove(test5, test5 + 1, 0);
    ft_memmove(test6, test6 + 1, 0);
    printf("Zero-byte memmove : %s\n", test5);
    printf("Zero-byte ft_memmove: %s\n\n", test6);

	// Random test
    char test7[] = "abc";
    char test8[] = "";
	char test9[] = "abc";
    char test10[] = "";
    memmove(test8, test7 + 1, 1);
    ft_memmove(test10, test9 + 1, 1);
    printf("Random test: %s\n", test8);
    printf("Random test: %s\n\n", test10);

    // NULL pointers
    // Uncomment these carefully; they should both return NULL
    // printf("memmove NULL: %p\n", memmove(NULL, NULL, 0));
    // printf("ft_memmove NULL: %p\n", ft_memmove(NULL, NULL, 0));

    return 0;
} */