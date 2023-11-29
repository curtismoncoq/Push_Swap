/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:08:26 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/29 18:06:38 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_size_final_rotate(t_ring *top)
{
	int		up;
	int		down;
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
		return (down);
	return (-up);
}

void	ft_final_rotate(t_ring **top)
{
	int	size;

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
