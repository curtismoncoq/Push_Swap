/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:03:30 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 19:52:39 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static long	ft_long_atoi(const char *str)
{
	int		i;
	int		sign;
	long	x;

	x = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		x *= 10;
		x += str[i] - 48;
		i++;
	}
	return (x * sign);
}
/*
**Checks for validity of a string according to long_atoi rules
*/
static int	ft_valid_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (!i)
		return (0);
	return (1);
}

/*
**Checks for INTMIN/MAX or non-ints in the stack of strings
*/
static int	ft_valid_stack(int ac, char **stack)
{
	int		i;
	long	a;

	i = 0;
	while (stack[i] && (i < ac || ac == 2))
	{
		if (!ft_valid_str(stack[i]))
			return (0);
		i++;
	}
	i = 0;
	while (stack[i] && (i < ac || ac == 2))
	{
		a = ft_long_atoi(stack[i]);
		if (a > INT_MAX || a < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

/*
**Free the split used to parse
*/
static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*
**Parse args and converts them to the A ring if it's only valid integers
*/
void	ft_parse_args(int ac, char **av, t_ring **top)
{
	int		i;
	char	**stack;

	i = 0;
	stack = NULL;
	if (ac == 2)
		stack = ft_split(av[1], ' ');
	else if (ac > 2)
		stack = av + 1;
	if (!ft_valid_stack(ac, stack))
	{
		ft_putstr_fd("Error\n", 2);
		if (ac == 2)
			ft_free_split(stack);
		return ;
	}
	while (stack[i] && (i < ac || ac == 2))
	{
		ft_ring_push_back(top, ft_long_atoi(stack[i]));
		i++;
	}
	if (ac == 2)
		ft_free_split(stack);
}
