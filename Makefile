# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmika <wmika@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:51:25 by wmika             #+#    #+#              #
#    Updated: 2022/01/25 13:51:28 by wmika            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

SRC = so_long.c reading.c reading_1.c reading_2.c so_long_extra.c

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

OBJ = ${SRC:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

MFLAGS = -framework OpenGL -framework AppKit

RM		= rm -f

all:		${NAME}

${NAME}:	${LIBFT} ${MLX} ${OBJ} ${HEADER}
			${CC} ${cFLAGS} ${MFLAGS} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}

${LIBFT}:	
			make -C  ./libft
			make -C  ./libft bonus

${MLX}:		
			make -C ./mlx

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

clean:	
			${RM} ${OBJ}
			make -C ./libft clean
			make -C ./mlx clean

fclean:		clean
			${RM} ${NAME}
			make  -C ./libft fclean
			make  -C ./mlx fclean

re:			fclean all

.PHONY:		all clean fclean re
