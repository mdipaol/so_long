/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <mdi-paol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:20:58 by mdi-paol          #+#    #+#             */
/*   Updated: 2022/12/12 15:49:19 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		k;

	i = 0;
	k = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			k = k + ft_checkformat(args, format + i + 1);
			i = i + 2;
		}
		else
		{
			k = k + write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (k);
}
