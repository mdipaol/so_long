/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:50:21 by mdi-paol          #+#    #+#             */
/*   Updated: 2022/10/27 16:57:17 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(uintptr_t ptr)
{
	int		i;
	int		x;
	char	*s;

	x = 0;
	i = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	s = ft_itoa_base("0123456789abcdef", ptr);
	i = i + write(1, "0x", 2);
	while (s[x] != '\0')
	{
		write(1, &s[x], 1);
		i++;
		x++;
	}
	free (s);
	return (i);
}
