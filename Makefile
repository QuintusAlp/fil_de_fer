# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 13:15:29 by qalpesse          #+#    #+#              #
#    Updated: 2024/06/12 12:18:49 by qalpesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ft_drawline.c ft_get_points.c ft_get_points_utils.c ft_centermap.c ft_projections.c ft_error.c ft_translation.c

OBJS = $(SRCS:%.c=%.o)

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
cc = gcc
INCLUDE = fdf.h


all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDE}

${NAME}: ${OBJS}
		make all -C ./libft
		${CC} ${CFLAGS} ${OBJS} -fsanitize=address -g -L./libft -lft  -L./minilibx_macos -lmlx -framework OpenGl -framework AppKit -o ${NAME}


clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re ${NAME}