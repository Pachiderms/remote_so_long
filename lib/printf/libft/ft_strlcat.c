/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:19:56 by tzizi             #+#    #+#             */
/*   Updated: 2024/05/22 12:20:12 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	sd;

	i = 0;
	sd = 0;
	while (dst[sd] != '\0')
		sd++;
	if (siz > sd)
	{
		while (src[i] != '\0' && sd + i + 1 < siz)
		{
			dst[sd + i] = src[i];
			i++;
		}
		dst[sd + i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	if (siz > sd)
		return (i + sd);
	else
		return (i + siz);
}
