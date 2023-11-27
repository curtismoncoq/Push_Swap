/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:13:53 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/26 23:16:08 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_count(char c, int *r)
{
	write(1, &c, 1);
	*r = *r + 1;
}

void	ft_putstr_count(char *s, int *r)
{
	while (s && *s)
		ft_putchar_count(*s++, r);
}

void	ft_putnbr_count(int n, int *r)
{
	unsigned int	x;

	if (n < 0)
	{
		x = -n;
		ft_putchar_count('-', r);
	}
	else
		x = n;
	if (x > 9)
		ft_putnbr_count(x / 10, r);
	ft_putchar_count((x % 10) + 48, r);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		r;

	va_start(ap, str);
	i = -1;
	r = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's' || str[i] == 'p')
				sptr_print(va_arg(ap, char *), str[i], &r);
			else if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i')
				deci_print(va_arg(ap, int), str[i], &r);
			else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
				unsi_print(va_arg(ap, unsigned int), str[i], &r);
			else if (str[i] == '%')
				ft_putchar_count('%', &r);
		}
		else
			ft_putchar_count(str[i], &r);
	}
	return (r);
}
