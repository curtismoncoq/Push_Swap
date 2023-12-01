SRCS = push_swap.c push_swap_a_ope.c push_swap_b_ope.c push_swap_check.c push_swap_costs.c push_swap_last.c push_swap_parsing.c push_swap_ring.c push_swap_rotates.c push_swap_targets.c push_swap_tasks.c

BONUS = push_swap_sprab_bonus.c push_swap_bonus.c push_swap_ope_bonus.c push_swap_check_bonus.c push_swap_parsing_bonus.c push_swap_ring_bonus.c push_swap_tasks_bonus.c

LIBFT = libft/libft.a

LIBFTDIR = libft

OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

OBONUS = $(addprefix $(OBJDIR),$(BONUS:.c=.o))

OBJDIR = objs/

NAME = push_swap

CHECK = checker

ARGS = 641 7643 -4995 -9035 4803 -119 298 2809 6817 9465 -913 -7541 -5787 -1106 1976 -196 7078 1806 -7852 1100 6814 5185 2330 -5920 5671 6719 -2364 -740 7019 -532 2611 662 -606 312 4008 -14 -4080 3033 -4558 -3529 6957 -4294 7991 -9914 769 -169 -4296 1731 -7063 -6517 -2213 -4906 -6759 8145 386 7231 8225 -9625 1018 1013 -1357 -4338 9556 -8020 8477 -2860 9555 -8616 5895 -6938 -1243 7796 8167 3332 6331 -6176 -2661 -3886 -5585 -2645 -4608 -4654 3755 -1066 7045 -5270 1342 5425 -4496 -8955 -9818 2946 3444 -819 7716 -5003 -9627 -5805 5190 -7181

CC = cc

CFLAGS = -Wall -Wextra -Werror

$(OBJDIR)%.o : %.c
	mkdir -p $(OBJDIR)
	${CC} ${CFLAGS} -c $< -o $@

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
	rmdir $(OBJDIR)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(CHECK)

re: fclean all

m: $(NAME)
	./$(NAME) $(ARGS)

b: $(CHECK)
	./$(CHECK) $(ARGS)

x: all
	./$(NAME) $(ARGS) | ./$(CHECK) $(ARGS)

.PHONY: all mandatory bonus clean fclean re m b x
