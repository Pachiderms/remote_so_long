/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:23:56 by tzizi             #+#    #+#             */
/*   Updated: 2024/05/22 13:28:19 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*_s;

	i = 0;
	_s = (unsigned char *)s;
	while (s[i])
	{
		if (_s[i] == (unsigned char)c)
			return ((char *)(_s + i));
		i++;
	}
	if (_s[i] == (unsigned char)c)
		return ((char *)(_s + i));
	return (0);
}
