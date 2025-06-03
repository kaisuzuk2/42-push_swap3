NAME = push_swap
CC = cc
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
SRCS = main.c \
		error_check.c\
		push.c\
		rotate.c\
		swap.c\
		stack_utils.c\
		compression.c\
		sort_three.c\
		sort_five.c\
		operation_helper.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C ./printf
	cp ./printf/libftprintf.a .
	$(CC) $(FLAG) -o $(NAME) $(SRCS) libftprintf.a

%.o: %.c
	$(CC) $(FLAG) -c -o $@ $<

clean:
	make -C ./printf clean	
	rm -rf $(OBJS)

fclean: clean
	make -C ./printf fclean
	rm -rf libftprintf.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re