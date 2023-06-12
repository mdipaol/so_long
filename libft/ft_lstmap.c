/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:27:21 by mdi-paol          #+#    #+#             */
/*   Updated: 2022/10/19 17:01:33 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmpn;
	t_list	*new;

	new = 0;
	tmp = lst;
	if (tmp)
	{
		new = ft_lstnew((*f)(tmp->content));
		if (!new)
			ft_lstclear(&new, (*del));
		else
			ft_lstadd_back(&new, new);
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmpn = ft_lstnew((*f)(tmp->content));
		if (!tmpn)
			ft_lstclear(&tmpn, (*del));
		else
			ft_lstadd_back(&new, tmpn);
		tmp = tmp->next;
	}
	return (new);
}
