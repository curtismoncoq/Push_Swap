SRCS = push_swap.c push_swap_a_ope.c push_swap_b_ope.c push_swap_check.c push_swap_costs.c push_swap_last.c push_swap_parsing.c push_swap_ring.c push_swap_rotates.c push_swap_targets.c push_swap_tasks.c

BONUS = push_swap_bonus.c push_swap_ope_bonus.c push_swap_check_bonus.c push_swap_parsing_bonus.c push_swap_ring_bonus.c push_swap_tasks_bonus.c

LIBFT = libft/libft.a

LIBFTDIR = libft

OBJS = $(SRCS:.c=.o)

OBONUS= $(BONUS:.c=.o)

NAME = push_swap

CHECK = checker

ARGS = 1002 495 293857 929 57947 48 41 2 4 -2 -999 0 11 7 22275 45 3 -100

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME) $(CHECK)

mandatory: $(NAME)

bonus: $(CHECK)

$(LIBFT):
	make bonus -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

$(CHECK): $(OBONUS) $(LIBFT)
	$(CC) -o $(CHECK) $(OBONUS) -L$(LIBFTDIR) -lft

clean:
	rm -f $(OBJS)
	rm -f $(OBONUS)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(CHECK)

re: fclean all

m: $(NAME)
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	./$(NAME) $(ARGS)

b: $(CHECK)
	rm -f $(OBONUS)
	make clean -C $(LIBFTDIR)
	./$(CHECK) $(ARGS)

x: all
	rm -f $(OBJS)
	rm -f $(OBONUS)
	make clean -C $(LIBFTDIR)
	./$(NAME) $(ARGS) | ./$(CHECK) $(ARGS)

.PHONY: all bonus clean fclean re x c check
