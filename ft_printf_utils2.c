/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:36:40 by insoares          #+#    #+#             */
/*   Updated: 2024/05/09 17:44:18 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, const char c)
{
	char	*base;
	int		char_counter;

	char_counter = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		char_counter += ft_puthexa((n / 16), c);
		char_counter += ft_puthexa((n % 16), c);
	}
	else
		char_counter += write(1, &base[n], 1);
	return (char_counter);
}

int	ft_puthexaptr(unsigned long n)
{
	char	*base;
	int		char_counter;

	char_counter = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		char_counter += ft_puthexaptr((n / 16));
		char_counter += ft_puthexaptr((n % 16));
	}
	else
		char_counter += write(1, &base[n], 1);
	return (char_counter);
}

int	ft_putptr(unsigned long n)
{
	int	char_counter;

	char_counter = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	char_counter += write(1, "0x", 2);
	char_counter += ft_puthexaptr(n);
	return (char_counter);
}

int	ft_numlen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != '\0')
	{
		i++;
		n = (n / 10);
	}
	return (i);
}
