/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:55:08 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 17:52:15 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		count;
	size_t				s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	count = -1;
	while (++count < len)
		substr[count] = s[start + count];
	substr[count] = '\0';
	return (substr);
}

/* #include <stdio.h>

int	main(void)
{
	printf("ft_substr: %s\n", ft_substr("Part0fthe+world!", 3, 7));
	printf("len = 0: %s\n", ft_substr("Part0fthe+world!", 5, 0));
	printf("start bigger than s: %s\n", ft_substr("Part0fthe world!", 30, 50));
	printf("null string: %s\n", ft_substr("", 3, 50));
} */
