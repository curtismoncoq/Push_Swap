/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:39:32 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/14 00:03:56 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;

	if (n < 0)
	{
		x = -n;
		ft_putchar_fd('-', fd);
	}
	else
		x = n;
	if (x > 9)
		ft_putnbr_fd(x / 10, fd);
	ft_putchar_fd((x % 10) + 48, fd);
}
