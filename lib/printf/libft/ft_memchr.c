/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:54:35 by tzizi             #+#    #+#             */
/*   Updated: 2024/05/22 14:07:42 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	int *t = (int*)ft_memchr(tab, -1, 7);
	int *t1 = (int*)memchr(tab, -1, 7);

	for (int i = 0; i < 7; i++)
	{
		printf("%c || ", t[i]);
	}
	for (int j = 0; j < 7; j++)
	{
		printf("%c || ", t1[j]);
	}
}*/
