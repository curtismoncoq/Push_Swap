/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ring_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:01:57 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 19:15:36 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_ring	*ft_create_element(int data)
{
	t_ring	*n;

	n = (t_ring *)malloc(sizeof(t_ring));
	if (!n)
		return (NULL);
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

/*
**Push a node to the top
*/
void	ft_ring_push_top(t_ring **top, int data)
{
	t_ring	*n;

	n = ft_create_element(data);
	if (n)
	{
		if (*top)
		{
			n->next = *top;
			n->prev = (*top)->prev;
			n->prev->next = n;
			(*top)->prev = n;
		}
		else
		{
			n->next = n;
			n->prev = n;
		}
		*top = n;
	}
}

/*
**Push a node to the bottom
*/
void	ft_ring_push_back(t_ring **top, int data)
{
	t_ring	*n;

	n = ft_create_element(data);
	if (n)
	{
		if (*top)
		{
			n->next = *top;
			n->prev = (*top)->prev;
			n->prev->next = n;
			(*top)->prev = n;
		}
		else
		{
			n->next = n;
			n->prev = n;
			*top = n;
		}
	}
}

/*
**Free all nodes in a ring set top to NULL
*/
void	ft_clear_ring(t_ring **top)
{
	t_ring	*move;
	t_ring	*tmp;

	if (!(*top))
		return ;
	move = (*top)->next;
	while (move != *top)
	{
		tmp = move;
		move = move->next;
		free (tmp);
	}
	free(*top);
	*top = NULL;
}
