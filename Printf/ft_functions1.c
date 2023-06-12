/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:01:04 by mdi-paol          #+#    #+#             */
/*   Updated: 2022/10/27 17:04:58 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdi1(char *s, int i)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		write(1, &s[x], 1);
		i++;
		x++;
	}
	return (i);
}

int	ft_printdi(int di)
{
	int		i;
	char	*s;

	i = 0;
	if (di == 0)
	{
		write(1, "0", 1);
		i++;
		return (i);
	}
	if (di == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (di < 0)
	{
		di = -di;
		write(1, "-", 1);
		i++;
	}
	s = ft_itoa_base("0123456789", di);
	i = ft_printdi1(s, i);
	free (s);
	return (i);
}

int	ft_printu(unsigned int u)
{
	int		i;
	char	*s;
	int		x;

	x = 0;
	i = 0;
	if (u == 0)
	{
		write(1, "0", 1);
		i++;
		return (i);
	}
	s = ft_itoa_base("0123456789", u);
	while (s[x] != '\0')
	{
		write(1, &s[x], 1);
		i++;
		x++;
	}
	free (s);
	return (i);
}

int	ft_printx(unsigned int x)
{
	int		i;
	char	*s;
	int		y;

	y = 0;
	i = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		i++;
		return (i);
	}
	s = ft_itoa_base("0123456789abcdef", x);
	while (s[y] != '\0')
	{
		write (1, &s[y], 1);
		i++;
		y++;
	}
	free (s);
	return (i);
}

int	ft_printics(unsigned int ics)
{
	int		i;
	char	*s;
	int		y;

	y = 0;
	i = 0;
	if (ics == 0)
	{
		write(1, "0", 1);
		i++;
		return (i);
	}
	s = ft_itoa_base("0123456789ABCDEF", ics);
	while (s[y] != '\0')
	{
		write (1, &s[y], 1);
		i++;
		y++;
	}
	free (s);
	return (i);
}
