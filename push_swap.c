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
}

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
}

// void	ft_rotate_printer(t_ints res)
// {
	
// }

void	ft_print_ring(t_ring *top)
{
	t_ring	*move;

	if (!top)
	{
		printf("NULL\n");
		return ;
	}
	move = top->next;
	printf(">%d	next>%d\n", top->data, top->next->data);
	while (move != top)
	{
		printf(">%d	next>%d\n", move->data, move->next->data);
		move = move->next;
	}
}

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
}

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
}

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
}

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
}

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
}

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
}

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
}

int main(int ac, char **av)
{
	t_ring	*top;

	top = NULL;
	if (ac < 2 && av[0] == 0)
		return (1);
	ft_parse_args(ac, av, &top);
	if (ft_check_double(&top))
	{
		ft_clear_ring(&top);
		ft_putstr_fd("Error: Duplicate numbers in arguments.", 2);
	}
	// ft_ring_push_back(&top, 1);
	// ft_ring_push_back(&top, 8);
	// ft_ring_push_back(&top, 5);
	// ft_ring_push_back(&top, 3);
	// ft_ring_push_top(&top, 2);
	ft_print_ring(top);
	ft_clear_ring(&top);
	ft_print_ring(top);
	return (0);
}


