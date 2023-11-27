/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:24:13 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 20:58:54 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		d;
	size_t	i;

	i = 0;
	d = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n - 1))
	{
		i++;
	}
	if (n)
		d = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (d);
}
