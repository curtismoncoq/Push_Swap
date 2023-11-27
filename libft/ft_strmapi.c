/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:23:32 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 22:26:07 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*map;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	map = (char *)ft_calloc(sizeof(*map), (len + 1));
	if (!map)
		return (NULL);
	while (s[i])
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
