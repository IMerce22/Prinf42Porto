/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:39:47 by insoares          #+#    #+#             */
/*   Updated: 2024/05/09 16:45:03 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list ap)
{
	int		char_counter;
	char	p;

	char_counter = 0;
	p = '%';
	if (c == 'c')
		char_counter += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		char_counter += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		char_counter += ft_mputnbr(va_arg(ap, int));
	else if (c == 'u')
		char_counter += ft_mputunbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		char_counter += ft_puthexa(va_arg(ap, unsigned int), c);
	else if (c == 'p')
		char_counter += ft_putptr(va_arg(ap, unsigned long));
	else if (c == p)
		char_counter += write(1, &p, 1);
	else
		return (0);
	return (char_counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		char_counter;

	va_start(ap, format);
	i = 0;
	char_counter = 0;
	if (!format)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			char_counter += ft_format(format[i + 1], ap);
			i++;
		}
		else
			char_counter += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (char_counter);
}

/* int	main(void)
{
	//char	text2[] = "isto e uma string";
	//char	c;
	int		n;
	int*	ptr;

	//c = 'A';
	n = 48;
	ptr = &n;
	ft_printf("%p\n", ptr);
	//printf("%d\n", printf("%p\n", ptr));
	printf("%p\n", ptr);
	return (0);
} */