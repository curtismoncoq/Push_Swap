/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:45:34 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 22:26:33 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	x;
	int				i;
	char			*str;

	if (n < 0)
		x = -n;
	else
		x = n;
	i = ft_malloc_size(n);
	str = (char *)ft_calloc(sizeof(*str), (i + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (x)
	{
		str[i - 1] = (x % 10) + 48;
		x /= 10;
		i--;
	}
	return (str);
}
