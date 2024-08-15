/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:58:25 by tzizi             #+#    #+#             */
/*   Updated: 2024/05/30 14:42:47 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*_s;

	i = ft_strlen(s);
	_s = (unsigned char *)s;
	while (i >= 0)
	{
		if (_s[i] == (unsigned char)c)
			return ((char *)(_s + i));
		i--;
	}
	return (0);
}
