/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:38:50 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 09:39:14 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		ch += 'A' - 'a';
	return (ch);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void) {
    char c,
    d,
    e,
    f,
    g,
    h;
    char s1[] = "T3st1Ng +£*%";
    int count;

    c = 'w';
    d = '4';
    e = '+';
    f = 'T';
    g = '\t';
    h = 126;

    // single character
    printf("%c\n", toupper(c));
    printf("%c\n", ft_toupper(c));
    printf("%c\n", toupper(d));
    printf("%c\n", ft_toupper(d));
    printf("%c\n", toupper(e));
    printf("%c\n", ft_toupper(e));
    printf("%c\n", toupper(f));
    printf("%c\n", ft_toupper(f));
    printf("%c\n", toupper(g));
    printf("%c\n", ft_toupper(g));
    printf("%c\n", toupper(h));
    printf("%c\n", ft_toupper(h));

    printf("\n");

    // strings
    count = 0;
    while (s1[count] != '\0') {
        printf("%c", toupper(s1[count]));
        count++;
    }
    printf("\n");

    count = 0;
    while (s1[count] != '\0') {
        printf("%c", ft_toupper(s1[count]));
        count++;
    }

} */