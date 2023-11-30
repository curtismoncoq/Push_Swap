/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:57:10 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/29 23:56:24 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stash	*ft_create(int fd, char *buffer, int end)
{
	t_stash	*n;
	int		i;

	i = 0;
	n = (t_stash *)malloc(sizeof(t_stash));
	if (!n)
		return (NULL);
	n->text = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
	if (!n->text)
	{
		free(n);
		return (NULL);
	}
	while (i < BUFFER_SIZE && buffer[i])
	{
		n->text[i] = buffer[i];
		i++;
	}
	n->text[i] = 0;
	n->fd = fd;
	n->next = NULL;
	n->end = end;
	return (n);
}

void	ft_add_back(t_stash **stash, t_stash *n)
{
	t_stash	*move;

	if (*stash)
	{
		move = *stash;
		while (move->next)
			move = move->next;
		move->next = n;
	}
	else
		*stash = n;
}

int	ft_check_newline(int fd, t_stash *stash)
{
	int	i;
	int	found;

	found = 0;
	while (stash)
	{
		i = -1;
		if (fd == stash->fd)
		{
			while (stash && stash->text[++i] && !found)
				if (stash->text[i] == '\n' && !found)
					found = 1;
			if (stash->end)
				found = 1;
		}
		stash = stash->next;
	}
	return (found);
}

void	ft_free_text(t_stash *tmp)
{
	if (tmp->text)
		free(tmp->text);
	tmp->text = NULL;
	if (tmp)
		free(tmp);
	tmp = NULL;
}

void	ft_clear_stash(int fd, t_stash **stash)
{
	t_stash	*tmp;
	t_stash	*prev;

	while (*stash && (*stash)->fd == fd)
	{
		tmp = *stash;
		*stash = (*stash)->next;
		ft_free_text(tmp);
	}
	tmp = *stash;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			prev->next = tmp->next;
			ft_free_text(tmp);
			tmp = prev->next;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
