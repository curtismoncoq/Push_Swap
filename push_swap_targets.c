/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_targets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:10:04 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/29 13:11:58 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
