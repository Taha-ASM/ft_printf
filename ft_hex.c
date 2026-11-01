/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:50:43 by tait-si           #+#    #+#             */
/*   Updated: 2026/10/31 19:58:19 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else if (c == 'x')
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_hex(n / 16, c);
	count += write(1, &hex[n % 16], 1);
	return (count);
}
