/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:33:14 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 16:32:41 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdest;
	size_t			count;

	count = 0;
	if (src == NULL || dest == NULL)
		return (dest);
	tempdest = (unsigned char *) dest;
	tempsrc = (unsigned char *) src;
	while (count < n)
	{
		tempdest[count] = tempsrc[count];
		count++;
	}
	return (dest);
}

// copies maximum n bytes from src to dst.
// if dest and src overlap, behaviour is undefined
// Return orignal value of dst
/* #include <stdio.h>
#include <string.h>

int main(void)
{
    const char s1[50] = "Welcomet0th3n3w w0r!d++";
    char d1[50] = "It's just an0ther t3st";

    printf("Before memcpy dest = %s\n", d1);
    printf("Before memcpy src = %s\n", s1);
    printf("\n");
    
    printf("   memcpy dest = %s\n", (char *)memcpy(d1, s1, 5));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(d1, s1, 5));
    
    printf("\n");
    
    // n == 0
    const char s2[50] = "abcdef";
    char d2[50] = "123456";
    
    printf("n == 0\n");
    printf("   memcpy dest = %s\n", (char *)memcpy(d2, s2, 0));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(d2, s2, 0));
    
    printf("\n");
    // src == dest - same memory address'
    char s3[10] = "abcdef";
    printf("src==dest, size smaller than src\n");
    printf("   memcpy dest = %s\n", (char *)memcpy(s3, s3, 3));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(s3, s3, 3));
    
    printf("\n");
    printf("src==dest, size bigger than src\n");
    printf("   memcpy dest = %s\n", (char *)memcpy(s3, s3, 10));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(s3, s3, 10));
    
    printf("\n");
    // Overlapping memory
    printf("Overlapping memory. Should be UB\n");
    char str[] = "Another test";
    printf("   memcpy dest = %s\n", (char *)memcpy(str + 1, str, 5));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(str + 1, str, 5));
	
	// dest == null
    const char s5[50] = "Why are we testing again?";
    char d5[50] = "";
    printf("dest == NULL\n");
    printf("   memcpy dest = %s\n", (char *)memcpy(d5, s5, 10));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(d5, s5, 10));
    
    printf("\n");
    // Very large n
    char *s6 = malloc(1000000);
    char *d6 = malloc(1000000);
    printf("very large n - check for crashes\n");
    printf("   memcpy dest = %s\n", (char *)memcpy(d6, s6, 100000));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(d6, s6, 100000));
    
    printf("\n");
    // copy strings with null characters
    char s7[] = {'a', 'b', '\t', 'd', '\0', 'e'};
    char d7[7];
    printf("with null characters\n");
    printf("   memcpy dest = %s\n", (char *)memcpy(d7, s7, 7));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(d7, s7, 7));

	printf("\n");
    // copy strings with null characters
    const char s8[50] = "Why are we testing \0 again?";
    char d8[50] = "";
    printf("with null characters in string\n");
    printf("   memcpy dest = %s\n", (char *)memcpy(d8, s8, 50));
    printf("ft_memcpy dest = %s\n", (char *)ft_memcpy(d8, s8, 50));
    
    printf("EOT\n");
    
    return(0);
} */
