NAME = libftprintf.a

LIBFTPRINTF = src/ft_printstr.c src/ft_printf.c \
	src/ft_printhexa.c src/ft_printu.c \
	src/ft_strjoinf.c src/ft_printptr.c \

LIBFT = libft

SRCS = ${LIBFTPRINTF}

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -I ./

.c.o:
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cp ./$(LIBFT)/libft.a ./$(NAME)
	ar -rc ${NAME} ${OBJS}
	ranlib $(NAME)

all: ${NAME}

clean:
	/bin/rm -f $(OBJS) $(DEPS)
	make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}
