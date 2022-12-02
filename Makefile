# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:19:03 by aperin            #+#    #+#              #
#    Updated: 2022/12/02 15:18:17 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC_FILE	= main.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				error/error.c \
				input/input.c \
				map/init_map.c \
				map/legal_map.c \
				map/map_utils.c \
				path/path.c \
				path/path_utils.c \
				game/game.c \
				game/game_hooks.c \
				game/sprites.c \
				game/update.c
				
SRCS_DIR	= srcs
OBJSDIR		= objs
INCDIR		= includes ${FT_PRINTF_DIR}/includes ${LIBFT_DIR} srcs/mlx

SRCS		= $(addprefix ${SRCS_DIR}/, ${SRC_FILE})
OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${SRC_FILE})))
OBJS_DIR	= $(sort $(dir $(OBJS)))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= $(foreach d, $(INCDIR), -I$d)

# libft
LIBFT_DIR	= srcs/libft
LIBFT		= ${LIBFT_DIR}/libft.a

# ft_printf
FT_PRINTF_DIR	= srcs/ft_printf
FT_PRINTF		= ${FT_PRINTF_DIR}/libftprintf.a

# Minilibx
MLX_DIR		= srcs/mlx
MLX_PATH	= ${MLX_DIR}/libmlx.a
MLX			= -framework OpenGL -framework AppKit ${MLX_PATH}

# Rules
${OBJSDIR}/%.o: ${SRCS_DIR}/%.c
			@mkdir -p ${OBJSDIR} ${OBJS_DIR}
			${CC} ${CFLAGS} ${INCS} -c -o $@ $<

all:		${NAME}

${NAME}:	${OBJS}
			@make -C ${MLX_DIR}
			@make -C ${LIBFT_DIR}
			@make -C ${FT_PRINTF_DIR}
			${CC} ${OBJS} ${LIBFT} ${FT_PRINTF} ${MLX} -o ${NAME}

clean:
			@make clean -C ${MLX_DIR}
			@make clean -C ${FT_PRINTF_DIR}
			@make clean -C ${LIBFT_DIR}
			rm -rf ${OBJSDIR}

fclean:		clean
			@make fclean -C ${LIBFT_DIR}
			@make fclean -C ${FT_PRINTF_DIR}
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME