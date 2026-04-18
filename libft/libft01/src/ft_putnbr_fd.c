/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:26:25 by pang              #+#    #+#             */
/*   Updated: 2025/05/19 00:26:25 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putnbr_fd((nbr % 10), fd);
	}
	else
		ft_putchar_fd((nbr + '0'), fd);
}

/* #include <limits.h> // For INT_MIN and INT_MAX

int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1); // -2147483648
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);       // 0
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MAX, 1); // 2147483647
	ft_putchar_fd('\n', 1);
	return (0);
}
 */