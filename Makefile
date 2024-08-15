# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 13:30:58 by tzizi            #+#    #+#              #
#    Updated: 2024/08/15 13:30:58 by tzizi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
NAME_BONUS		= so_long_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

printf 			= ./lib/printf/printf.a

CC 				= clang

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./src/
BONUS_SRCS_DIR	= ./bonus_src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				so_long.c			\
				ft_check_map.c		\
				ft_close_game.c		\
				ft_free_memory.c	\
				ft_handle_input.c	\
				ft_init_game.c		\
				ft_init_map.c		\
				ft_render_map.c		\
				ft_utils.c)

SRCS_BONUS 		= $(addprefix $(BONUS_SRCS_DIR),\
				so_long_bonus.c				\
				ft_check_map_bonus.c		\
				ft_close_game_bonus.c		\
				ft_free_memory_bonus.c		\
				ft_handle_input_bonus.c		\
				ft_init_game_bonus.c		\
				ft_init_map_bonus.c			\
				ft_render_map_bonus.c		\
				ft_utils_bonus.c)

all:			${printf} ${NAME}

${NAME}: 		
				${CC} ${SRCS} ${printf} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

bonus:			${printf} ${NAME_BONUS}

${NAME_BONUS}:		
				${CC} ${SRCS_BONUS} ${printf} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME_BONUS}
				@echo "\n$(NAME): $(GREEN)$(NAME) was compiled with Bonus.$(RESET)"
				@echo

${printf}:
				@echo
				make -C lib/printf

clean:
				make clean -C lib/printf
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo

re:				fclean all

rebonus:		fclean ${NAME_BONUS}

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

run_bonus:		${NAME_BONUS}
				${VALGRIND} ./${NAME_BONUS} assets/maps/valid/bonus/map5.ber

.PHONY:			all clean fclean re rebonus valgrind run run_bonus
