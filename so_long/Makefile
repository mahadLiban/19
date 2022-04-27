SRCS = main.c error.c error1.c ft_move_pixel.c ft_map.c ft_pars_map.c ft_pars_map2.c \
ft_keyco.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRCS_GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS_GNL = ${SRCS_GNL:.c=.o}

all : ${NAME}

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c $< -o $@
	
${NAME}: libft  ${OBJS} ${OBJS_GNL} 
	
	make -C ft_printf
	$(CC) $(CFLAGS) -o $(NAME) -lmlx -framework OpenGl -framework AppKit $(OBJS) ${OBJS_GNL} ft_printf/libftprintf.a 
clean: 
	rm -f ${OBJS}
	make clean -C ft_printf

fclean: clean
	rm -f ${NAME}
	rm -f ${OBJS_GNL}
	make fclean -C ft_printf

	
re: fclean all


.PHONY: libft