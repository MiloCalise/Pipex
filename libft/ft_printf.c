/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:49:20 by milo              #+#    #+#             */
/*   Updated: 2025/06/19 13:42:00 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'x' || c == 'u' || c == 'X'
		|| c == '%')
		return (1);
	return (0);
}

int	print_str(const char *format, va_list params)
{
	int	i;
	int	res;

	i = 0;
	res = i;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && check_char(format[i + 1]))
		{
			res = res + distrib(format[i + 1], params);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
			i++;
		}
	}
	return (res);
}

int	distrib(char type, va_list params)
{
	int	i;

	i = 0;
	if (type == 'c')
		i = type_c(params);
	if (type == 'd' || type == 'i')
		i = type_di(params);
	if (type == 'u')
		i = type_u(params);
	if (type == 's')
		i = type_s(params);
	if (type == 'p')
		i = type_p(params);
	if (type == 'x')
		i = type_x(params);
	if (type == 'X')
		i = type_xx(params);
	if (type == '%')
		i = type_percent();
	return (i);
}

int	check_format(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && check_char(format[i + 1] == 0))
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	count;

	if (!format)
		return (-1);
	count = 0;
	va_list(params);
	va_start(params, format);
	if (check_format(format) == 1)
	{
		va_end(params);
		return (0);
	}
	count = print_str(format, params);
	va_end(params);
	return (count);
}

// int	main(void)
// {
// 	int	bytes_written;
// 	int	real_bytes;
// 	bytes_written = ft_printf("  %s  \n" , "bonjour");
// 	real_bytes = printf("  %s  \n", "bonjour");
// 	printf("moi : %d\n", bytes_written);
// 	printf("vrai printf : %d\n", real_bytes);
// }
