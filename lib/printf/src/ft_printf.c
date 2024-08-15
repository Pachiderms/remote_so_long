/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:55:49 by tzizi             #+#    #+#             */
/*   Updated: 2024/06/04 06:55:51 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(const char c, va_list src)
{
	if (c == 's')
		return (ft_printstr(ft_strdup(va_arg(src, char *))));
	else if (c == 'd' || c == 'i')
		return (ft_printstr(ft_itoa(va_arg(src, int))));
	else if (c == 'u')
		return (ft_printstr(ft_itoau(va_arg(src, unsigned int))));
	else if (c == 'c')
		ft_putchar_fd(va_arg(src, int), 1);
	else if (c == 'x')
		return (ft_printstr(
				ft_itoax(va_arg(src, long), "0123456789abcdef")));
	else if (c == 'X')
		return (ft_printstr(
				ft_itoax(va_arg(src, long), "0123456789ABCDEF")));
	else if (c == 'p')
		return (ft_printstr(ft_printptr(va_arg(src, unsigned long long))));
	else
		ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		retval;

	retval = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			retval += ft_convert(*(str + 1), ap);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			retval += 1;
		}
		str++;
	}
	va_end(ap);
	return (retval);
}
