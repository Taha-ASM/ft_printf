/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:34:23 by tait-si           #+#    #+#             */
/*   Updated: 2026/11/01 18:55:04 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}
