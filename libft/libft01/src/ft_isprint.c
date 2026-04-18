/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:17:23 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 09:18:11 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void)
{
    char    c, d, e, f, g, h, i, j, k, l;

    // single character
    c = '\r';
    d = 'h';
    e = '1';
    f = '+';
    g = '\0';
    h = ' ';
	i = 127;
	j = 31;
	k = 32;
	l = 126;
    printf("isprint: %i\n", isprint(c));
    printf("ft_isprint: %i\n", ft_isprint(c));
    printf("isprint: %i\n", isprint(d));
    printf("ft_isprint: %i\n", ft_isprint(d));
    printf("isprint: %i\n", isprint(e));
    printf("ft_isprint: %i\n", ft_isprint(e));
    printf("isprint: %i\n", isprint(f));
    printf("ft_isprint: %i\n", ft_isprint(f));
    printf("isprint: %i\n", isprint(g));
    printf("ft_isprint: %i\n", ft_isprint(g));
    printf("isprint: %i\n", isprint(h));
    printf("ft_isprint: %i\n", ft_isprint(h));
	printf("isprint: %i\n", isprint(i));
    printf("ft_isprint: %i\n", ft_isprint(i));
	printf("isprint: %i\n", isprint(j));
    printf("ft_isprint: %i\n", ft_isprint(j));
	printf("isprint: %i\n", isprint(k));
    printf("ft_isprint: %i\n", ft_isprint(k));
	printf("isprint: %i\n", isprint(l));
    printf("ft_isprint: %i\n", ft_isprint(l));

    printf("\n");
    printf("\n");

    // A string
    char    s1[] = "1234567890";
    char    s2[] = "Just another\nstring";
    char    s3[] = "Justan0therstr1ng";
	char	s4[] = "";
	char	s5[] = " ";
	char	s6[] = "\n\r\t";
    int count;

    count = 0;

    // S1
    while (s1[count] != '\0')
    {
        if (!isprint(s1[count]))
		{
            printf("isprint s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("isprint s1: 1\n");

	count = 0;

    while (s1[count] != '\0')
    {
        if (!ft_isprint(s1[count]))
		{
            printf("ft_isprint s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("ft_isprint s1: 1\n");

    printf("\n");

    // S2
	count = 0;
    while (s2[count] != '\0')
    {
        if (!isprint(s2[count]))
		{
            printf("isprint s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
	    printf("isprint s2: 1\n");

	count = 0;
    while (s2[count] != '\0')
    {
        if (!ft_isprint(s2[count]))
		{
            printf("ft_isprint s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
   		printf("ft_isprint s2: 1\n");

    printf("\n");
    
    // S3
	count = 0;
    while (s3[count] != '\0')
    {
        if (!isprint(s3[count]))
		{
            printf("isprint s3: 0\n");
			break;
		}
        count++;
    }
	if (s3[count] == '\0')
    	printf("isprint s3: 1\n");

	count = 0;
    while (s3[count] != '\0')
    {
        if (!ft_isprint(s3[count]))
		{
            printf("ft_isprint s3: 0\n");
			break ;
		}
        count++;
    }
	if (s3[count] == '\0')
   		printf("ft_isprint s3: 1\n");

	printf("\n");

	// S3 test
	printf("isprint s3[5]: %i\n", isprint(s3[5]));
	printf("isprint s3[6]: %i\n", isprint(s3[6]));
	printf("ft_isprint s3[5]: %i\n", ft_isprint(s3[5]));
	printf("ft_isprint s3[6]: %i\n", ft_isprint(s3[6]));

	printf("\n");

	// S4 test
	count = 0;
    while (s4[count] != '\0')
    {
        if (!isprint(s4[count]))
		{
            printf("isprint s4: 0\n");
			break;
		}
        count++;
    }
	if (s4[count] == '\0')
    	printf("isprint s4: 1\n");

	count = 0;
    while (s4[count] != '\0')
    {
        if (!ft_isprint(s4[count]))
		{
            printf("ft_isprint s4: 0\n");
			break ;
		}
        count++;
    }
	if (s4[count] == '\0')
   		printf("ft_isprint s4: 1\n");

	printf("\n");

	// S5 test
	count = 0;
    while (s5[count] != '\0')
    {
        if (!isprint(s5[count]))
		{
            printf("isprint s5: 0\n");
			break;
		}
        count++;
    }
	if (s5[count] == '\0')
    	printf("isprint s5: 1\n");

	count = 0;
    while (s5[count] != '\0')
    {
        if (!ft_isprint(s5[count]))
		{
            printf("ft_isprint s5: 0\n");
			break ;
		}
        count++;
    }
	if (s5[count] == '\0')
   		printf("ft_isprint s5: 1\n");
	
	printf("\n");

	// S6 test
	count = 0;
    while (s6[count] != '\0')
    {
        if (!isprint(s6[count]))
		{
            printf("isprint s6: 0\n");
			break;
		}
        count++;
    }
	if (s6[count] == '\0')
    	printf("isprint s6: 1\n");

	count = 0;
    while (s6[count] != '\0')
    {
        if (!ft_isprint(s6[count]))
		{
            printf("ft_isprint s6: 0\n");
			break ;
		}
        count++;
    }
	if (s6[count] == '\0')
   		printf("ft_isprint s6: 1\n");

    return (0);
}
 */