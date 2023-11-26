/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:10:27 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/26 23:17:26 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_ring
{
	struct s_ring	*next;
	struct s_ring	*prev;
	struct s_ring	*target;
	int 			up;
	int 			down;
	int				cost;
	int				data;
}	t_ring;

typedef struct s_ints
{
	int	a;
	int b;
	int min;
}	t_ints;

typedef struct s_updown
{
	int uu;
	int dd;
	int ud;
	int du;
}	t_updown;

#endif