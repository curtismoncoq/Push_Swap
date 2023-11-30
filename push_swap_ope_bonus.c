/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ope_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:05:11 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 18:04:47 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rx(t_ring **top)
{
	if (!(*top))
		return ;
	*top = (*top)->next;
}

void	ft_rrx(t_ring **top)
{
	if (!(*top))
		return ;
	*top = (*top)->prev;
}

void	ft_rr(t_ring **a, t_ring **b)
{
	if (!(*a) || !(*b))
		return ; 
	*a = (*a)->next;
	*b = (*b)->next;
}

void	ft_push(t_ring **a, t_ring **b)
{
	t_ring	*top;

	top = *b;
	ft_remove_top(b);
	if (top)
	{
		ft_ring_push_top(a, top->data);
		free(top);
	}
}

// void	ft_swap(t_ring **top)
// {
// 	t_ring	*tmp;
// 	t_ring	*two;
// 	t_ring	*three;

// 	if (!(*top))
// 		return ;
// 	two = (*top)->next;
// 	three = (*top)->next->next;
// 	tmp = (*top)->next;
// 	(*top)->next = (*top)->prev;
// 	(*top)->prev = tmp;
// 	tmp = two->next;
// 	two->next = two->prev;
// 	two->prev = tmp;
// 	tmp = three->next;
// 	three->next = three->prev;
// 	three->prev = tmp;
// 	*top = two;
// }

void ft_swap(t_ring **top)
{
	int tmp;

	tmp = (*top)->data;
	(*top)->data = (*top)->next->data;
	(*top)->next->data = tmp;
}
