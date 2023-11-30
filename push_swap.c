/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:37:16 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 19:56:10 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_choose_and_push_a(t_ring **a, t_ring **b)
{
	if (!b || !a)
		return ;
	ft_reset(*a);
	ft_reset(*b);
	ft_all_target_a(*a, *b);
	ft_both_dist(*a);
	ft_both_dist(*b);
	ft_set_all_costs(*a);
	ft_rotate_cheapest_a(a, b);
	ft_push_b(a, b);
}

static void	ft_choose_and_push_b(t_ring **a, t_ring **b)
{
	if (!b || !a)
		return ;
	ft_reset(*a);
	ft_reset(*b);
	ft_all_target_b(*a, *b);
	ft_both_dist(*a);
	ft_both_dist(*b);
	ft_set_all_costs(*b);
	ft_rotate_cheapest_b(a, b);
	ft_push_a(a, b);
}

static void	ft_order(t_ring **a, t_ring **b)
{
	if (ft_len_ring(*a) > 3)
		ft_push_b(a, b);
	if (ft_len_ring(*a) > 3)
		ft_push_b(a, b);
	while (ft_len_ring(*a) > 3)
		ft_choose_and_push_a(a, b);
	ft_order_three(a);
	while (ft_len_ring(*b) > 0)
		ft_choose_and_push_b(a, b);
	ft_final_rotate(a);
}

int	main(int ac, char **av)
{
	t_ring	*a;
	t_ring	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	ft_parse_args(ac, av, &a);
	if (a && ft_check_double(&a))
	{
		ft_clear_ring(&a);
		ft_putstr_fd("Error\n", 2);
	}
	if (!ft_is_sorted(a))
	{
		if (ft_len_ring(a) > 3)
			ft_order(&a, &b);
		else if (ft_len_ring(a) == 3)
			ft_order_three(&a);
		else if (ft_len_ring(a) == 2)
			ft_swap_a(&a);
	}
	ft_clear_ring(&a);
	ft_clear_ring(&b);
	return (0);
}
