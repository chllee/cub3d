/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:18:59 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 19:16:53 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return dest + src

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_count;
	size_t	src_count;

	dest_count = 0;
	src_count = 0;
	while (dest[dest_count] != '\0' && dest_count < size)
	{
		dest_count++;
	}
	if (size == 0 || size <= dest_count)
	{
		return (size + ft_strlen(src));
	}
	while (src[src_count] != '\0' && (dest_count + src_count + 1) < size)
	{
		dest[dest_count + src_count] = src[src_count];
		src_count++;
	}
	dest[dest_count + src_count] = '\0';
	return (dest_count + ft_strlen(src));
}

// strlcat() should return:
// initial length of dest + length of src
// But only if size > initial length of dest.
// Otherwise, it should return:
// size + length of src

/* #include <stdio.h>
#include <bsd/string.h> 

int main()
{
    // Test case variables
    char dest1[] = "Hello";
    char src1[] = " World!";
	char dest2[] = "Hello";
    char src2[] = " World!";

    // Testing ft_strlcat
	printf("size > dest\n");
	printf("dest len: %lu\n", strlen(dest1));
	printf("src len: %lu\n", strlen(src1));
	printf("strlcat result: %zu\n", strlcat(dest1, src1, 15));
    printf("ft_strlcat result: %d\n", ft_strlcat(dest2, src2, 15));
    printf("ft_strlcat dest: %s\n\n", dest1);

	char dest3[] = "Hello";
    char src3[] = " World!";
	char dest4[] = "Hello";
    char src4[] = " World!";

	printf("size < dest size 2\n");
	printf("dest len: %lu\n", strlen(dest3));
	printf("src len: %lu\n", strlen(src3));
	printf("strlcat result: %zu\n", strlcat(dest3, src3, 2));
    printf("ft_strlcat result: %d\n", ft_strlcat(dest4, src4, 2));
    printf("ft_strlcat dest: %s\n\n", dest3);

	char dest5[] = "Hello";
    char src5[] = " World!";
	char dest6[] = "Hello";
    char src6[] = " World!";

	printf("size = dest\n");
	printf("dest len: %lu\n", strlen(dest5));
	printf("src len: %lu\n", strlen(src5));
	printf("strlcat result: %zu\n", strlcat(dest5, src5, 5));
    printf("ft_strlcat result: %d\n", ft_strlcat(dest6, src6, 5));
    printf("ft_strlcat dest: %s\n\n", dest5);

	char dest7[] = "Hello";
    char src7[] = " World!";
	char dest8[] = "Hello";
    char src8[] = " World!";

	printf("size = 0\n");
	printf("dest len: %lu\n", strlen(dest7));
	printf("src len: %lu\n", strlen(src7));
	printf("strlcat result: %zu\n", strlcat(dest7, src7, 0));
    printf("ft_strlcat result: %d\n", ft_strlcat(dest8, src8, 0));
    printf("ft_strlcat dest: %s\n\n", dest7);

	return 0;
} */
