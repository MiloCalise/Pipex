/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:40:14 by milo              #+#    #+#             */
/*   Updated: 2025/05/21 14:35:09 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_stash(char *stash)
{
	if (!stash || !*stash)
	{
		stash = malloc(BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	return (stash);
}
