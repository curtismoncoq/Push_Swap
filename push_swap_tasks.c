/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tasks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:15 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 19:58:20 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**sets each nodes [up/down distances] in a ring
*/
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
}

t_ring	*ft_find_cheapest(t_ring *a)
{
	t_ring	*cheap;
	t_ring	*move;

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

static void	ft_order_three_suport(t_ring **a, int min, int max)
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
		ft_swap_a(a);
	else if (one == min && two == max)
	{
		ft_swap_a(a);
		ft_ra(a);
	}
	else if (one == max && three == min)
	{
		ft_swap_a(a);
		ft_rra(a);
	}
}

void	ft_order_three(t_ring **a)
{
	int		max;
	int		min;
	t_ring	*move;

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
