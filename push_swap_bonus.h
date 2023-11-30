/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:10:27 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 15:54:09 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"

// typedef struct s_ints
// {
// 	int	a;
// 	int	target;
// }	t_ints;

typedef struct s_ring
{
	int				data;
	struct s_ring	*next;
	struct s_ring	*prev;
}	t_ring;

// typedef struct s_ring
// {
// 	struct s_ring	*next;
// 	struct s_ring	*prev;
// 	struct s_ring	*target;
// 	struct s_ints	route;
// 	int				up;
// 	int				down;
// 	int				cost;
// 	int				data;
// }	t_ring;

// typedef struct s_updown
// {
// 	int	uu;
// 	int	dd;
// 	int	ud;
// 	int	du;
// }	t_updown;

void	ft_rx(t_ring **top);
void	ft_rrx(t_ring **top);
void	ft_rr(t_ring **a, t_ring **b);
void	ft_push(t_ring **a, t_ring **b);
void	ft_swap(t_ring **top);
void	ft_rrr(t_ring **a, t_ring **b);
void	ft_remove_top(t_ring **top);
int		ft_check_double(t_ring **top);
int		ft_is_sorted(t_ring *top);
long	ft_long_atoi(const char *str);
int		ft_valid_str(char *str);
int		ft_valid_stack(int ac, char **stack);
void	ft_free_split(char **split);
void	ft_parse_args(int ac, char **av, t_ring **top);
t_ring	*ft_create_element(int data);
void	ft_ring_push_top(t_ring **top, int data);
void	ft_ring_push_back(t_ring **top, int data);
void	ft_clear_ring(t_ring **top);
void	ft_order_three_suport(t_ring **a, int min, int max);
void	ft_order_three(t_ring **a);

#endif