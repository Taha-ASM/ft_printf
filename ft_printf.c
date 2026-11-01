/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:15:25 by tait-si           #+#    #+#             */
/*   Updated: 2026/10/31 20:22:01 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_equal(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	if (c == 'p')
		count += ft_puthex(va_arg(list, void *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int));
	if (c == 'u')
		count += ft_unsigned(va_arg(list, unsigned int));
	if (c == 'x' || c == 'X')
		count += ft_hex(va_arg(list, unsigned int), c);
	if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += is_equal(format[i + 1], args);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
