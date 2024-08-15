/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:18:06 by tzizi             #+#    #+#             */
/*   Updated: 2024/06/06 14:18:07 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	count_sizef(unsigned long long n)
{
	if (n / 16 == 0)
		return (1);
	else
	{
		return (1 + count_sizef(n / 16));
	}
}

char	*ft_itoaf(unsigned long long n, char *base)
{
	char	*res;
	int		size;

	res = NULL;
	size = count_sizef(n);
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res[size] = '\0';
	while (size > 0)
	{
		res[size - 1] = base[n % 16];
		n /= 16;
		size--;
	}
	return (res);
}

char	*ft_itoax(long n, char *base)
{
	char			*res;
	int				size;
	unsigned int	nb;

	nb = (unsigned int)n;
	size = count_sizef(nb);
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res[size] = '\0';
	while (size > 0)
	{
		res[size - 1] = base[nb % 16];
		nb /= 16;
		size--;
	}
	return (res);
}
