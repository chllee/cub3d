/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:30:20 by pang              #+#    #+#             */
/*   Updated: 2025/05/30 15:12:56 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* %x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format. */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	convert_hex(unsigned int nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		convert_hex(nb / 16);
	ft_putchar_fd(hex[nb % 16], 1);
}

int	print_hex(va_list args)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(args, unsigned int);
	len = hex_len(nbr);
	convert_hex(nbr);
	return (len);
}

void	convert_upphex(unsigned int nb)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nb >= 16)
		convert_upphex(nb / 16);
	ft_putchar_fd(hex[nb % 16], 1);
}

int	print_upphex(va_list args)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(args, unsigned int);
	len = hex_len(nbr);
	convert_upphex(nbr);
	return (len);
}
