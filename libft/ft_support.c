/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:08:35 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/26 23:16:19 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_count(unsigned int n, int *r)
{
	if (n > 9)
		ft_putunbr_count(n / 10, r);
	ft_putchar_count((n % 10) + 48, r);
}

void	ft_puthex(unsigned long long hex, char up, int *r)
{
	char	*str;

	if (up)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (hex)
	{
		ft_puthex((hex / 16), up, r);
		ft_putchar_count(str[hex % 16], r);
	}
}

void	sptr_print(void *sptr, char c, int *r)
{
	if (c == 's')
	{
		if (!sptr)
			ft_putstr_count("(null)", r);
		else
			ft_putstr_count(sptr, r);
	}
	else if (c == 'p')
	{
		if (!sptr)
			ft_putstr_count("(nil)", r);
		else
		{
			ft_putstr_count("0x", r);
			ft_puthex((unsigned long)sptr, 0, r);
		}
	}
}

void	deci_print(int n, char c, int *r)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_count(n, r);
	if (c == 'c')
		ft_putchar_count(n, r);
}

void	unsi_print(unsigned int n, char c, int *r)
{
	if (!n)
		ft_putchar_count('0', r);
	else if (c == 'u')
		ft_putunbr_count(n, r);
	else if (c == 'x')
		ft_puthex(n, 0, r);
	else if (c == 'X')
		ft_puthex(n, 1, r);
}
