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

RED		=	\033[0;31m
CYAN		=	\033[0;36m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
NC		=	\033[0m

LIBFT_INC	=	${LIBFT_DIR}includes/
FTPF_INC	=	${FTPF_DIR}includes/
GNL_INC		=	${GNL_DIR}includes/

SRCS_DIR	=	${MINIRT_DIR}
SRCS		=	main.c ${SRCS_DIR}srcs/loadScene/load_scene.c ${SRCS_DIR}srcs/loadScene/load_polygons.c \
				${SRCS_DIR}srcs/loadScene/load_setup_properties.c ${SRCS_DIR}srcs/loadScene/load_scene_utils.c ${SRCS_DIR}srcs/log/log_polygons.c
OBJS		= 	$(patsubst %.c, %.o, ${SRCS})

LIBFT_LIB	=	ft
LIBFT_A		=	${LIBFT_DIR}lib${LIBFT_LIB}.a

GNL_LIB		=	gnl
GNL_A		=	${GNL_DIR}lib${GNL_LIB}.a

FTPF_LIB	=	ftprintf
FTPF_A		=	${FTPF_DIR}lib${FTPF_LIB}.a

NAME		=	miniRT_TEST

CC			=	clang

#Check OS
#IF MACOS
ifeq ($(shell uname), "Darwin")
MLX_DIR	=	${MINiIRT_DIR}srcs/libs/minilibx_opengl_20191021
FLAGS		=	-framework OpenGL -framework AppKit
else
#IFNOT DARWIN (probably Linux)
MLX_DIR		=	${MINIRT_DIR}srcs/libs/minilibx-linux
FLAGS		=	-L/usr/lib -lXext -lX11 -lm -lz
endif

%.o : %.c
				@clang -I ${FTPF_INC} -I ${LIBFT_INC} -I ${GNL_INC} -I ${MLX_DIR} -c $< -o $@

${NAME}:		${OBJS}
				@echo -n "${RED}Compiling LIBFT${NC}"
				@make -s -C ${LIBFT_DIR}
				@cp ${LIBFT_A} ./
				@echo " ---> ${CYAN}Success${NC}"

				@echo -n "${RED}Compiling FTPF${NC}"
				@make -s -C ${FTPF_DIR}
				@cp ${FTPF_A} ./
				@echo "  ---> ${CYAN}Success${NC}"

				@echo -n "${RED}Compiling GNL${NC}"
				@make -s -C ${GNL_DIR}
				@cp ${GNL_A} ./
				@echo "   ---> ${CYAN}Success${NC}"

				@${CC} ${FLAGS} ${OBJS} -L${MLX_DIR} -lmlx -L./ -l${GNL_LIB} -l${FTPF_LIB} -l${LIBFT_LIB} -o ${NAME}
				@#make without mlx
				@#@${CC} ${OBJS} -L${MINIRT_DIR} -l${GNL_LIB} -l${FTPF_LIB} -l${LIBFT_LIB} -o ${NAME}
				@echo "\n${GREEN}${NAME} READY!${NC}"

all:			${NAME}

clean:
				@make -s -C ${LIBFT_DIR} clean
				@make -s -C ${FTPF_DIR} clean
				@make -s -C ${GNL_DIR} clean
				@rm -f ${OBJS}
				@echo "${YELLOW}OBJS Removed!${NC}"

fclean:			clean
				@rm -f ${LIBFT_A}
				@rm -f ${FTPF_A}
				@rm -f ${GNL_A}
				@rm -f *.a
				@echo "${YELLOW}LIBS Removed!${NC}"
				@rm -f miniRT
				@echo "${YELLOW}miniRT exe Removed!${NC}"
				
re:				fclean all
.PHONY:			all clean fclean re bonus
