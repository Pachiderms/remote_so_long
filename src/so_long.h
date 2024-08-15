/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:27:29 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/15 13:27:29 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../lib/printf/src/ft_printf.h"

# define IMG_HEIGHT			90
# define IMG_WIDTH			90

# define ROCK				'1'
# define GRASS 				'0'
# define POKEBALL  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define ROCK_XPM			"assets/sprites/rock.xpm"
# define GRASS_XPM			"assets/sprites/grass.xpm"
# define POKEBALL_XPM			"assets/sprites/pokeball.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/walk_up.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/walk_left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/walk_right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/walk_down.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			POKEBALL;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		ROCK;
	t_image		GRASS;
	t_image		POKEBALL;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

void	ft_check_command_line_arguments(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *argv);
char	*ft_strappend(char **s1, const char *s2);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_init_vars(t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
size_t	ft_strlen_line(const char *str);
void	ft_check_columns(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
int		ft_render_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
void	ft_player_move(t_game *game, int x, int y, int player_sprite);
int		ft_victory(t_game *game);
int		ft_error_msg(char *message, t_game *game);
int		ft_close_game(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);

#endif
