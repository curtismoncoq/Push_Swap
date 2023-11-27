// Double sided list a & b

// handle errors of input

// input can be a string or multiple ints so we use spli on string

// if no errors each number goes into linked list a

// check if sorted
// 		if !sorted, sort it
// 			check for 2 number case;		-> swap
// 			check for 3 number case;		-> sort 3 algo;
// 			check for >3 number case		-> big man sorting turk algorithm;

//!----------------------------------------------------------//

#include "push_swap.h"

t_ring	*ft_create_element(int data)
{
	t_ring	*n;

	n = (t_ring *)malloc(sizeof(t_ring));
	if (!n)
		return (NULL);
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	n->target = NULL;
	n->cost = 0;
	return (n);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

// void	ft_cost_supp(t_updown cost, t_ints up, t_ints down, t_ints *res)
// {
// 	res->min = ft_min(ft_min(cost.uu, cost.dd), ft_min(cost.ud, cost.du));
// 	if (cost.uu == res->min)
// 	{
// 		res->a = -up.a;
// 		res->b = -up.b;
// 	}
// 	else if (cost.dd == res->min)
// 	{
// 		res->a = down.a;
// 		res->b = down.b;
// 	}
// 	else if (cost.du == res->min)
// 	{
// 		res->a = down.a;
// 		res->b = -up.b;
// 	}
// 	else if (cost.ud == res->min)
// 	{
// 		res->a = -up.a;
// 		res->b = down.b;
// 	}
// 	return (res);			//! negative value means going up positive means going down
// }


// t_ints	ft_cost(t_ints up, t_ints down)		//? takes the distance top for a and b nodes traveling up or down, returns the opti route
// {
// 	t_updown	cost;
// 	int 		min;
// 	t_ints		res;

// 	cost.uu = ft_max(up.a, up.b);
// 	cost.dd = ft_max(down.a, down.b);
// 	cost.ud = up.a + down.b;
// 	cost.du = down.a + up.b;
// 	ft_cost_supp(cost, up, down, &res);
// 	return (res);
// }


void ft_ring_push_top(t_ring **top, int data)
{
	t_ring	*n;

	n = ft_create_element(data);
	if (n)
	{
		if (*top)
		{
			n->next = *top;
			n->prev = (*top)->prev;
			n->prev->next = n;
			(*top)->prev = n;
		}
		else
		{
			n->next = n;
			n->prev = n;
		}
		*top = n;
	}
}					//? Push a node at the bottom

void ft_ring_push_back(t_ring **top, int data)
{
	t_ring	*n;

	n = ft_create_element(data);
	if (n)
	{
		if (*top)
		{
			n->next = *top;
			n->prev = (*top)->prev;
			n->prev->next = n;
			(*top)->prev = n;
		}
		else
		{
			n->next = n;
			n->prev = n;
			*top = n;

		}
	}
}					//? Push a node at the bottom

// void	ft_rotate_printer(t_ints res)
// {
	
// }

void	ft_print_ring(t_ring *top)
{
	t_ring	*move;

	if (!top)
	{
		ft_printf("NULL\n");
		return ;
	}
	move = top->next;
	ft_printf(">%d	up>%d	down>%d\n", top->data, top->up, top->down);
	while (move != top)
	{
		ft_printf(">%d	up>%d	down>%d\n", move->data, move->up, move->down);
		move = move->next;
	}
}			//? PRIIIIIIIIINT

void	ft_clear_ring(t_ring **top)
{
	t_ring	*move;
	t_ring	*tmp;

	if (!(*top))
		return ;
	move = (*top)->next;
	while (move != *top)
	{
		tmp = move;
		move = move->next;
		free (tmp);
	}
	free(*top);
	*top = NULL;
}					//? Free all nodes in a ring set top to NULL

long	ft_long_atoi(const char *str)
{
	int		i;
	int		sign;
	long	x;

	x = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		x *= 10;
		x += str[i] - 48;
		i++;
	}
	return (x * sign);
}				//? Atoi but long

int ft_valid_str(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (!i)
		return (0);
	return (1);
}					//? Checks for validity of a string according to long_atoi rules

