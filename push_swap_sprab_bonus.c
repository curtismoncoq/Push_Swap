/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sprab_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:31:34 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 19:48:47 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int ft_is_s(char *ope)
{
	if (ope[1] == 'a' && (!ope[2] || ope[2] == '\n'))
		return (1);
	if (ope[1] == 'b'&& (!ope[2] || ope[2] == '\n'))
		return (2);
	if (ope[1] == 's'&& (!ope[2] || ope[2] == '\n'))
		return (3);
	return (0);
}

static int ft_is_p(char *ope)
{
	if (ope[1] == 'a' && (!ope[2] || ope[2] == '\n'))
		return (4);
	if (ope[1] == 'b' && (!ope[2] || ope[2] == '\n'))
		return (5);
	return (0);
}

static int ft_is_rr(char *ope)
{
	if (ope[2] == 'a' && (!ope[3] || ope[3] == '\n'))
		return (9);
	if (ope[2] == 'b'&& (!ope[3] || ope[3] == '\n'))
		return (10);
	if (ope[2] == 'r'&& (!ope[3] || ope[3] == '\n'))
		return (11);
	return (0);
}

static int ft_is_r(char *ope)
{
	if (ope[1] == 'a' && (!ope[2] || ope[2] == '\n'))
		return (6);
	if (ope[1] == 'b'&& (!ope[2] || ope[2] == '\n'))
		return (7);
	if (ope[1] == 'r')
	{
		if(!ope[2] || ope[2] == '\n')
			return (8);
		else
			return(ft_is_rr(ope));
	}
	return (0);
}

int	ft_is_operation(char *ope)
{
	if (!ope)
		return (12);
	if (ope[0] == 's')
		return (ft_is_s(ope));
	if (ope[0] == 'p')
		return (ft_is_p(ope));
	if (ope[0] == 'r')
		return (ft_is_r(ope));
	return (0);
}
