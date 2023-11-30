/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:59:43 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 18:47:02 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

static int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

/*
**negative value means going up positive means going down
*/
static void	ft_cost_supp(t_updown cost, t_ring *a, t_ring *target)
{
	a->cost = ft_min(ft_min(cost.uu, cost.dd), ft_min(cost.ud, cost.du));
	if (cost.uu == a->cost)
	{
		a->route.a = -a->up;
		a->route.target = -target->up;
	}
	else if (cost.dd == a->cost)
	{
		a->route.a = a->down;
		a->route.target = target->down;
	}
	else if (cost.du == a->cost)
	{
		a->route.a = a->down;
		a->route.target = -target->up;
	}
	else if (cost.ud == a->cost)
	{
		a->route.a = -a->up;
		a->route.target = target->down;
	}
}

/*
**takes distance for a and b nodes returns the opti route
*/
static void	ft_cost(t_ring *a, t_ring *target)
{
	t_updown	cost;

	cost.uu = ft_max(a->up, target->up);
	cost.dd = ft_max(a->down, target->down);
	cost.ud = a->up + target->down;
	cost.du = a->down + target->up;
	ft_cost_supp(cost, a, target);
}

void	ft_set_all_costs(t_ring *a)
{
	t_ring		*move;

	move = a->next;
	ft_cost(a, a->target);
	while (move != a)
	{
		ft_cost(move, move->target);
		move = move->next;
	}
}
