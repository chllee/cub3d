/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:29:21 by pang              #+#    #+#             */
/*   Updated: 2025/05/30 15:05:00 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_nbr(va_list args)
{
	int		nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	return (nbr_len(nbr));
}

static int	nbr_len_unsign(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_put_unsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_put_unsigned_fd(n / 10, fd);
		ft_put_unsigned_fd(n % 10, fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}

int	print_unsign(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	ft_put_unsigned_fd(nbr, 1);
	return (nbr_len_unsign(nbr));
}
