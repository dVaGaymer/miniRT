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

MINIRT_DIR	=	srcs/
LIBFT_DIR	=	srcs/Libft/
FTPF_DIR	=	srcs/FTPF/
GNL_DIR		=	srcs/GNL/

LIBFT_INC	=	${LIBFT_DIR}includes/
FTPF_INC	=	${FTPF_DIR}includes/
GNL_INC		=	${GNL_DIR}includes/

SRCS		=	${MINIRT_DIR}main.c
OBJS		= 	$(patsubst %.c, %.o, ${SRCS})

LIBFT_A		=	${LIBFT_DIR}libft.a
LIBFT_LIB	=	ft
GNL_A		=	${GNL_DIR}libgnl.a
GNL_LIB		=	gnl
FTPF_A		=	${FTPF_DIR}libftprintf.a
FTPF_LIB	=	ftprintf

NAME		=	miniRT

CC			=	gcc
FLAGS		=	-L srcs/minilibx-linux -l mlx -l m -l bsd -l X11 -l Xext

%.o : %.c
				clang -Wall -Werror -Wextra -I ${FTPF_INC} -I ${LIBFT_INC} -I ${GNL_INC} -c $< -o $@

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
				rm -f *.a
				
re:				fclean all
.PHONY:			all clean fclean re bonus