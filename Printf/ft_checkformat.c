/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:46:48 by mdi-paol          #+#    #+#             */
/*   Updated: 2022/10/27 17:02:19 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkformat(va_list args, const char *format)
{
	int	k;

	k = 0;
	if (*format == 'c')
		k = k + ft_reading(va_arg(args, int));
	if (*format == 's')
		k = k + ft_printstr(va_arg(args, char *));
	if (*format == 'p')
		k = k + ft_printptr(va_arg(args, uintptr_t));
	if (*format == 'd' || *format == 'i')
		k = k + ft_printdi(va_arg(args, int));
	if (*format == 'u')
		k = k + ft_printu(va_arg(args, unsigned int));
	if (*format == 'x')
		k = k + ft_printx(va_arg(args, unsigned int));
	if (*format == 'X')
		k = k + ft_printics(va_arg(args, unsigned int));
	if (*format == '%')
		k = k + ft_reading('%');
	return (k);
}
