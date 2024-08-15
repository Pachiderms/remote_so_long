/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:09:45 by tzizi             #+#    #+#             */
/*   Updated: 2024/05/29 16:14:16 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char c, char const *sup)
{
	int	i;

	i = 0;
	while (sup[i])
	{
		if (sup[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	to_trim(char const *s, char const *_set, int i)
{
	int	j;

	j = i;
	while (in_set(s[j], _set))
		j++;
	return (s[j] == '\0' || (i == 0 && j != i));
}

int	sizeupfun(char const *_s1, char const *_setter)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (_s1[i])
	{
		if (to_trim(_s1, _setter, i) == 0)
			size++;
		i++;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	end = sizeupfun(s1, set);
	start = 0;
	while (in_set(s1[start], set))
		start++;
	while (in_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
