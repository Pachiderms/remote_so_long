/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:29:30 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/15 13:29:30 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		ft_handle_input(int keysym, t_game *game);
void	ft_player_move(t_game *game, int x, int y, int player_sprite);

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		ft_close_game(game);
	return (0);
}

void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == TOXIC_RIVER)
		ft_loss(game);
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.POKEBALL == 0)
		ft_victory(game);
	else if ((game->map.full[new_y][new_x] == GRASS)
	|| (game->map.full[new_y][new_x] == POKEBALL))
	{
		game->map.full[last_y][last_x] = GRASS;
		if (game->map.full[new_y][new_x] == POKEBALL)
			game->map.POKEBALL--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		ft_render_map(game);
	}
}
