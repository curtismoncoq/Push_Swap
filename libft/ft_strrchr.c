/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:44:57 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/13 23:55:24 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			k = i;
		i++;
	}
	if (s[i] == (char)c)
		k = i;
	if (k != -1)
		return ((char *)s + k);
	return (NULL);
}
