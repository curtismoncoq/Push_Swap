/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:16:10 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/29 23:56:29 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stash	*ft_stash_to_line(int fd, char *line, t_stash *stash, int len)
{
	t_fill	x;

	x.found = 0;
	x.j = 0;
	while (stash && !x.found)
	{
		x.i = 0;
		if (fd == stash->fd)
		{
			while (stash && stash->text[x.i] && x.j < len)
			{
				if (stash->text[x.i] == '\n')
					x.found = x.i + 1;
				line[x.j++] = stash->text[x.i++];
			}
			if (stash->end)
				if (!x.found)
					x.found = -1;
			x.last = stash;
		}
		stash = stash->next;
	}
	if (x.found > 0 && x.last->text[x.found] && (BUFFER_SIZE - x.found) && len)
		return (ft_create(fd, x.last->text + x.found, x.last->end));
	return (NULL);
}

int	ft_line_len(int fd, t_stash *stash, int result, int found)
{
	int	i;

	while (stash && !found)
	{
		i = -1;
		if (fd == stash->fd)
		{
			while (stash && stash->text[++i] && !found)
			{
				if (stash->text[i] == '\n' && !found)
				{
					result += i + 1;
					found = 1;
				}
			}
			if (stash && !found)
				result += i;
			if (stash->end)
				found = 1;
		}
		stash = stash->next;
	}
	return (result);
}

t_stash	*ft_fill_line(int fd, char **line, t_stash *stash)
{
	int	len;
	int	i;

	i = 0;
	if (!line || !stash)
		return (NULL);
	len = ft_line_len(fd, stash, 0, 0);
	*line = (char *)malloc(sizeof(**line) * len + 1);
	while (i <= len)
		(*line)[i++] = 0;
	return (ft_stash_to_line(fd, *line, stash, len));
}

void	ft_fill_stash(t_fdo g, char *buffer, char **line, t_stash **stash)
{
	t_stash	*rest;

	while (!ft_check_newline(g.fd, *stash) && g.bytes)
	{
		rest = *stash;
		g.bytes = read(g.fd, buffer, BUFFER_SIZE);
		if (g.bytes == -1)
			return (ft_clear_stash(g.fd, stash));
		buffer[g.bytes] = 0;
		while (rest)
		{
			if (rest->fd == g.fd)
				g.o++;
			rest = rest->next;
		}
		if (g.bytes || g.o)
			ft_add_back(stash, ft_create(g.fd, buffer, BUFFER_SIZE - g.bytes));
	}
	if (ft_check_newline(g.fd, *stash))
	{
		rest = ft_fill_line(g.fd, line, *stash);
		ft_clear_stash(g.fd, stash);
		ft_add_back(stash, rest);
	}
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static t_stash	*stash;
	t_fdo			g;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		ft_clear_stash(fd, &stash);
		return (NULL);
	}
	g.bytes = 1;
	g.fd = fd;
	g.o = 0;
	buffer = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
	line = NULL;
	if (!buffer)
		return (NULL);
	ft_fill_stash(g, buffer, &line, &stash);
	free(buffer);
	return (line);
}
