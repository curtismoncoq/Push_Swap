/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b_ope.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:05:11 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 19:54:06 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_ring **b)
{
	*b = (*b)->next;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rrb(t_ring **b)
{
	*b = (*b)->prev;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_ring **a, t_ring **b)
{
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

void	ft_push_b(t_ring **a, t_ring **b)
{
	t_ring	*top;

	top = *a;
	ft_remove_top(a);
	ft_ring_push_top(b, top->data);
	free(top);
	ft_putstr_fd("pb\n", 1);
}
