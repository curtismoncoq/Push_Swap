PUSH = push_swap.c

LIBFT = libft/libft.a

LIBFTDIR = libft

SRCS = ${PUSH}

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFT) .
	$(CC) -o $(NAME) $(OBJS) -L. -lft
	

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f libft.a

re: fclean all

x: re clean
	./$(NAME) 12 4 56 2 0 -3

.PHONY: all clean fclean re
