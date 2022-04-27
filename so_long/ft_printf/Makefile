# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:45:25 by mliban-s          #+#    #+#              #
#    Updated: 2022/01/19 16:45:29 by mliban-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_hexa.c ft_putusign.c ft_c_case.c ft_di_case.c \
ft_s_case.c ft_p_case.c ft_x_case.c ft_x_upp_case.c ft_prct_case.c ft_u_case.c ft_form.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : libft ${NAME} 

libft : 
	make -C libft/

${NAME}: ${OBJS}
	cp libft/libft.a ${NAME}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	make -C libft/ fclean
	rm -f ${NAME}

re: fclean all

.PHONY : libft
