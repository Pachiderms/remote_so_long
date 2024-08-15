/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:10:37 by tzizi             #+#    #+#             */
/*   Updated: 2024/06/18 13:33:34 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

char	*ft_printptr(unsigned long long n)
{
	if (n == 0)
		return (ft_strdup("(nil)"));
	else
	{
		return (ft_strjoinf(ft_strdup("0x"),
				ft_itoaf(n,
					"0123456789abcdef")));
	}
}
