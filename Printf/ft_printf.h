/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:20:50 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 20:04:12 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_checkformat(va_list args, const char *format);
void	ft_putchar(char c);
int		ft_reading(char c);
int		ft_printstr(char *s);
size_t	ft_sstrlen(char *str);
int		ft_printptr(uintptr_t ptr);
char	*ft_itoa_base(char *base_to, uintptr_t ptr);
int		ft_printdi(int di);
int		ft_printdi1(char *s, int i);
int		ft_printu(unsigned int u);
int		ft_printx(unsigned int x);
int		ft_printics(unsigned int X);

#endif
