/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:13:41 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/29 14:38:46 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_double_rotate(t_ring **a, t_ring **b, t_ring *cheap)
{
	while (cheap->route.a < 0 && cheap->route.target < 0)
	{
		ft_rr(a, b);
		cheap->route.a++;
		cheap->route.target++;
	}
	while (cheap->route.a > 0 && cheap->route.target > 0)
	{
		ft_rrr(a, b);
		cheap->route.a--;
		cheap->route.target--;
	}
}

void ft_single_rotate_a(t_ring **a, t_ring **b, t_ring *cheap)
{
	while (cheap->route.a < 0)
	{
		ft_ra(a);
		cheap->route.a++;
	}
	while (cheap->route.a > 0)
	{
		ft_rra(a);
		cheap->route.a--;
	}
	while (cheap->route.target < 0)
	{
		ft_rb(b);
		cheap->route.target++;
	}
	while (cheap->route.target > 0)
	{
		ft_rrb(b);
		cheap->route.target--;
	}
}

void ft_single_rotate_b(t_ring **a, t_ring **b, t_ring *cheap)
{
	while (cheap->route.a < 0)
	{
		ft_rb(b);
		cheap->route.a++;
	}
	while (cheap->route.a > 0)
	{
		ft_rrb(b);
		cheap->route.a--;
	}
	while (cheap->route.target < 0)
	{
		ft_ra(a);
		cheap->route.target++;
	}
	while (cheap->route.target > 0)
	{
		ft_rra(a);
		cheap->route.target--;
	}
}

void ft_rotate_cheapest_a(t_ring **a, t_ring **b)
{
	t_ring *cheap;

	cheap = ft_find_cheapest(*a);
	ft_double_rotate(a, b, cheap);
	ft_single_rotate_a(a, b, cheap);
}

void ft_rotate_cheapest_b(t_ring **a, t_ring **b)
{
	t_ring *cheap;

	cheap = ft_find_cheapest(*b);
	ft_double_rotate(a, b, cheap);
	ft_single_rotate_b(a, b, cheap);
}