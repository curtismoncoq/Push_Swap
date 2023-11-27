PUSH = push_swap.c

LIBFT = libft/libft.a

LIBS = libft.a

LIBFTDIR = libft

SRCS = ${PUSH}

OBJS = $(SRCS:.c=.o)

NAME = push_swap

ARGS = 12 4 56 2 0 -3

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(LIBS): $(LIBFTDIR)
	make -C $(LIBFTDIR)
	cp $(LIBFT) .

$(NAME): $(OBJS) $(LIBS)
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

x: re
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	rm -f $(LIBFT)
	rm -f libft.a
	./$(NAME) $(ARGS)

c: $(NAME)
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re