int	ft_valid_stack(int ac, char **stack)
{
	int		i;
	long	a;

	i = 0;
	while (stack[i] && (i < ac || ac == 2))
	{
		if (!ft_valid_str(stack[i]))
			return (0);
		i++;
	}
	i = 0;
	while (stack[i] && (i < ac || ac == 2))
	{
		a = ft_long_atoi(stack[i]);
		if (a > INT_MAX || a < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}				//?Checks for INTMIN/MAX or non-ints in the stack of strings

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}				//? Free the split used to parse

void	ft_parse_args(int ac, char **av, t_ring **top)
{
	int	i;

	i = 0;
	char **stack;
	stack = NULL;
	if (ac == 2)
		stack = ft_split(av[1], ' ');	//!need to free later
	else if (ac > 2)
		stack = av + 1;
	if (!ft_valid_stack(ac, stack))
	{
		write(2, "Error: Invalid arguments.", 26);
		if (ac == 2)
			ft_free_split(stack);
		return ;
	}
	while (stack[i] && (i < ac || ac == 2))
	{
		ft_ring_push_back(top, ft_long_atoi(stack[i]));
		i++;
	}
	if (ac == 2)
		ft_free_split(stack);
}						//? Parse args and converts them to the A ring if it's only valid integers

int	ft_check_double(t_ring	**top)
{
	t_ring	*a;
	t_ring	*b;

	a = *top;
	b = (*top)->next;
	while (b != *top)
	{
		if (a->data == b->data)
			return (1);
		b = b->next;
	}
	a = a->next;
	while (a != *top)
	{
		b = a->next;
		while (b != *top)
		{
			if (a->data == b->data)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}						//? Checks for any duplicate ints

int	ft_len_ring(t_ring *top)
{
	t_ring	*move;
	int		len;

	if (!top)
		return (0);
	move = top->next;
	len = 1;
	while (move != top)
	{
		len++;
		move = move->next;
	}
	return (len);
}						//? Returns the lenght of the ring

void	ft_remove_top(t_ring **top)
{
	(*top)->next->prev = (*top)->prev;
	(*top)->prev->next = (*top)->next;
	(*top) = (*top)->next;
}						//? Remove the top node of a ring

void	ft_push(t_ring **a, t_ring **b)
{
	t_ring	*top;

	top = *a;
	ft_remove_top(a);
	ft_ring_push_top(b, top->data);
	free (top);
}						//? push first A node to B

void	ft_one_target(t_ring *node, t_ring *b)
{
	t_ring	*target;
	t_ring	*move;

	target = b;
	move = b->next;
	while (move != b)
	{
		if (move->data < node->data && move->data > target->data)
			target = move;
		move = move->next;
	}
	node->target = target;
}						//? set the target of "node" by checking all possible targets in b

void	ft_all_target(t_ring *a, t_ring *b)
{
	t_ring	*move;

	move = a->next;
	ft_one_target(a, b);
	while (move != a)
	{
		ft_one_target(move, b);
		move = move->next;
	}
}						//? uses the above function to set all targets in ring a

void	ft_both_dist(t_ring *top)
{
	t_ring	*move;
	int		i;

	move = top->next;
	i = 1;
	while (move != top)
	{
		move->up = i;
		i++;
		move = move->next;
	}
	move = top->prev;
	i = 1;
	while (move != top)
	{
		move->down = i;
		i++;
		move = move->prev;
	}
}						//? sets each nodes [up/down distances] in a ring

// void	ft_choose_and_push(t_ring **a, t_ring **b)
// {

// }

void	ft_order(t_ring **a, t_ring **b)
{
	if (ft_len_ring(*a) > 3)
		ft_push(a, b);
	if (ft_len_ring(*a) > 3)
		ft_push(a, b);
	// while (ft_len_ring(a) > 3)	//TODO put back
	// 	ft_choose_and_push(a, b);	//TODO put back
	ft_all_target(*a, *b);	//! to test
	ft_both_dist(*a);
	ft_both_dist(*b);

}

int main(int ac, char **av)
{
	t_ring	*a;
	t_ring	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	ft_parse_args(ac, av, &a);
	if (a && ft_check_double(&a))
	{
		ft_clear_ring(&a);
		ft_putstr_fd("Error: Duplicate numbers in arguments.", 2);
	}
	// ft_printf("len is %d\n", ft_len_ring(a));	//! delete
	ft_order(&a, &b);
	// if (ft_len_ring(a) <= 3)	//?
	// 	ft_order_small(&a);		//?
	// if (ft_len_ring(a) > 3)	//? else if
	// 	ft_order(&a, &b);
	ft_print_ring(a); 		//! delete
	ft_putchar_fd('\n', 1);
	ft_print_ring(b);	//! delete
	// ft_printf("len is %d\n", ft_len_ring(a));
	ft_clear_ring(&a);
	ft_clear_ring(&b);
	return (0);
}


