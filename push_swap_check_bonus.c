/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:07:25 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 18:44:34 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
**Checks for any duplicate ints
*/
int	ft_check_double(t_ring **top)
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

/*
**Returns 1 if sorted 0 if not
*/
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
}
