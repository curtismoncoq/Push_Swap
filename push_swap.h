/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:10:27 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/29 18:17:02 by cumoncoq         ###   ########.fr       */
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
int		ft_max(int x, int y);
int		ft_min(int x, int y);
void	ft_cost_supp(t_updown cost, t_ring *a, t_ring *target);
void	ft_cost(t_ring *a, t_ring *target);
void	ft_set_all_costs(t_ring *a);
t_ring	*ft_find_smallest(t_ring *top);
int		ft_size_final_rotate(t_ring *top);
void	ft_final_rotate(t_ring **top);
long	ft_long_atoi(const char *str);
int		ft_valid_str(char *str);
int		ft_valid_stack(int ac, char **stack);
void	ft_free_split(char **split);
void	ft_parse_args(int ac, char **av, t_ring **top);
t_ring	*ft_create_element(int data);
void	ft_ring_push_top(t_ring **top, int data);
void	ft_ring_push_back(t_ring **top, int data);
void	ft_clear_ring(t_ring **top);
void	ft_double_rotate(t_ring **a, t_ring **b, t_ring *cheap);
void	ft_single_rotate_a(t_ring **a, t_ring **b, t_ring *cheap);
void	ft_single_rotate_b(t_ring **a, t_ring **b, t_ring *cheap);
void	ft_rotate_cheapest_a(t_ring **a, t_ring **b);
void	ft_rotate_cheapest_b(t_ring **a, t_ring **b);
void	ft_one_target_a(t_ring *node, t_ring *b);
void	ft_all_target_a(t_ring *a, t_ring *b);
void	ft_one_target_b(t_ring *node, t_ring *a);
void	ft_all_target_b(t_ring *a, t_ring *b);
void	ft_both_dist(t_ring *top);
t_ring	*ft_find_cheapest(t_ring *a);
void	ft_reset(t_ring *top);
void	ft_order_three_suport(t_ring **a, int min, int max);
void	ft_order_three(t_ring **a);
void	ft_choose_and_push_a(t_ring **a, t_ring **b);
void	ft_choose_and_push_b(t_ring **a, t_ring **b);
void	ft_order(t_ring **a, t_ring **b);
int		main(int ac, char **av);

#endif