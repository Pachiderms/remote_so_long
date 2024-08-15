/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:00:41 by tzizi             #+#    #+#             */
/*   Updated: 2024/06/18 13:33:57 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
char	*ft_itoaf(unsigned long long n, char *base);
char	*ft_itoax(long n, char *base);
int		ft_printstr(char *str);
char	*ft_itoau(unsigned int n);
char	*ft_strjoinf(char const *s1, char const *s2);
char	*ft_printptr(unsigned long long n);

#endif
