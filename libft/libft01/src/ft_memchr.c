/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:08:32 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 18:54:54 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	count;
	unsigned char	*str;

	count = 0;
	str = (unsigned char *)s;
	while (count < n)
	{
		if (str[count] == (unsigned char)c)
			return (str + count);
		count++;
	}
	return (NULL);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
	char s1[] = "I don't know what this is...";
	char s2[] = "I don't know '\0' what this is...";
	char s3[] = "";

	printf("   memchr: %s\n", (char *)memchr(s1, 'c', 9));
	printf("ft_memchr: %s\n", (char *)ft_memchr(s1, 'c', 9));
	printf("   memchr: %s\n", (char *)memchr(s1, 'w', 15));
	printf("ft_memchr: %s\n", (char *)ft_memchr(s1, 'w', 15));
	printf("   memchr: %s\n", (char *)memchr(s1, 'I', 9));
	printf("ft_memchr: %s\n", (char *)ft_memchr(s1, 'I', 9));
	printf("   memchr: %s\n", (char *)memchr(s2, '\0', 9));
	printf("ft_memchr: %s\n", (char *)ft_memchr(s2, '\0', 9));
	printf("   memchr: %s\n", (char *)memchr(s3, 'i', 9));
	printf("ft_memchr: %s\n", (char *)ft_memchr(s3, 'i', 9));
} */
