/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:29:11 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/15 13:29:11 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_victory(t_game *game);
int	ft_loss(t_game *game);
int	ft_close_game(t_game *game);
int	ft_error_msg(char *message, t_game *game);

int	ft_victory(t_game *game)
{
	ft_printf(CYAN"\n			Movements: %d\n"RESET, ++game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf(GREEN"\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
"RESET);
	exit (EXIT_FAILURE);
}

int	ft_loss(t_game *game)
{
	ft_printf(CYAN"\n			Movements: %d\n"RESET, ++game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf(RED"\n\
█████████████████████████████████████████████████████████████████████\n\
██                                                                 ██\n\
██  ███  ███  ██████  ██    ██     ██      ██████   ██████ ██████  ██\n\
██   ██  ██  ██    ██ ██    ██     ██     ██    ██ ██      ██      ██\n\
██    ████   █      █ ██    ██     ██     █      █   ████  █████   ██\n\
██     ██    ██    ██ ██    ██     ██     ██    ██      ██ ██      ██\n\
██     ██     ██████    ████       ██████  ██████  ██████  ██████  ██\n\
██                                                                 ██\n\
█████████████████████████████████████████████████████████████████████\n\n\
"RESET);
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf(GREY"CLOSED\n"RESET);
	exit (EXIT_FAILURE);
}

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit (EXIT_FAILURE);
}
