/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:19:20 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 22:28:32 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(const char *str, char c)
{
	int	i;
	int	words;
	int	nw;

	i = 0;
	words = 0;
	nw = 1;
	while (str[i])
	{
		if (c != str[i] && nw == 1)
		{
			nw = 0;
			words++;
		}
		if (c == str[i])
			nw = 1;
		i++;
	}
	return (words);
}

static	void	ft_fill_tab(const char *str, char c, char **tab, int *lens)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (lens[i])
	{
		while (c == str[s])
			s++;
		j = 0;
		while (j < lens[i])
			tab[i][j++] = str[s++];
		tab[i++][j] = 0;
	}
}

static	void	ft_words_len(const char *str, char c, int *lens)
{
	int	i;
	int	d;
	int	nw;
	int	index;

	i = -1;
	nw = 1;
	index = -1;
	while (str[++i])
	{
		if (c == str[i] && !nw)
		{
			lens[index] = i - d;
			nw = 1;
		}
		else if (c != str[i] && nw)
		{
			index++;
			d = i;
			nw = 0;
		}
	}
	if (nw == 0)
		lens[index] = i - d;
	lens[index + 1] = 0;
}

static int	ft_free_if(char **tab, int word)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (tab && i < word)
	{
		if (!tab[i])
			f = 1;
		i++;
	}
	i = 0;
	if (f)
	{
		while (tab && i < word)
		{
			if (tab[i])
				free (tab[i]);
			i++;
		}
		free (tab);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		*lens;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	word = ft_count_words(s, c);
	tab = (char **)ft_calloc(sizeof(*tab), (word + 1));
	if (!tab)
		return (NULL);
	lens = (int *)ft_calloc(sizeof(*lens), (word + 1));
	ft_words_len(s, c, lens);
	while (++i < word)
		tab[i] = (char *)ft_calloc(sizeof(**tab), lens[i] + 1);
	if (ft_free_if(tab, word))
	{
		free (lens);
		return (NULL);
	}
	ft_fill_tab(s, c, tab, lens);
	tab[word] = 0;
	free(lens);
	return (tab);
}
