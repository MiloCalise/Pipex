/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:02:48 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/23 13:05:07 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dst;

	dst = (t_list *)malloc(sizeof(t_list));
	if (!dst)
		return (NULL);
	dst->content = content;
	dst->next = NULL;
	return (dst);
}
