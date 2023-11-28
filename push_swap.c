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
#include "ft_libft.c"

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

	cost.uu = ft_max(a->up, target->up);
	cost.dd = ft_max(a->down, target->down);
	cost.ud = a->up + target->down;
	cost.du = a->down + target->up;
	ft_cost_supp(cost, a, target);
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

void	ft_print_ring(t_ring *top)
{
	t_ring	*move;

	if (!top)
	{
		ft_printf("NULL\n");
		return ;
	}
	ft_putchar_fd('\n', 1);
	move = top->next;
	ft_printf("> %d\n", top->data);
	while (move != top)
	{
		ft_printf("> %d\n", move->data);
		move = move->next;
	}
}			//? PRIIIIIIIIINT

void	ft_print_both(t_ring *a, t_ring *b)
{
	t_ring	*mv_a = NULL;
	t_ring	*mv_b = NULL;
	int		fa = 1;
	int		fb = 1;

	if (!a || !b)
	{
		if (!b)
			ft_print_ring(a);
		if (!a)
			ft_print_ring(b);
		return ;
	}
	ft_putchar_fd('\n', 1);
	ft_printf("A				B\n");
	mv_a = a->next;
	mv_b = b->next;
	ft_printf(">%d				%d\n", a->data, b->data);
	while (fa || fb)
	{
		if (mv_a == a)
			fa = 0;
		if (mv_b == b)
			fb = 0;
		if (fa && fb)
			ft_printf(">%d				%d\n", mv_a->data, mv_b->data);
		else if (fa)
			ft_printf(">%d\n", mv_a->data);
		else if (fb)
			ft_printf("				%d\n", mv_b->data);
		mv_a = mv_a->next;
		mv_b = mv_b->next;
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

void	ft_ra(t_ring **a)
{
	*a = (*a)->next;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_ring **b)
{
	*b = (*b)->next;
	// ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_ring **a, t_ring **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	// ft_putstr_fd("rr\n", 1);
}

void	ft_rra(t_ring **a)
{
	*a = (*a)->prev;
	// ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_ring **b)
{
	*b = (*b)->prev;
	// ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_ring **a, t_ring **b)
{
	*a = (*b)->prev;
	*b = (*b)->prev;
	// ft_putstr_fd("rrr\n", 1);
}

int	ft_is_sorted(t_ring *top)
{
	t_ring	*move;
	int		sort;

	if (!top)
		return (0);
	move = top->next;
	sort = 1;
	if (top->data > top->next->data)
		sort = 0;
	while (move->next != top)
	{
		if (move->data > move->next->data)
			sort = 0;
		move = move->next;
	}
	return (sort);
}					//? Returns 1 if sorted 0 if not

t_ring	*ft_find_smallest(t_ring *top)
{
	t_ring	*move;
	t_ring	*min;

	if (!top)
		return (0);
	move = top->next;
	min = top;
	while (move != top)
	{
		if (move->data < min->data)
			min = move;
		move = move->next;
	}
	return (min);
}

int	ft_size_final_rotate(t_ring	*top)
{
	int	up;
	int	down;
	t_ring	*move;
	t_ring	*smallest;

	smallest = ft_find_smallest(top);
	if (top == smallest)
		return (0);
	up = 1;
	down = 1;
	move = top->next;
	while (move != smallest)
	{
		down++;
		move = move->next;
	}
	move = top->prev;
	while (move != smallest)
	{
		up++;
		move = move->prev;
	}
	if (down < up)
		return(down);
	return (-up);
}

void	ft_final_rotate(t_ring	**top)
{
	int size;

	size = ft_size_final_rotate(*top);
	while (size < 0)
	{
		ft_rra(top);
		size++;
	}
	while (size > 0)
	{
		ft_ra(top);
		size--;
	}
}

int	ft_len_ring(t_ring *top)
{
	t_ring	*move;
	int		len;

	if (!top)
		return (0);
	move = top->next;
	len = 1;
	while (move && move != top)
	{
		len++;
		move = move->next;
	}
	return (len);
}						//? Returns the lenght of the ring

void	ft_remove_top(t_ring **top)
{
	// t_ring	*tmp;

	if (!(*top))
		return ;
	if ((*top) == (*top)->next)
	{
		// free (*top);
		(*top) = NULL;
		return ;
	}
	(*top)->next->prev = (*top)->prev;
	(*top)->prev->next = (*top)->next;
	// tmp = (*top);
	(*top) = (*top)->next;
	// free (tmp);
}						//? Remove the top node of a ring

// void	ft_one_target_a(t_ring *node, t_ring *b)
// {
// 	t_ring	*target;
// 	t_ring	*move;

// 	target = b;
// 	move = b->next;
// 	while (move != b)
// 	{
// 		if (move->data < node->data && move->data > target->data)
// 			target = move;
// 		move = move->next;
// 	}
// 	node->target = target;
// }						//? set the target of A "node" by checking all possible targets in B

void	ft_one_target_a(t_ring *node, t_ring *b)
{
	t_ring	*target;
	t_ring	*move;
	t_ring	*max;

	target = NULL;
	max = b;
	if (node->data > b->data)
		target = b;
	move = b->next;
	while (move != b)
	{
		if (node->data > move->data && (!target || move->data > target->data))
			target = move;
		if (move->data > max->data)
			max = move;
		move = move->next;
	}
	if (!target)
		target = max;
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

// void	ft_one_target_b(t_ring *node, t_ring *a)
// {
// 	t_ring	*target;
// 	t_ring	*move;

// 	target = a;
// 	move = a->next;
// 	while (move != a)
// 	{
// 		if (move->data > node->data && move->data < target->data)
// 			target = move;
// 		move = move->next;
// 	}
// 	node->target = target;
// }

void	ft_one_target_b(t_ring *node, t_ring *a)
{
	t_ring	*target;
	t_ring	*move;
	t_ring	*min;

	target = NULL;
	min = a;
	if (node->data < a->data)
		target = a;
	move = a->next;
	while (move != a)
	{
		if (node->data < move->data && (!target || move->data < target->data))
			target = move;
		if (move->data < min->data)
			min = move;
		move = move->next;
	}
	if (!target)
		target = min;
	node->target = target;
}						//? set the target of A "node" ay checking all possible targets in B

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

// void	ft_swap(t_ring **top)
// {
// 	int	one;
// 	int	two;

// 	one = (*top)->data;
// 	two = (*top)->next->data;
// 	ft_remove_top(top);
// 	ft_remove_top(top);
// 	ft_ring_push_top(top, one);
// 	ft_ring_push_top(top, two);
// 	ft_putstr("sa", 1);
// }

void	ft_push_a(t_ring **a, t_ring **b)
{
	t_ring	*top;

	top = *a;
	ft_remove_top(a);
	ft_ring_push_top(b, top->data);
	free (top);
	// ft_putstr_fd("pa\n", 1);
}						//? push first A node to B


void	ft_push_b(t_ring **a, t_ring **b)
{
	t_ring	*top;

	top = *b;
	ft_remove_top(b);
	ft_ring_push_top(a, top->data);
	free (top);
	// ft_putstr_fd("pb\n", 1);
}						//? push first B node to A

void ft_double_rotate(t_ring **a, t_ring **b, t_ring *cheap)
{
	while (cheap->route.a < 0 && cheap->route.target < 0)
	{
		ft_rr(a, b);
		cheap->route.a++;
		cheap->route.target++;
	}
	while (cheap->route.a > 0 && cheap->route.target > 0)
	{
		ft_rrr(a, b);
		cheap->route.a--;
		cheap->route.target--;
	}
}

void ft_single_rotate_a(t_ring **a, t_ring **b, t_ring *cheap)
{
	while (cheap->route.a < 0)
	{
		ft_ra(a);
		cheap->route.a++;
	}
	while (cheap->route.a > 0)
	{
		ft_rra(a);
		cheap->route.a--;
	}
	while (cheap->route.target < 0)
	{
		ft_rb(b);
		cheap->route.target++;
	}
	while (cheap->route.target > 0)
	{
		ft_rrb(b);
		cheap->route.target--;
	}
}

void ft_single_rotate_b(t_ring **a, t_ring **b, t_ring *cheap)
{
	while (cheap->route.a < 0)
	{
		ft_rb(b);
		cheap->route.a++;
	}
	while (cheap->route.a > 0)
	{
		ft_rrb(b);
		cheap->route.a--;
	}
	while (cheap->route.target < 0)
	{
		ft_ra(a);
		cheap->route.target++;
	}
	while (cheap->route.target > 0)
	{
		ft_rra(a);
		cheap->route.target--;
	}
}

void ft_rotate_cheapest_a(t_ring **a, t_ring **b)
{
	t_ring *cheap;

	cheap = ft_find_cheapest(*a);
	ft_double_rotate(a, b, cheap);
	ft_single_rotate_a(a, b, cheap);
}

void ft_rotate_cheapest_b(t_ring **a, t_ring **b)
{
	t_ring *cheap;

	cheap = ft_find_cheapest(*b);
	ft_double_rotate(a, b, cheap);
	ft_single_rotate_b(a, b, cheap);
}

void	ft_reset(t_ring *top)
{
	t_ring	*move;

	move = top->next;
	top->cost = 0;
	top->up = 0;
	top->down = 0;
	top->route.a = 0;
	top->route.target = 0;
	while (move && move != top)
	{
		move->cost = 0;
		move->up = 0;
		move->down = 0;
		move->route.a = 0;
		move->route.target = 0;
		move = move->next;
	}
}

void	ft_choose_and_push_a(t_ring **a, t_ring **b)
{
	if (!b || !a)
		return;
	ft_reset(*a);
	ft_reset(*b);
	ft_print_both(*a, *b);	//!
	ft_all_target_a(*a, *b);
	ft_both_dist(*a);
	ft_both_dist(*b);
	ft_set_all_costs(*a);
	ft_rotate_cheapest_a(a, b);
	ft_push_a(a, b);
}

void	ft_choose_and_push_b(t_ring **a, t_ring **b)
{
	if (!b || !a)
		return;
	ft_reset(*a);
	ft_reset(*b);
	ft_all_target_b(*a, *b);
	ft_both_dist(*a);
	ft_both_dist(*b);
	ft_set_all_costs(*b);
	ft_rotate_cheapest_b(a, b);
	ft_push_b(a, b);
	// ft_print_both(*a, *b);	//!
}

// void	ft_swap(t_ring **top)
// {
// 	int	one;
// 	int	two;

// 	one = (*top)->data;
// 	two = (*top)->next->data;
// 	ft_print_ring(*top);	//!
// 	ft_remove_top(top);
// 	ft_print_ring(*top);	//!
// 	ft_remove_top(top);
// 	ft_print_ring(*top);	//!
// 	ft_ring_push_top(top, one);
// 	ft_print_ring(*top);	//!
// 	ft_ring_push_top(top, two);
// 	ft_print_ring(*top);	//!
// 	ft_putstr_fd("sa", 1);
// }

void	ft_swap(t_ring **top)
{
	t_ring	*tmp;
	t_ring	*two;
	t_ring	*three;

	two = (*top)->next;
	three = (*top)->next->next;
	tmp = (*top)->next;
	(*top)->next = (*top)->prev;
	(*top)->prev = tmp;
	tmp = two->next;
	two->next = two->prev;
	two->prev = tmp;
	tmp = three->next;
	three->next = three->prev;
	three->prev = tmp;
	*top = two;
}

void ft_order_three_suport(t_ring **a, int min, int max)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->data;
	two = (*a)->next->data;
	three = (*a)->next->next->data;

	if (one == max && two == min)
		ft_ra(a);
	else if (two == max && three == min)
		ft_rra(a);
	else if (two == min && three == max)
		ft_swap(a);
	else if (one == min && two == max)
	{
		ft_swap(a);
		ft_ra(a);
	}
	else if (one == max && three == min)
	{
		ft_swap(a);
		ft_rra(a);
	}
}

void	ft_order_three(t_ring **a)
{
	int	max;
	int min;
	t_ring *move;

	max = (*a)->data;
	min = (*a)->data;
	move = (*a)->next;
	while (move != *a)
	{
		if (max < move->data)
			max = move->data;
		if (min > move->data)
			min = move->data;
		move = move->next;
	}
	ft_order_three_suport(a, min, max);
}

void	ft_order(t_ring **a, t_ring **b)
{
	if (ft_len_ring(*a) > 3)
		ft_push_a(a, b);
	if (ft_len_ring(*a) > 3)
		ft_push_a(a, b);
	while (ft_len_ring(*a) > 3)	//TODO put back
		ft_choose_and_push_a(a, b);	//TODO put back

	
	ft_order_three(a);
	ft_print_both(*a, *b);	//!
	while (ft_len_ring(*b) > 0)
		ft_choose_and_push_b(a, b);
	ft_print_ring(*a);
	ft_printf("sizer:%d", ft_size_final_rotate(*a));
	ft_final_rotate(a);

}

int main(int ac, char **av)
{
	t_ring	*a;
	t_ring	*b;

	a = NULL;
	b = NULL;
	ac = 2;						//! delete
	av[1] = "1 2 4 -2 -9 0 11 7 75 45 3 -100"	;	//! delete
	if (ac < 2)
		return (1);
	ft_parse_args(ac, av, &a);
	if (a && ft_check_double(&a))
	{
		ft_clear_ring(&a);
		ft_putstr_fd("Error: Duplicate numbers in arguments.", 2);
	}
	// ft_printf("len is %d\n", ft_len_ring(a));	//! delete
	if (!ft_is_sorted(a))
		ft_order(&a, &b);
	// if (ft_len_ring(a) <= 3)	//?
	// 	ft_order_small(&a);		//?
	// if (ft_len_ring(a) > 3)	//? else if
	// 	ft_order(&a, &b);
	// ft_print_both(a, b); 		//! delete
	// ft_putchar_fd('\n', 1);
	ft_print_ring(a);	//! delete
	// ft_printf("len is %d\n", ft_len_ring(a));
	ft_clear_ring(&a);
	ft_clear_ring(&b);
	return (0);
}


