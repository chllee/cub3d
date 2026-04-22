/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:33:33 by pang              #+#    #+#             */
/*   Updated: 2025/05/10 19:55:35 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	unsigned int	str_count;
	unsigned int	sub_count;

	str_count = 0;
	if (*substr == '\0')
		return ((char *)str);
	while (str_count < len && str[str_count] != '\0')
	{
		sub_count = 0;
		while (substr[sub_count] != '\0')
		{
			if (str[str_count + sub_count] == substr[sub_count]
				&& (str_count + sub_count < len))
				sub_count++;
			else
				break ;
		}
		if (substr[sub_count] == '\0')
			return ((char *)str + str_count);
		str_count++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char *b1 = "Foo Bar Baz";
    char *s1 = "Bar";
    char *ptr;
	char *ptr2;

	printf("Normal\n");
    ptr = strnstr(b1, s1, 8);
	ptr2 = ft_strnstr(b1, s1, 8);
	printf("%s\n", ptr);
	printf("%s\n\n", ptr2);

	char *b2 = "Foo Bar Baz";
    char *s2 = "";
    char *ptr3;
	char *ptr4;

	printf("sub null\n");
    ptr3 = strnstr(b2, s2, 8);
	ptr4 = ft_strnstr(b2, s2, 8);
	printf("%s\n", ptr3);
	printf("%s\n\n", ptr4);

	char *b3 = "Foo Bar Baz";
    char *s3 = "o";
    char *ptr5;
	char *ptr6;

	printf("single 'o'\n");
    ptr5 = strnstr(b3, s3, 8);
	ptr6 = ft_strnstr(b3, s3, 8);
	printf("%s\n", ptr5);
	printf("%s\n\n", ptr6);

	char *b4 = "Foo Bar Baz";
    char *s4 = "Bar";
    char *ptr9;
	char *ptr10;

	printf("len 3\n");
    ptr9 = strnstr(b4, s4, 3);
	ptr10 = ft_strnstr(b4, s4, 3);
	printf("%s\n", ptr9);
	printf("%s\n\n", ptr10);

	char *b5 = "Foo Bar Baz";
    char *s5 = "Bar";
    char *ptr11;
	char *ptr12;

	printf("len 0\n");
    ptr11 = strnstr(b5, s5, 0);
	ptr12 = ft_strnstr(b5, s5, 0);
	printf("%s\n", ptr11);
	printf("%s\n\n", ptr12);

	char *b6 = "";
    char *s6 = "Bar";
    char *ptr13;
	char *ptr14;

	printf("big null\n");
    ptr13 = strnstr(b6, s6, 8);
	ptr14 = ft_strnstr(b6, s6, 8);
	printf("%s\n", ptr13);
	printf("%s\n\n", ptr14);

	char *b7 = "Foo Bar Baz";
    char *s7 = "bar";
    char *ptr15;
	char *ptr16;

	printf("small sub letters\n");
    ptr15 = strnstr(b7, s7, 8);
	ptr16 = ft_strnstr(b7, s7, 8);
	printf("%s\n", ptr15);
	printf("%s\n\n", ptr16);
} */