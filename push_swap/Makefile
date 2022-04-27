SRCS = main.c utils.c ft_atoi_push.c case_of_tree_five.c case_of_hundred.c utils_swap.c utils3.c utils_push.c ft_check.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = gcc

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(FLAGS) -c $< -o $@

libft:
	make -C libft/ 

${NAME}: libft ${OBJS}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft
clean: 
	rm -f ${OBJS}

fclean: clean
	make -C libft/ fclean
	rm -f ${NAME}

re: fclean all

.PHONY: libft