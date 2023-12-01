/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:10:27 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/12/01 09:14:26 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_ints
{
	int	a;
	int	target;
}	t_ints;

typedef struct s_ring
{
	struct s_ring	*next;
	struct s_ring	*prev;
	struct s_ring	*target;
	struct s_ints	route;
	int				up;
	int				down;
	int				cost;
	int				data;
}	t_ring;

typedef struct s_updown
{
	int	uu;
	int	dd;
	int	ud;
	int	du;
}	t_updown;

void	ft_ra(t_ring **a);
void	ft_rra(t_ring **a);
void	ft_rr(t_ring **a, t_ring **b);
void	ft_push_a(t_ring **a, t_ring **b);
void	ft_swap_a(t_ring **top);
void	ft_rb(t_ring **b);
void	ft_rrb(t_ring **b);
void	ft_rrr(t_ring **a, t_ring **b);
void	ft_remove_top(t_ring **top);
void	ft_push_b(t_ring **a, t_ring **b);
int		ft_check_double(t_ring **top);
int		ft_is_sorted(t_ring *top);
int		ft_len_ring(t_ring *top);
void	ft_set_all_costs(t_ring *a);
void	ft_final_rotate(t_ring **top);
void	ft_parse_args(int ac, char **av, t_ring **top);
void	ft_ring_push_top(t_ring **top, int data);
void	ft_ring_push_back(t_ring **top, int data);
void	ft_clear_ring(t_ring **top);
void	ft_rotate_cheapest_a(t_ring **a, t_ring **b);
void	ft_rotate_cheapest_b(t_ring **a, t_ring **b);
void	ft_all_target_a(t_ring *a, t_ring *b);
void	ft_all_target_b(t_ring *a, t_ring *b);
void	ft_both_dist(t_ring *top);
t_ring	*ft_find_cheapest(t_ring *a);
void	ft_reset(t_ring *top);
void	ft_order_three(t_ring **a);
int		main(int ac, char **av);

#endif