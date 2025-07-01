/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:00:44 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/05 17:34:26 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dup;
	t_list	*elem;
	void	*cont;

	dup = NULL;
	while (lst)
	{
		cont = f(lst->content);
		elem = ft_lstnew(cont);
		if (!elem)
		{
			if (cont)
				del(cont);
			ft_lstclear(&dup, del);
			return (NULL);
		}
		ft_lstadd_back(&dup, elem);
		lst = lst->next;
	}
	return (dup);
}
