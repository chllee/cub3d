/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:33:32 by pang              #+#    #+#             */
/*   Updated: 2025/05/10 20:47:17 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (count < n)
	{
		if (c1[count] != c2[count])
			return (c1[count] - c2[count]);
		count++;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
    // Test 1: Identical strings
    char s1[] = "apple";
    char s2[] = "apple";
    printf("Test 1 - Identical strings:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 5) = %d\n", 
	s1, s2, ft_memcmp(s1, s2, 5)); // Expected: 0
    printf("memcmp(\"%s\", \"%s\", 5) = %d\n\n", 
	s1, s2, memcmp(s1, s2, 5)); // Expected: 0

    // Test 2: Different strings, same length
    char s3[] = "apple";
    char s4[] = "apricot";
    printf("Test 2 - Different strings, same length:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 5) = %d\n", 
	s3, s4, ft_memcmp(s3, s4, 5)); // Expected: Negative value
    printf("memcmp(\"%s\", \"%s\", 5) = %d\n\n", 
	s3, s4, memcmp(s3, s4, 5)); // Expected: Negative value

    // Test 3: Compare part of a string
    char s5[] = "banana";
    char s6[] = "ban";
    printf("Test 3 - Compare part of a string:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 3) = %d\n", 
	s5, s6, ft_memcmp(s5, s6, 3)); // Expected: 0
    printf("memcmp(\"%s\", \"%s\", 3) = %d\n\n", 
	s5, s6, memcmp(s5, s6, 3)); // Expected: 0

    // Test 4: Different length strings, but only first n characters are compared
    char s7[] = "apple";
    char s8[] = "applesauce";
    printf("Test 4 - Different length strings, first n characters:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 5) = %d\n", 
	s7, s8, ft_memcmp(s7, s8, 5)); // Expected: 0
    printf("memcmp(\"%s\", \"%s\", 5) = %d\n\n", 
	s7, s8, memcmp(s7, s8, 5)); // Expected: 0

    // Test 5: First string is lexicographically smaller
    char s9[] = "apple";
    char s10[] = "banana";
    printf("Test 5 - First string is lexicographically smaller:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 5) = %d\n", 
	s9, s10, ft_memcmp(s9, s10, 5)); // Expected: Negative value
    printf("memcmp(\"%s\", \"%s\", 5) = %d\n\n", 
	s9, s10, memcmp(s9, s10, 5)); // Expected: Negative value

    // Test 6: First string is lexicographically greater
    char s11[] = "cherry";
    char s12[] = "apple";
    printf("Test 6 - First string is greater:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 5) = %d\n", 
	s11, s12, ft_memcmp(s11, s12, 5)); // Expected: Positive value
    printf("memcmp(\"%s\", \"%s\", 5) = %d\n\n", 
	s11, s12, memcmp(s11, s12, 5)); // Expected: Positive value

    // Test 7: Case-sensitive comparison
    char s13[] = "Apple";
    char s14[] = "apple";
    printf("Test 7 - Case-sensitive comparison:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 5) = %d\n", 
	s13, s14, ft_memcmp(s13, s14, 5)); // Expected: Negative value
    printf("memcmp(\"%s\", \"%s\", 5) = %d\n\n", 
	s13, s14, memcmp(s13, s14, 5)); // Expected: Negative value

    // Test 9: Compare with 0 characters
    char s17[] = "apple";
    char s18[] = "banana";
    printf("Test 9 - Compare with 0 characters:\n");
    printf("ft_memcmp(\"%s\", \"%s\", 0) = %d\n", 
	s17, s18, ft_memcmp(s17, s18, 0)); // Expected: 0
    printf("memcmp(\"%s\", \"%s\", 0) = %d\n\n", 
	s17, s18, memcmp(s17, s18, 0)); // Expected: 0

    return 0;
} */
