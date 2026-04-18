/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:18:36 by pang              #+#    #+#             */
/*   Updated: 2025/06/03 20:24:56 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (NULL);
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

char	*ft_strjoin_sub(char const *s1, char const *s2)
{
	char	*result;
	int		count;
	int		scount;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	count = 0;
	scount = 0;
	result = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!result)
		return (NULL);
	while (s1[count] != '\0')
	{
		result[count] = s1[count];
		count++;
	}
	while (s2[scount] != '\0')
		result[count++] = s2[scount++];
	result[count] = '\0';
	return (result);
}

char	*ft_strdup_extract(const char *src)
{
	char	*dest;
	int		count;
	int		dcount;

	if (!src || !*src)
		return (NULL);
	count = 0;
	dcount = 0;
	while (src[count] && src[count] != '\n')
		count++;
	if (src[count] == '\n')
		count++;
	dest = malloc(count + 1);
	if (!dest)
		return (NULL);
	while (dcount < count)
	{
		dest[dcount] = src[dcount];
		dcount++;
	}
	dest[dcount] = '\0';
	return (dest);
}

char	*ft_substr_remain(const char *s)
{
	size_t	count;
	size_t	r_count;
	char	*result;

	if (!s)
		return (NULL);
	count = 0;
	r_count = 0;
	while (s[count] != '\0' && s[count] != '\n')
		count++;
	if (s[count] == '\0')
		return (NULL);
	count++;
	result = malloc(ft_strlen((char *)s + count) + 1);
	if (!result)
		return (NULL);
	while (s[count] != '\0')
	{
		result[r_count] = s[count];
		r_count++;
		count++;
	}
	result[r_count] = '\0';
	return (result);
}
