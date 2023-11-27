/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:24:23 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/10 14:57:26 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	k;
	size_t			i;

	i = 0;
	k = (unsigned char)c;
	while (i < n)
	{
		((unsigned char *)s)[i] = k;
		i++;
	}
	return (s);
}
