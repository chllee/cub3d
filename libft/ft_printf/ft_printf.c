/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:46:43 by pang              #+#    #+#             */
/*   Updated: 2025/05/30 15:22:50 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_funct(const char *format, va_list args)
{
	if (*format == 'c')
		return (print_char(args));
	else if (*format == 's')
		return (print_str(args));
	else if ((*format == 'i') || (*format == 'd'))
		return (print_nbr(args));
	else if (*format == 'u')
		return (print_unsign(args));
	else if (*format == 'x')
		return (print_hex(args));
	else if (*format == 'X')
		return (print_upphex(args));
	else if (*format == 'p')
		return (print_add(args));
	else
	{
		(ft_putchar_fd(*format, 1));
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format +1))
		{
			format++;
			len += check_funct(format, args);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
