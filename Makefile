# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 00:22:43 by alopez-g          #+#    #+#              #
#    Updated: 2020/08/10 01:03:56 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_INC	=	${LIBFT_DIR}includes/
FTPF_INC	=	${FTPF_DIR}includes/
GNL_INC		=	${GNL_DIR}includes/

SRCS_DIR	=	${MINIRT_DIR}
SRCS		=	${SRCS_DIR}srcs/main.c
OBJS		= 	$(patsubst %.c, %.o, ${SRCS})

LIBFT_LIB	=	ft
LIBFT_A		=	${LIBFT_DIR}lib${LIBFT_LIB}.a

GNL_LIB		=	gnl
GNL_A		=	${GNL_DIR}lib${GNL_LIB}.a

FTPF_LIB	=	ftprintf
FTPF_A		=	${FTPF_DIR}lib${FTPF_LIB}.a

NAME		=	miniRT

CC			=	gcc

#Following code works in MACOS
MLX_DIR		=	${MINIRT_DIR}srcs/libs/minilibx_opengl_20191021
FLAGS		=	-L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

%.o : %.c
				clang -Wall -Werror -Wextra -I ${FTPF_INC} -I ${LIBFT_INC} -I ${GNL_INC} -I ${MLX_DIR} -c $< -o $@

${NAME}:		${OBJS}
				make -C ${LIBFT_DIR}
				cp ${LIBFT_A} .

				make -C ${FTPF_DIR}
				cp ${FTPF_A} .
				
				make -C ${GNL_DIR}
				cp ${GNL_A} .
				
				${CC} ${OBJS} -L${LIBFT_DIR} -l${LIBFT_LIB} -L${FTPF_DIR} -l${FTPF_LIB} -L${GNL_DIR} -l${GNL_LIB} ${FLAGS} -o ${NAME}

all:			${NAME}

clean:
				make -C ${LIBFT_DIR} clean
				make -C ${FTPF_DIR} clean
				make -C ${GNL_DIR} clean
				rm -f ${OBJS}

fclean:			clean
				rm -f ${LIBFT_A}
				rm -f ${FTPF_A}
				rm -f ${GNL_A}
				rm -f miniRT
				
re:				fclean all
.PHONY:			all clean fclean re bonus
