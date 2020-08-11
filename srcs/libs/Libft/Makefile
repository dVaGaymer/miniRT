# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 17:06:37 by aloez-g           #+#    #+#              #
#    Updated: 2020/08/09 23:36:11 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_INC	=	${LIBFT_DIR}includes/
SRCS_DIR	=	${LIBFT_DIR}srcs/
SRCS		=	${SRCS_DIR}ft_memset.c ${SRCS_DIR}ft_bzero.c ${SRCS_DIR}ft_memcpy.c ${SRCS_DIR}ft_memccpy.c ${SRCS_DIR}ft_memmove.c ${SRCS_DIR}ft_memchr.c \
				${SRCS_DIR}ft_memcmp.c ${SRCS_DIR}ft_strlen.c ${SRCS_DIR}ft_strlcpy.c ${SRCS_DIR}ft_strlcat.c ${SRCS_DIR}ft_strchr.c ${SRCS_DIR}ft_strrchr.c\
				${SRCS_DIR}ft_strnstr.c ${SRCS_DIR}ft_strncmp.c ${SRCS_DIR}ft_atoi.c ${SRCS_DIR}ft_isalpha.c ${SRCS_DIR}ft_isdigit.c ${SRCS_DIR}ft_isalnum.c \
				${SRCS_DIR}ft_isascii.c ${SRCS_DIR}ft_isprint.c ${SRCS_DIR}ft_toupper.c ${SRCS_DIR}ft_tolower.c ${SRCS_DIR}ft_calloc.c ${SRCS_DIR}ft_strdup.c\
				${SRCS_DIR}ft_substr.c ${SRCS_DIR}ft_strjoin.c ${SRCS_DIR}ft_strtrim.c ${SRCS_DIR}ft_split.c ${SRCS_DIR}ft_itoa.c ${SRCS_DIR}ft_strmapi.c \
				${SRCS_DIR}ft_putchar_fd.c ${SRCS_DIR}ft_putstr_fd.c ${SRCS_DIR}ft_putendl_fd.c ${SRCS_DIR}ft_putnbr_fd.c ${SRCS_DIR}ft_uitoab.c ${SRCS_DIR}ft_ultoab.c

OBJS		= 	$(patsubst %.c, %.o, ${SRCS})

SRCS_BONUS	= 	${SRCS_DIR}ft_lstnew_bonus.c ${SRCS_DIR}ft_lstadd_front_bonus.c ${SRCS_DIR}ft_lstsize_bonus.c ${SRCS_DIR}ft_lstlast_bonus.c \
				${SRCS_DIR}ft_lstadd_back_bonus.c ${SRCS_DIR}ft_lstdelone_bonus.c ${SRCS_DIR}ft_lstclear_bonus.c ${SRCS_DIR}ft_lstiter_bonus.c ${SRCS_DIR}ft_lstmap_bonus.c

OBJS_BONUS 	= 	${SRCS_BONUS:.c=.o}

%.o : %.c
				clang -Wall -Werror -Wextra -I $(LIBFT_INC) -c $< -o $@

NAME		= 	libft.a

$(NAME):		${OBJS}
				ar -rc ${NAME} ${OBJS}
				ar -s ${NAME}
all:			${NAME}
bonus:			${OBJS} ${OBJS_BONUS}
				ar -rc ${NAME} ${OBJS} ${OBJS_BONUS}
				ranlib ${NAME}
clean:
				rm -f ${OBJS} ${OBJS_BONUS}
fclean:			clean
				rm -f ${NAME}
re:				fclean all
.PHONY:			all clean fclean re bonus
