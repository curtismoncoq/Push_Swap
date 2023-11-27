/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:00 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 22:33:24 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*move;

	if (!lst)
		return ;
	if (*lst)
	{
		move = *lst;
		while (move->next)
			move = move->next;
		move->next = new;
	}
	else
		*lst = new;
}
