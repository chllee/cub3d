/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:15:38 by pang              #+#    #+#             */
/*   Updated: 2025/05/10 20:06:54 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)s + count);
		count++;
	}
	if ((char)c == '\0')
		return ((char *)s + count);
	return (NULL);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
	char s1[] = "I don't know what this is...";
	char s2[] = "I don't know '\0' what this is...";
	char s3[] = "";

	printf("   strchr: %s\n", strchr(s1, 'c'));
	printf("ft_strchr: %s\n", ft_strchr(s1, 'c'));
	printf("   strchr: %s\n", strchr(s1, 'w'));
	printf("ft_strchr: %s\n", ft_strchr(s1, 'w'));
	printf("   strchr: %s\n", strchr(s1, 'I'));
	printf("ft_strchr: %s\n", ft_strchr(s1, 'I'));
	printf("   strchr: %s\n", strchr(s2, '\0'));
	printf("ft_strchr: %s\n", ft_strchr(s2, '\0'));
	printf("   strchr: %s\n", strchr(s3, 'a'));
	printf("ft_strchr: %s\n", ft_strchr(s3, 'a'));
} */
