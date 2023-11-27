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

void	ft_cost_supp(t_updown cost, t_ring *a, t_ring *target)
{
	a->cost = ft_min(ft_min(cost.uu, cost.dd), ft_min(cost.ud, cost.du));
	if (cost.uu == a->cost)
	{
		a->route.a = -a->up;
		a->route.target = -target->up;
	}
	else if (cost.dd == a->cost)
	{
		a->route.a = a->down;
		a->route.target = target->down;
	}
	else if (cost.du == a->cost)
	{
		a->route.a = a->down;
		a->route.target = -target->up;
	}
	else if (cost.ud == a->cost)
	{
		a->route.a = -a->up;
		a->route.target = target->down;
	}							//! negative value means going up positive means going down
}


void	ft_cost(t_ring *a, t_ring *target)
{
	t_updown	cost;
	t_ints		res;

	cost.uu = ft_max(a->up, target->up);
	cost.dd = ft_max(a->down, target->down);
	cost.ud = a->up + target->down;
	cost.du = a->down + target->up;
	ft_cost_supp(cost, a, target);
	a->route = res;
}				//? takes the top distance for a and b nodes traveling up or down, returns the opti route

void	ft_set_all_costs(t_ring *a)
{
	t_ring	*move;

	move = a->next;
	ft_cost(a, a->target);
	while (move != a)
	{
		ft_cost(move, move->target);
		move = move->next;
	}
}


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
	ft_printf(">%d	cost>%d\n", top->data, top->cost);
	while (move != top)
	{
		ft_printf(">%d	cost>%d\n", move->data, move->cost);
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

void	ft_one_target_a(t_ring *node, t_ring *b)
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
}						//? set the target of A "node" by checking all possible targets in B

void	ft_all_target_a(t_ring *a, t_ring *b)
{
	t_ring	*move;

	move = a->next;
	ft_one_target_a(a, b);
	while (move != a)
	{
		ft_one_target_a(move, b);
		move = move->next;
	}
}						//? uses the above function to set all targets in ring A

void	ft_one_target_b(t_ring *node, t_ring *a)
{
	t_ring	*target;
	t_ring	*move;

	target = a;
	move = a->next;
	while (move != a)
	{
		if (move->data > node->data && move->data < target->data)
			target = move;
		move = move->next;
	}
	node->target = target;
}						//? set the target of B "node" by checking all possible targets in A

void	ft_all_target_b(t_ring *a, t_ring *b)
{
	t_ring	*move;

	move = b->next;
	ft_one_target_b(b, a);
	while (move != b)
	{
		ft_one_target_b(move, a);
		move = move->next;
	}
}						//? uses the above function to set all targets in ring B

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

void	ft_ra(t_ring **a)
{
	*a = (*a)->next;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_ring **b)
{
	*b = (*b)->next;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_ring **a, t_ring **b)
{
	*a = (*b)->next;
	*b = (*b)->next;
	ft_putstr_fd("rr\n", 1);
}

void	ft_rra(t_ring **a)
{
	*a = (*a)->prev;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_ring **b)
{
	*b = (*b)->prev;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_ring **a, t_ring **b)
{
	*a = (*b)->prev;
	*b = (*b)->prev;
	ft_putstr_fd("rrr\n", 1);
}
t_ring *ft_find_cheapest(t_ring *a)
{
	t_ring *cheap;
	t_ring *move;

	cheap = a;
	move = a->next;
	while (move != a)
	{
		if (move->cost < cheap->cost)
			cheap = move;
		move = move->next;
	}
	return (cheap);
}


void ft_rotate_cheapest(t_ring **a, t_ring **b)
{
	t_ring *cheap;

	cheap = ft_find_cheapest(*a);
	while (cheap->route.a < 0 && cheap->route.target < 0)
		ft_rr(a, b);
	while (cheap->route.a > 0 && cheap->route.target > 0)
		ft_rrr(a, b);
	while (cheap->route.a < 0)
		ft_ra(a);
	while (cheap->route.a > 0)
		ft_rra(a);
	while (cheap->route.target < 0)
		ft_rb(b);
	while (cheap->route.target > 0)
		ft_rrb(b);
	
}

void	ft_choose_and_push_a(t_ring **a, t_ring **b)
{
	ft_all_target_a(*a, *b);
	ft_both_dist(*a);
	ft_both_dist(*b);
	ft_set_all_costs(*a);
	ft_rotate_cheapest
}

void	ft_order(t_ring **a, t_ring **b)
{
	if (ft_len_ring(*a) > 3)
		ft_push(a, b);
	if (ft_len_ring(*a) > 3)
		ft_push(a, b);
	while (ft_len_ring(a) > 3)	//TODO put back
		ft_choose_and_push_a(a, b);	//TODO put back
	// ft_all_target_a(*a, *b);	//! to test
	// ft_both_dist(*a);//!
	// ft_both_dist(*b);//!
	// ft_set_all_costs(*a);//!

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


