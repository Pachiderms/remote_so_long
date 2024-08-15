/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:29:48 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/15 13:29:48 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		ft_render_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_identify_sprite(t_game *game, int y, int x)
{	
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == ROCK)
		ft_render_sprite (game, game->ROCK, y, x);
	else if (parameter == GRASS)
		ft_render_sprite (game, game->GRASS, y, x);
	else if (parameter == POKEBALL)
		ft_render_sprite (game, game->POKEBALL, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.POKEBALL == 0)
			ft_render_sprite (game, game->open_exit, y, x);
		else
			ft_render_sprite (game, game->exit_closed, y, x);
	}
	else if (parameter == PLAYER)
		ft_render_player (game, y, x);
	else if (parameter == TOXIC_RIVER)
		ft_render_sprite (game, game->toxic, y, x);
}

void	ft_render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite (game, game->player_front, y, x);
	if (game->player_sprite == LEFT)
		ft_render_sprite (game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		ft_render_sprite (game, game->player_right, y, x);
	if (game->player_sprite == BACK)
		ft_render_sprite (game, game->player_back, y, x);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}
