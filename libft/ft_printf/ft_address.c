/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:29:21 by pang              #+#    #+#             */
/*   Updated: 2025/05/30 15:12:23 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	addptr_len(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static void	convert_hex_ptr(uintptr_t nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		convert_hex_ptr(nb / 16);
	ft_putchar_fd(hex[nb % 16], 1);
}

int	print_add(va_list args)
{
	uintptr_t	nbr;
	int			len;

	nbr = (uintptr_t)va_arg(args, void *);
	if (nbr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		convert_hex_ptr(nbr);
	}
	len = addptr_len(nbr);
	return (len +2);
}
