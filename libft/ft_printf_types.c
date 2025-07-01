/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:51:01 by milo              #+#    #+#             */
/*   Updated: 2025/05/21 14:38:18 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_c(va_list params)
{
	char	c;

	c = (char)va_arg(params, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	type_di(va_list params)
{
	int	i;
	int	j;

	i = va_arg(params, int);
	j = size_calcu(i);
	ft_putnbr_fd(i, 1);
	return (j);
}

int	type_s(va_list params)
{
	char	*dup;
	int		i;

	dup = va_arg(params, char *);
	if (!dup)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(dup);
	ft_putstr_fd(dup, 1);
	return (i);
}

int	type_u(va_list params)
{
	unsigned int	i;
	int				j;

	i = va_arg(params, unsigned int);
	j = size_calcu(i);
	ft_put_unsigned_nbr(i);
	return (j);
}

int	type_p(va_list params)
{
	void			*arg;
	unsigned long	ptr;
	int				i;

	arg = va_arg(params, void *);
	if (arg == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ptr = (unsigned long)arg;
	ft_putstr_fd("0x", 1);
	i = 2;
	i = i + ft_putnbr_hex_adr(ptr);
	return (i);
}
