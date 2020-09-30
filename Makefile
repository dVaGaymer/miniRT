# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 00:22:43 by alopez-g          #+#    #+#              #
#    Updated: 2020/08/23 17:08:46 by dvagaymer        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_INC	=	${LIBFT_DIR}includes/
FTPF_INC	=	${FTPF_DIR}includes/
GNL_INC		=	${GNL_DIR}includes/

SRCS_DIR	=	${MINIRT_DIR}
SRCS		=	${SRCS_DIR}srcs/main.c ${SRCS_DIR}srcs/loadScene/load_scene.c ${SRCS_DIR}srcs/loadScene/load_polygons.c \
			${SRCS_DIR}srcs/loadScene/load_setup_properties.c ${SRCS_DIR}srcs/loadScene/load_scene_utils.c
OBJS		= 	$(patsubst %.c, %.o, ${SRCS})

LIBFT_LIB	=	ft
LIBFT_A		=	${LIBFT_DIR}lib${LIBFT_LIB}.a

GNL_LIB		=	gnl
GNL_A		=	${GNL_DIR}lib${GNL_LIB}.a

FTPF_LIB	=	ftprintf
FTPF_A		=	${FTPF_DIR}lib${FTPF_LIB}.a

NAME		=	miniRT

CC			=	clang

	#Check OS
#IF MACOS
#MLX_DIR	=	${MINIRT_DIR}srcs/libs/minilibx_opengl_20191021
#FLAGS		=	-framework OpenGL -framework AppKit
#IF LINUX
MLX_DIR		=	${MINIRT_DIR}srcs/libs/minilibx-linux
FLAGS		=	-L/usr/lib -lXext -lX11 -lm -lz

%.o : %.c
				clang -I ${FTPF_INC} -I ${LIBFT_INC} -I ${GNL_INC} -I ${MLX_DIR} -c $< -o $@

${NAME}:		${OBJS}
				make -C ${LIBFT_DIR}
				cp ${LIBFT_A} ./

				make -C ${FTPF_DIR}
				cp ${FTPF_A} ./

				make -C ${GNL_DIR}
				cp ${GNL_A} ./

				${CC} ${FLAGS} ${OBJS} -L${MLX_DIR} -lmlx -L${MINIRT_DIR} -l${GNL_LIB} -l${FTPF_LIB} -l${LIBFT_LIB} -o ${NAME}

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
				rm -f *.a
				rm -f miniRT
				
re:				fclean all
.PHONY:			all clean fclean re bonus
