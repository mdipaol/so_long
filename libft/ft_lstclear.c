/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:00:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2022/10/17 15:05:14 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*d;

	tmp = *lst;
	while (tmp != 0)
	{
		d = tmp;
		tmp = tmp->next;
		(*del)(d->content);
		free(d);
	}
	*lst = 0;
}
