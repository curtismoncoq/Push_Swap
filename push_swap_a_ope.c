/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_ope.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:05:11 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/29 14:39:12 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ra(t_ring **a)
{
	*a = (*a)->next;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rra(t_ring **a)
{
	*a = (*a)->prev;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rr(t_ring **a, t_ring **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_putstr_fd("rr\n", 1);
}

void	ft_push_a(t_ring **a, t_ring **b)
{
	t_ring	*top;

	top = *b;
	ft_remove_top(b);
	ft_ring_push_top(a, top->data);
	free (top);
	ft_putstr_fd("pa\n", 1);
}						//? push first B node to A

void	ft_swap_a(t_ring **top)
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
	ft_putstr_fd("sa\n", 1);
}