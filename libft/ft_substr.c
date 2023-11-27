/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:32:56 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 23:03:06 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		sub = (char *)ft_calloc(sizeof(char), 1);
	else
	{
		i = ft_strlen(s) - start;
		if (len < i)
			i = len;
		sub = (char *)ft_calloc(sizeof(char), (i + 1));
		if (!sub)
			return (NULL);
		i = 0;
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
