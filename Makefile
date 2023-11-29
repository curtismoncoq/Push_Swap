SRCS = push_swap.c push_swap_a_ope.c push_swap_b_ope.c push_swap_check.c push_swap_costs.c push_swap_last.c push_swap_parsing.c push_swap_ring.c push_swap_rotates.c push_swap_targets.c push_swap_tasks.c

LIBFT = libft/libft.a

LIBFTDIR = libft

OBJS = $(SRCS:.c=.o)

NAME = push_swap

ARGS = 1002 495 293857 929 57947 48 41 2 4 -2 -999 0 11 7 22275 45 3 -100

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

x: re
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	rm -f $(LIBFT)
	./$(NAME) $(ARGS)

c: $(NAME)
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	./$(NAME) $(ARGS)

check: $(NAME)
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	./$(NAME) $(ARGS) | ./checker_linux $(ARGS)

.PHONY: all clean fclean re x c check
