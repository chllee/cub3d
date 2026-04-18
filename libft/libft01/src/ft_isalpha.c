/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:09:25 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 09:09:42 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void)
{
    char    c, d, e, f, g, h, i;

    // single character
    c = 'A';
    d = 'h';
    e = '1';
    f = '+';
    g = '\0';
    h = ' ';
	i = 123;
    printf("isalpha: %i\n", isalpha(c));
    printf("ft_isalpha: %i\n", ft_isalpha(c));
    printf("isalpha: %i\n", isalpha(d));
    printf("ft_isalpha: %i\n", ft_isalpha(d));
    printf("isalpha: %i\n", isalpha(e));
    printf("ft_isalpha: %i\n", ft_isalpha(e));
    printf("isalpha: %i\n", isalpha(f));
    printf("ft_isalpha: %i\n", ft_isalpha(f));
    printf("isalpha: %i\n", isalpha(g));
    printf("ft_isalpha: %i\n", ft_isalpha(g));
    printf("isalpha: %i\n", isalpha(h));
    printf("ft_isalpha: %i\n", ft_isalpha(h));
	printf("isalpha: %i\n", isalpha(i));
    printf("ft_isalpha: %i\n", ft_isalpha(i));

    printf("\n");
    printf("\n");

    // A string
    char    s1[] = "Justanotherstring";
    char    s2[] = "Just another string";
    char    s3[] = "Justan0therstr1ng";
	char	s4[] = "";
	char	s5[] = " ";
    int count;

    count = 0;

    // S1
    while (s1[count] != '\0')
    {
        if (!isalpha(s1[count]))
            printf("isalpha s1: 0\n");
        count++;
    }
	if (s1[count] == '\0')
    	printf("isalpha s1: 1\n");

	count = 0;

    while (s1[count] != '\0')
    {
        if (!ft_isalpha(s1[count]))
            printf("ft_isalpha s1: 0\n");
        count++;
    }
	if (s1[count] == '\0')
    	printf("ft_isalpha s1: 1\n");

    printf("\n");

    // S2
	count = 0;
    while (s2[count] != '\0')
    {
        if (!isalpha(s2[count]))
		{
            printf("isalpha s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
	    printf("isalpha s2: 1\n");

	count = 0;
    while (s2[count] != '\0')
    {
        if (!ft_isalpha(s2[count]))
		{
            printf("ft_isalpha s2: 0\n");
			break ;
		}
        count++;
    }
	if (s2[count] == '\0')
   		printf("ft_isalpha s2: 1\n");

    printf("\n");
    
    // S3
	count = 0;
    while (s3[count] != '\0')
    {
        if (!isalpha(s3[count]))
		{
            printf("isalpha s3: 0\n");
			break;
		}
        count++;
    }
	if (s3[count] == '\0')
    	printf("isalpha s3: 1\n");

	count = 0;
    while (s3[count] != '\0')
    {
        if (!ft_isalpha(s3[count]))
		{
            printf("ft_isalpha s3: 0\n");
			break ;
		}
        count++;
    }
	if (s3[count] == '\0')
   		printf("ft_isalpha s3: 1\n");

	printf("\n");

	// S3 test
	printf("isalpha s3[5]: %i\n", isalpha(s3[5]));
	printf("isalpha s3[6]: %i\n", isalpha(s3[6]));
	printf("ft_isalpha s3[5]: %i\n", ft_isalpha(s3[5]));
	printf("ft_isalpha s3[6]: %i\n", ft_isalpha(s3[6]));

	printf("\n");

	// S4 test
	count = 0;
    while (s4[count] != '\0')
    {
        if (!isalpha(s4[count]))
		{
            printf("isalpha s4: 0\n");
			break;
		}
        count++;
    }
	if (s4[count] == '\0')
    	printf("isalpha s4: 1\n");

	count = 0;
    while (s4[count] != '\0')
    {
        if (!ft_isalpha(s4[count]))
		{
            printf("ft_isalpha s4: 0\n");
			break ;
		}
        count++;
    }
	if (s4[count] == '\0')
   		printf("ft_isalpha s4: 1\n");

	printf("\n");

	// S5 test
	count = 0;
    while (s5[count] != '\0')
    {
        if (!isalpha(s5[count]))
		{
            printf("isalpha s5: 0\n");
			break;
		}
        count++;
    }
	if (s5[count] == '\0')
    	printf("isalpha s5: 1\n");

	count = 0;
    while (s5[count] != '\0')
    {
        if (!ft_isalpha(s5[count]))
		{
            printf("ft_isalpha s5: 0\n");
			break ;
		}
        count++;
    }
	if (s5[count] == '\0')
   		printf("ft_isalpha s5: 1\n");

    return (0);
}
 */