SRCS = push_swap.c

LIBFT = libft/libft.a

LIBFTDIR = libft

OBJS = $(SRCS:.c=.o)

NAME = push_swap

ARGS = 5 8 4 6 2 3 1 9 7 0

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft
	

all: $(NAME)

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

.PHONY: all clean fclean re
