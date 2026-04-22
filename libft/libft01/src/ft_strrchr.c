/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:59:59 by pang              #+#    #+#             */
/*   Updated: 2025/05/10 20:07:56 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
	char s1[] = "I don't know what this is...";
	char s2[] = "I don't know '\0' what this is...";
	char s3[] = "";

	printf("   strrchr: %s\n", strrchr(s1, 'c'));
	printf("ft_strrchr: %s\n", ft_strrchr(s1, 'c'));
	printf("   strrchr: %s\n", strrchr(s1, 'w'));
	printf("ft_strrchr: %s\n", ft_strrchr(s1, 'w'));
	printf("   strrchr: %s\n", strrchr(s1, 'I'));
	printf("ft_strrchr: %s\n", ft_strrchr(s1, 'I'));
	printf("   strrchr: %s\n", strrchr(s2, '\0'));
	printf("ft_strrchr: %s\n", ft_strrchr(s2, '\0'));
	printf("   strrchr: %s\n", strrchr(s3, 'i'));
	printf("ft_strrchr: %s\n", ft_strrchr(s3, 'i'));
} */
