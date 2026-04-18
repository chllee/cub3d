/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:07:34 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 09:08:29 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void)
{
    char    c, d, e, f, g, h, i;

    // single character
    c = '\r';
    d = 'h';
    e = '1';
    f = '+';
    g = '\0';
    h = ' ';
	i = 'W';
    printf("isalnum: %i\n", isalnum(c));
    printf("ft_isalnum: %i\n", ft_isalnum(c));
    printf("isalnum: %i\n", isalnum(d));
    printf("ft_isalnum: %i\n", ft_isalnum(d));
    printf("isalnum: %i\n", isalnum(e));
    printf("ft_isalnum: %i\n", ft_isalnum(e));
    printf("isalnum: %i\n", isalnum(f));
    printf("ft_isalnum: %i\n", ft_isalnum(f));
    printf("isalnum: %i\n", isalnum(g));
    printf("ft_isalnum: %i\n", ft_isalnum(g));
    printf("isalnum: %i\n", isalnum(h));
    printf("ft_isalnum: %i\n", ft_isalnum(h));
	printf("isalnum: %i\n", isalnum(i));
    printf("ft_isalnum: %i\n", ft_isalnum(i));

    printf("\n");
    printf("\n");

    // A string
    char    s1[] = "1234567890";
    char    s2[] = "Just another string+";
    char    s3[] = "Justa?0therstr1ng";
	char	s4[] = "";
	char	s5[] = " ";
    int count;

    count = 0;

    // S1
    while (s1[count] != '\0')
    {
        if (!isalnum(s1[count]))
		{
            printf("isalnum s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("isalnum s1: 1\n");

	count = 0;

    while (s1[count] != '\0')
    {
        if (!ft_isalnum(s1[count]))
		{
            printf("ft_isalnum s1: 0\n");
			break ;
		}
        count++;
    }
	if (s1[count] == '\0')
    	printf("ft_isalnum s1: 1\n");

    printf("\n");

    // S2
	count = 0;
    while (s2[count] != '\0')
    {
        if (!isalnum(s2[count]))
		{
            printf("isalnum s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
	    printf("isalnum s2: 1\n");

	count = 0;
    while (s2[count] != '\0')
    {
        if (!ft_isalnum(s2[count]))
		{
            printf("ft_isalnum s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
   		printf("ft_isalnum s2: 1\n");

    printf("\n");
    
    // S3
	count = 0;
    while (s3[count] != '\0')
    {
        if (!isalnum(s3[count]))
		{
            printf("isalnum s3: 0\n");
			break;
		}
        count++;
    }
	if (s3[count] == '\0')
    	printf("isalnum s3: 1\n");

	count = 0;
    while (s3[count] != '\0')
    {
        if (!ft_isalnum(s3[count]))
		{
            printf("ft_isalnum s3: 0\n");
			break ;
		}
        count++;
    }
	if (s3[count] == '\0')
   		printf("ft_isalnum s3: 1\n");

	printf("\n");

	// S3 test
	printf("isalnum s3[5]: %i\n", isalnum(s3[5]));
	printf("isalnum s3[6]: %i\n", isalnum(s3[6]));
	printf("ft_isalnum s3[5]: %i\n", ft_isalnum(s3[5]));
	printf("ft_isalnum s3[6]: %i\n", ft_isalnum(s3[6]));

	printf("\n");

	// S4 test
	count = 0;
    while (s4[count] != '\0')
    {
        if (!isalnum(s4[count]))
		{
            printf("isalnum s4: 0\n");
			break;
		}
        count++;
    }
	if (s4[count] == '\0')
    	printf("isalnum s4: 1\n");

	count = 0;
    while (s4[count] != '\0')
    {
        if (!ft_isalnum(s4[count]))
		{
            printf("ft_isalnum s4: 0\n");
			break ;
		}
        count++;
    }
	if (s4[count] == '\0')
   		printf("ft_isalnum s4: 1\n");

	printf("\n");

	// S5 test
	count = 0;
    while (s5[count] != '\0')
    {
        if (!isalnum(s5[count]))
		{
            printf("isalnum s5: 0\n");
			break;
		}
        count++;
    }
	if (s5[count] == '\0')
    	printf("isalnum s5: 1\n");

	count = 0;
    while (s5[count] != '\0')
    {
        if (!ft_isalnum(s5[count]))
		{
            printf("ft_isalnum s5: 0\n");
			break ;
		}
        count++;
    }
	if (s5[count] == '\0')
   		printf("ft_isalnum s5: 1\n");

    return (0);
}
 */