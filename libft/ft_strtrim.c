/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:14:18 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 22:19:57 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(const char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trim;

	if (!s1)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_charset(set, s1[start]))
		start++;
	while (end > start && ft_charset(set, s1[end - 1]))
		end--;
	trim = ft_calloc(sizeof(*trim), (end - start + 1));
	if (!trim)
		return (NULL);
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = 0;
	return (trim);
}
