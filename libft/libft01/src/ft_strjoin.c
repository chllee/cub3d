/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:27:31 by pang              #+#    #+#             */
/*   Updated: 2025/05/10 22:44:55 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		count;
	int		scount;

	count = 0;
	scount = 0;
	dest = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[scount] != '\0')
	{
		dest[count] = s1[scount];
		count++;
		scount++;
	}
	scount = 0;
	while (s2[scount] != '\0')
	{
		dest[count] = s2[scount];
		count++;
		scount++;
	}
	dest[count] = '\0';
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char s1[] = "test";
	char s2[] = "123";

	printf("%s\n\n", ft_strjoin(s1, s2))#include <stdio.h>;

	char s3[] = "test";
	char s4[] = "";

	printf("s2 null: %s\n\n", ft_strjoin(s3, s4));

	char s5[] = "";
	char s6[] = "t3+st";

	printf("s1 null: %s\n\n", ft_strjoin(s5, s6));
	
	return (0);
}  */
