/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:17:13 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 09:17:16 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void)
{
    char    c, d, e, f, g, h;

    // single character
    c = '\r';
    d = 'h';
    e = '1';
    f = '+';
    g = '\0';
    h = ' ';
    printf("isdigit: %i\n", isdigit(c));
    printf("ft_isdigit: %i\n", ft_isdigit(c));
    printf("isdigit: %i\n", isdigit(d));
    printf("ft_isdigit: %i\n", ft_isdigit(d));
    printf("isdigit: %i\n", isdigit(e));
    printf("ft_isdigit: %i\n", ft_isdigit(e));
    printf("isdigit: %i\n", isdigit(f));
    printf("ft_isdigit: %i\n", ft_isdigit(f));
    printf("isdigit: %i\n", isdigit(g));
    printf("ft_isdigit: %i\n", ft_isdigit(g));
    printf("isdigit: %i\n", isdigit(h));
    printf("ft_isdigit: %i\n", ft_isdigit(h));

    printf("\n");
    printf("\n");

    // A string
    char    s1[] = "1234567890";
    char    s2[] = "Just another string";
    char    s3[] = "Justan0therstr1ng";
	char	s4[] = "";
	char	s5[] = " ";
    int count;

    count = 0;

    // S1
    while (s1[count] != '\0')
    {
        if (!isdigit(s1[count]))
		{
            printf("isdigit s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("isdigit s1: 1\n");

	count = 0;

    while (s1[count] != '\0')
    {
        if (!ft_isdigit(s1[count]))
		{
            printf("ft_isdigit s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("ft_isdigit s1: 1\n");

    printf("\n");

    // S2
	count = 0;
    while (s2[count] != '\0')
    {
        if (!isdigit(s2[count]))
		{
            printf("isdigit s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
	    printf("isdigit s2: 1\n");

	count = 0;
    while (s2[count] != '\0')
    {
        if (!ft_isdigit(s2[count]))
		{
            printf("ft_isdigit s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
   		printf("ft_isdigit s2: 1\n");

    printf("\n");
    
    // S3
	count = 0;
    while (s3[count] != '\0')
    {
        if (!isdigit(s3[count]))
		{
            printf("isdigit s3: 0\n");
			break;
		}
        count++;
    }
	if (s3[count] == '\0')
    	printf("isdigit s3: 1\n");

	count = 0;
    while (s3[count] != '\0')
    {
        if (!ft_isdigit(s3[count]))
		{
            printf("ft_isdigit s3: 0\n");
			break ;
		}
        count++;
    }
	if (s3[count] == '\0')
   		printf("ft_isdigit s3: 1\n");

	printf("\n");

	// S3 test
	printf("isdigit s3[5]: %i\n", isdigit(s3[5]));
	printf("isdigit s3[6]: %i\n", isdigit(s3[6]));
	printf("ft_isdigit s3[5]: %i\n", ft_isdigit(s3[5]));
	printf("ft_isdigit s3[6]: %i\n", ft_isdigit(s3[6]));

	printf("\n");

	// S4 test
	count = 0;
    while (s4[count] != '\0')
    {
        if (!isdigit(s4[count]))
		{
            printf("isdigit s4: 0\n");
			break;
		}
        count++;
    }
	if (s4[count] == '\0')
    	printf("isdigit s4: 1\n");

	count = 0;
    while (s4[count] != '\0')
    {
        if (!ft_isdigit(s4[count]))
		{
            printf("ft_isdigit s4: 0\n");
			break ;
		}
        count++;
    }
	if (s4[count] == '\0')
   		printf("ft_isdigit s4: 1\n");

	printf("\n");

	// S5 test
	count = 0;
    while (s5[count] != '\0')
    {
        if (!isdigit(s5[count]))
		{
            printf("isdigit s5: 0\n");
			break;
		}
        count++;
    }
	if (s5[count] == '\0')
    	printf("isdigit s5: 1\n");

	count = 0;
    while (s5[count] != '\0')
    {
        if (!ft_isdigit(s5[count]))
		{
            printf("ft_isdigit s5: 0\n");
			break ;
		}
        count++;
    }
	if (s5[count] == '\0')
   		printf("ft_isdigit s5: 1\n");

    return (0);
}
 */