/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:37:55 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 17:41:34 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch += 'a' - 'A';
	return (ch);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void) {
    char c, d, e, f, g, h;
    char s1[] = "T3st1Ng +£*%";
    int count;

    c = 'w';
    d = '4';
    e = '+';
    f = 'T';
    g = '\t';
    h = 126;

    // single character
    printf("%c\n", tolower(c));
    printf("%c\n", ft_tolower(c));
    printf("%c\n", tolower(d));
    printf("%c\n", ft_tolower(d));
    printf("%c\n", tolower(e));
    printf("%c\n", ft_tolower(e));
    printf("%c\n", tolower(f));
    printf("%c\n", ft_tolower(f));
    printf("%c\n", tolower(g));
    printf("%c\n", ft_tolower(g));
    printf("%c\n", tolower(h));
    printf("%c\n", ft_tolower(h));

    printf("\n");

    // strings
    count = 0;
    while (s1[count] != '\0') {
        printf("%c", tolower(s1[count]));
        count++;
    }
    printf("\n");

    count = 0;
    while (s1[count] != '\0') {
        printf("%c", ft_tolower(s1[count]));
        count++;
    }

} */