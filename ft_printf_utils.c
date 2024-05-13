/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:14:21 by insoares          #+#    #+#             */
/*   Updated: 2024/05/09 17:43:48 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	char_counter;

	char_counter = 0;
	char_counter += write(1, &c, 1);
	return (char_counter);
}

int	ft_putstr(char *s)
{
	int	i;
	int	char_counter;

	i = 0;
	char_counter = 0;
	while (s[i] != '\0')
	{
		char_counter += (write(1, &s[i], 1));
		i++;
	}
	return (char_counter);
}

int	ft_mputnbr(int n)
{
	int	char_counter;

	char_counter = 0;
	if (n == -2147483648)
	{
		char_counter += write(1, "-2147483648", 11);
		return (char_counter);
	}
	if (n < 0)
	{
		char_counter += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		char_counter += ft_mputnbr(n / 10);
		char_counter += ft_mputnbr(n % 10);
	}
	else
		char_counter += ft_putchar(n + '0');
	return (char_counter);
}

int	ft_mputunbr(unsigned int n)
{
	int		nlen;
	char	*str;
	int		char_counter;

	char_counter = 0;
	nlen = ft_numlen(n);
	str = (char *)malloc((sizeof(char) * (nlen + 1)));
	if (!str)
	{
		free (str);
		return (0);
	}
	str[nlen] = '\0';
	if (n == 0)
		str[0] = '0';
	while (nlen)
	{
		nlen--;
		str[nlen] = (n % 10) + 48;
		n = (n / 10);
	}
	char_counter += ft_putstr(str);
	free (str);
	return (char_counter);
}
