/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:37:16 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 19:47:41 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_list	*ft_get_operations(void)
{
	t_list	*list;
	char	*line;
	int		nl;

	nl = 1;
	list = NULL;
	line = NULL;
	while (nl)
	{
		line = get_next_line(0);
		if (!line || line[ft_strlen(line) - 1] != '\n')
			nl = 0;
		ft_lstadd_back(&list, ft_lstnew(line));
	}

	return (list);
}

static void	ft_apply(t_ring **a, t_ring **b, int ope)
{
	if (ope == 1)
		ft_swap(a);
	if (ope == 2)
		ft_swap(b);
	if (ope == 3)
	{
		ft_swap(a);
		ft_swap(b);
	}
	if (ope == 4)
		ft_push(a, b);
	if (ope == 5)
		ft_push(b, a);
	if (ope == 6)
		ft_rx(a);
	if (ope == 7)
		ft_rx(b);
	if (ope == 8)
		ft_rr(a, b);
	if (ope == 9)
		ft_rrx(a);
	if (ope == 10)
		ft_rrx(b);
	if (ope == 11)
		ft_rrr(a, b);
}

static int	ft_follow_operations(t_ring **a, t_ring **b)
{
	t_list	*ope_list;
	t_list	*move;

	ope_list = ft_get_operations();
	move = ope_list;
	while (move)
	{
		if (!ft_is_operation(move->content))
		{
			ft_putstr_fd("Error\n", 2);
			ft_lstclear(&ope_list, free);
			return (0);
		}
		move = move->next;
	}
	move = ope_list;
	while(move)
	{
		ft_apply(a, b, ft_is_operation(move->content));
		move = move->next;
	}
	return (1);
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
	else if (a)
	{
		ft_follow_operations(&a, &b);
		if (ft_is_sorted(a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	ft_clear_ring(&a);
	ft_clear_ring(&b);
	return (0);
}
