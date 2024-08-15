/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:38:33 by tzizi             #+#    #+#             */
/*   Updated: 2024/06/10 16:38:35 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	count_sizeu(unsigned int n)
{
	if (n / 10 == 0)
		return (1);
	else
	{
		return (1 + count_sizeu(n / 10));
	}
}

char	*ft_itoau(unsigned int n)
{
	int		size;
	char	*res;

	size = count_sizeu(n);
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res[size] = '\0';
	while (size > 0)
	{
		res[size - 1] = (n % 10) + 48;
		n /= 10;
		size--;
	}
	return (res);
}
