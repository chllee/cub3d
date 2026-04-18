/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:04:14 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 17:43:51 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(long nbr)
{
	unsigned long	n;

	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	if (n < 10)
		return (1);
	return (1 + count_digit(n / 10));
}

char	*fill_str(char *arr, long n)
{
	unsigned long	num;
	int				len;
	int				count;
	int				index;

	len = count_digit(n);
	index = 0;
	if (n < 0)
	{
		arr[0] = '-';
		num = -n;
		index = 1;
	}
	else
		num = n;
	arr[len + index] = '\0';
	count = len + index - 1;
	while (count >= index)
	{
		arr[count] = (num % 10) + '0';
		num = num / 10;
		count--;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	long	nbr;

	nbr = (long)n;
	len = count_digit(nbr);
	if (nbr < 0)
		len += 1;
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	fill_str(arr, nbr);
	return (arr);
}

/* 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *ft_itoa(int n); // Your function prototype

void test(int n)
{
    char *result = ft_itoa(n);
    if (result)
    {
        printf("ft_itoa(%d) = \"%s\"\n", n, result);
        free(result);
    }
    else
        printf("ft_itoa(%d) = NULL\n", n);
}

int main(void)
{
    test(0);
    test(1);
    test(42);
    test(123456);
    test(-1);
    test(-42);
    test(-123456);
    test(INT_MAX);
    test(INT_MIN);
    test(9);
    test(-9);
    test(1000);
    return 0;
}
 */
