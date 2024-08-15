/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:12:19 by tzizi             #+#    #+#             */
/*   Updated: 2024/06/10 13:12:20 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	l;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		free(str);
		return (6);
	}
	else
	{
		ft_putstr_fd(str, 1);
		l = ft_strlen(str);
		free(str);
		return (l);
	}
}
