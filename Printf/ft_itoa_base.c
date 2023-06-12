/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <mdi-paol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:05:16 by mdi-paol          #+#    #+#             */
/*   Updated: 2022/12/12 15:49:31 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checklenght(char *base_to, uintptr_t ptr)
{
	uintptr_t	size;
	int			x;

	x = 0;
	size = ft_sstrlen(base_to);
	while (ptr >= size)
	{
		ptr = ptr / size;
		x++;
	}
	x++;
	return (x);
}

char	*ft_itoa_base(char *base_to, uintptr_t ptr)
{
	char	*s;
	int		lenght;
	int		size;

	size = ft_sstrlen(base_to);
	lenght = ft_checklenght(base_to, ptr);
	s = (char *)malloc(sizeof(char) * (lenght + 1));
	if (s == 0)
		return (NULL);
	s[lenght] = '\0';
	lenght--;
	while (ptr > 0)
	{
		s[lenght] = base_to[ptr % size];
		ptr = ptr / size;
		lenght--;
	}
	return (s);
}
