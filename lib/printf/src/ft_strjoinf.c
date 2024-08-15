/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:23 by tzizi             #+#    #+#             */
/*   Updated: 2024/06/12 14:27:35 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_count_words(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	return (j + i);
}

char	*ft_strjoinf(char const *s1, char const *s2)
{
	int		x;
	int		c;
	int		size;
	char	*conc;

	size = ft_count_words(s1, s2);
	x = 0;
	c = 0;
	conc = malloc(size * sizeof(char) + 1);
	if (conc == NULL)
		return (0);
	while (s1[c] && c + x < size)
	{
		conc[c] = s1[c];
		c++;
	}
	while (s2[x] && c + x < size)
	{
		conc[x + c] = s2[x];
		x++;
	}
	conc[x + c] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (conc);
}
