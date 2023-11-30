/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tasks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:40:15 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 22:55:53 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_order_three_suport(t_ring **a, int min, int max)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->data;
	two = (*a)->next->data;
	three = (*a)->next->next->data;
	if (one == max && two == min)
		ft_rx(a);
	else if (two == max && three == min)
		ft_rrx(a);
	else if (two == min && three == max)
		ft_swap(a);
	else if (one == min && two == max)
	{
		ft_swap(a);
		ft_rx(a);
	}
	else if (one == max && three == min)
	{
		ft_swap(a);
		ft_rrx(a);
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

void	ft_rrr(t_ring **a, t_ring **b)
{
	if (!(*a) || !(*b))
		return ;
	*a = (*a)->prev;
	*b = (*b)->prev;
	ft_putstr_fd("rrr\n", 1);
}

/*
**Remove the top node of a ring
*/
void	ft_remove_top(t_ring **top)
{
	if (!(*top))
		return ;
	if ((*top) == (*top)->next)
	{
		(*top) = NULL;
		return ;
	}
	(*top)->next->prev = (*top)->prev;
	(*top)->prev->next = (*top)->next;
	(*top) = (*top)->next;
}
