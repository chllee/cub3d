/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:16:48 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 09:16:57 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void)
{
    char    c, d, e, f, g, h;
	int	i;

    // single character
    c = '\r';
    d = 'h';
    e = '1';
    f = '+';
    g = '\0';
    h = ' ';
	i = 129;
    printf("isascii: %i\n", isascii(c));
    printf("ft_isascii: %i\n", ft_isascii(c));
    printf("isascii: %i\n", isascii(d));
    printf("ft_isascii: %i\n", ft_isascii(d));
    printf("isascii: %i\n", isascii(e));
    printf("ft_isascii: %i\n", ft_isascii(e));
    printf("isascii: %i\n", isascii(f));
    printf("ft_isascii: %i\n", ft_isascii(f));
    printf("isascii: %i\n", isascii(g));
    printf("ft_isascii: %i\n", ft_isascii(g));
    printf("isascii: %i\n", isascii(h));
    printf("ft_isascii: %i\n", ft_isascii(h));
	printf("isascii: %i\n", isascii(i));
    printf("ft_isascii: %i\n", ft_isascii(i));

    printf("\n");
    printf("\n");

    // A string
    char    s1[] = "1234567890";
    char    s2[] = "Just another string";
    char    s3[] = "Justan0therstr1ng";
	char	s4[] = "";
	char	s5[] = " ";
	char	s6[] = "\n\r\t";
    int count;

    count = 0;

    // S1
    while (s1[count] != '\0')
    {
        if (!isascii(s1[count]))
		{
            printf("isascii s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("isascii s1: 1\n");

	count = 0;

    while (s1[count] != '\0')
    {
        if (!ft_isascii(s1[count]))
		{
            printf("ft_isascii s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("ft_isascii s1: 1\n");

    printf("\n");

    // S2
	count = 0;
    while (s2[count] != '\0')
    {
        if (!isascii(s2[count]))
		{
            printf("isascii s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
	    printf("isascii s2: 1\n");

	count = 0;
    while (s2[count] != '\0')
    {
        if (!ft_isascii(s2[count]))
		{
            printf("ft_isascii s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
   		printf("ft_isascii s2: 1\n");

    printf("\n");
    
    // S3
	count = 0;
    while (s3[count] != '\0')
    {
        if (!isascii(s3[count]))
		{
            printf("isascii s3: 0\n");
			break;
		}
        count++;
    }
	if (s3[count] == '\0')
    	printf("isascii s3: 1\n");

	count = 0;
    while (s3[count] != '\0')
    {
        if (!ft_isascii(s3[count]))
		{
            printf("ft_isascii s3: 0\n");
			break ;
		}
        count++;
    }
	if (s3[count] == '\0')
   		printf("ft_isascii s3: 1\n");

	printf("\n");

	// S3 test
	printf("isascii s3[5]: %i\n", isascii(s3[5]));
	printf("isascii s3[6]: %i\n", isascii(s3[6]));
	printf("ft_isascii s3[5]: %i\n", ft_isascii(s3[5]));
	printf("ft_isascii s3[6]: %i\n", ft_isascii(s3[6]));

	printf("\n");

	// S4 test
	count = 0;
    while (s4[count] != '\0')
    {
        if (!isascii(s4[count]))
		{
            printf("isascii s4: 0\n");
			break;
		}
        count++;
    }
	if (s4[count] == '\0')
    	printf("isascii s4: 1\n");

	count = 0;
    while (s4[count] != '\0')
    {
        if (!ft_isascii(s4[count]))
		{
            printf("ft_isascii s4: 0\n");
			break ;
		}
        count++;
    }
	if (s4[count] == '\0')
   		printf("ft_isascii s4: 1\n");

	printf("\n");

	// S5 test
	count = 0;
    while (s5[count] != '\0')
    {
        if (!isascii(s5[count]))
		{
            printf("isascii s5: 0\n");
			break;
		}
        count++;
    }
	if (s5[count] == '\0')
    	printf("isascii s5: 1\n");

	count = 0;
    while (s5[count] != '\0')
    {
        if (!ft_isascii(s5[count]))
		{
            printf("ft_isascii s5: 0\n");
			break ;
		}
        count++;
    }
	if (s5[count] == '\0')
   		printf("ft_isascii s5: 1\n");
	
	printf("\n");

	// S6 test
	count = 0;
    while (s6[count] != '\0')
    {
        if (!isascii(s6[count]))
		{
            printf("isascii s6: 0\n");
			break;
		}
        count++;
    }
	if (s6[count] == '\0')
    	printf("isascii s6: 1\n");

	count = 0;
    while (s6[count] != '\0')
    {
        if (!ft_isascii(s6[count]))
		{
            printf("ft_isascii s6: 0\n");
			break ;
		}
        count++;
    }
	if (s6[count] == '\0')
   		printf("ft_isascii s6: 1\n");

    return (0);
} */
