/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:37:54 by tait-si           #+#    #+#             */
/*   Updated: 2026/10/31 20:22:43 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_helper(unsigned long long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += hex_helper(n / 16);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	ft_puthex(void *p)
{
	int					count;
	unsigned long long	addr;

	count = 0;
	if (p == NULL)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	addr = (unsigned long long)p;
	count += write(1, "0x", 2);
	count += hex_helper(addr);
	return (count);
}
