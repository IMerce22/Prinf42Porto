/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:09:55 by insoares          #+#    #+#             */
/*   Updated: 2024/05/09 16:28:59 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_mputnbr(int n);
int	ft_mputunbr(unsigned int n);
int	ft_puthexa(unsigned int n, const char c);
int	ft_putptr(unsigned long n);
int	ft_putptrhexa(unsigned long n, const char c);
int	ft_numlen(unsigned int n);

#endif