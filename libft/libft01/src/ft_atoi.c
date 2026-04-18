/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:00:41 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 18:24:07 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		count;
	int		sign;
	long	nbr;

	count = 0;
	sign = 1;
	nbr = 0;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 13))
	{
		count++;
	}
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		nbr = (nbr * 10) + (str[count] - '0');
		count++;
	}
	return (nbr * sign);
}

/* #include <stdlib.h>
#include <stdio.h>

int main(void)
{
    printf("Empty string\n");
    printf("%d\n", atoi(""));
    printf("%d\n", ft_atoi(""));
    printf("\n");

    printf("\\t\n");
    printf("%d\n", atoi("\t"));
    printf("%d\n", ft_atoi("\t"));
    printf("\n");

    printf("- sign\n");
    printf("%d\n", atoi("-"));
    printf("%d\n", ft_atoi("-"));
    printf("\n");

    printf("123\n");
    printf("%d\n", atoi("123"));
    printf("%d\n", ft_atoi("123"));
    printf("\n");

    printf("   -1234ab567\n");
    printf("%d\n", atoi("  -1234ab567"));
    printf("%d\n", ft_atoi("  -1234ab567"));
    printf("\n");

    printf("-42\n");
    printf("%d\n", atoi("-42"));
    printf("%d\n", ft_atoi("-42"));
    printf("\n");

    printf("   --00123abc\n");
    printf("%d\n", atoi("  --00123abc"));
    printf("%d\n", ft_atoi("  --00123abc"));
    printf("\n");

    printf("   987\n");
    printf("%d\n", atoi("   987"));
    printf("%d\n", ft_atoi("   987"));
    printf("\n");

    printf("abc123\n");
    printf("%d\n", atoi("abc123"));
    printf("%d\n", ft_atoi("abc123"));
} */
