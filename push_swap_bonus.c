/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:37:16 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 16:56:30 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// static char	*ft_strcat(char *dest, char *src)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (dest[i])
// 		i++;
// 	while (src[j])
// 		dest[i++] = src[j++];
// 	dest[i] = '\0';
// 	return (dest);
// }

// static char	*ft_newstrjoin(char const *s1, char const *s2, size_t len)
// {
// 	char	*cat;

// 	if (!s1 && s2)
// 	{
// 		cat = ft_strdup((char *)s2);
// 		free((void *)s2);
// 		return (cat);
// 	}
// 	if (s1 && !s2)
// 	{
// 		cat = ft_strdup((char *)s1);
// 		free((void *)s1);
// 		return (cat);
// 	}
// 	if (!s1 && !s2)
// 		return (NULL);
// 	cat = (char *)ft_calloc(sizeof(*cat), (len + 1));
// 	if (!cat)
// 		return (NULL);
// 	cat[0] = 0;
// 	ft_strcat(cat, (char *)s1);
// 	ft_strcat(cat, (char *)s2);
// 	free((void *)s1);
// 	free((void *)s2);
// 	return (cat);
// }
// char	*ft_get_operations(void)
// {
// 	char	*str;
// 	char	*line;
// 	int		nl;
// 	size_t	len;

// 	nl = 1;
// 	str = NULL;
// 	line = NULL;
// 	len = 0;
// 	while (nl)
// 	{
// 		line = get_next_line(0);
// 		if (!line || line[ft_strlen(line) - 1] != '\n')
// 			nl = 0;
// 		if (str && line)
// 			len = ft_strlen(str) + ft_strlen(line);
// 		str = ft_newstrjoin(str, line, len);
// 	}
// 	return (str);
// }
void	ft_print_list(t_list *list)	//! delete
{
	while(list)
	{
		ft_putstr_fd(list->content, 1);
		list = list->next;
	}
}


void	ft_print_int_list(t_ring *list)	//! delete
{
	t_ring *move;

	if (!list)
		return ;
	ft_putnbr_fd(list->data, 1);
	move = list->next;
	while(move != list)
	{
		ft_putnbr_fd(move->data, 1);
		move = move->next;
	}
}

t_list	*ft_get_operations(void)
{
	t_list	*list;
	char	*line;
	int		nl;

	nl = 1;
	list = NULL;
	line = NULL;
	while (nl)
	{
		line = get_next_line(0);
		if (!line || line[ft_strlen(line) - 1] != '\n')
			nl = 0;
		ft_lstadd_back(&list, ft_lstnew(line));
	}

	return (list);
}

void	ft_apply(t_ring **a, t_ring **b, int ope)
{
	if (ope == 1)
		ft_swap(a);
	if (ope == 2)
		ft_swap(b);
	if (ope == 3)
	{
		ft_swap(a);
		ft_swap(b);
	}
	if (ope == 4)
		ft_push(a, b);
	if (ope == 5)
		ft_push(b, a);
	if (ope == 6)
		ft_rx(a);
	if (ope == 7)
		ft_rx(b);
	if (ope == 8)
		ft_rr(a, b);
	if (ope == 9)
		ft_rrx(a);
	if (ope == 10)
		ft_rrx(b);
	if (ope == 11)
		ft_rrr(a, b);
}


int ft_is_s(char *ope)
{
	if (ope[1] == 'a' && (!ope[2] || ope[2] == '\n'))
		return (1);
	if (ope[1] == 'b'&& (!ope[2] || ope[2] == '\n'))
		return (2);
	if (ope[1] == 's'&& (!ope[2] || ope[2] == '\n'))
		return (3);
	return (0);
}

int ft_is_p(char *ope)
{
	if (ope[1] == 'a' && (!ope[2] || ope[2] == '\n'))
		return (4);
	if (ope[1] == 'b' && (!ope[2] || ope[2] == '\n'))
		return (5);
	return (0);
}

int ft_is_rr(char *ope)
{
	if (ope[2] == 'a' && (!ope[3] || ope[3] == '\n'))
		return (9);
	if (ope[2] == 'b'&& (!ope[3] || ope[3] == '\n'))
		return (10);
	if (ope[2] == 'r'&& (!ope[3] || ope[3] == '\n'))
		return (11);
	return (0);
}

int ft_is_r(char *ope)
{
	if (ope[1] == 'a' && (!ope[2] || ope[2] == '\n'))
		return (6);
	if (ope[1] == 'b'&& (!ope[2] || ope[2] == '\n'))
		return (7);
	if (ope[1] == 'r')
	{
		if(!ope[2] || ope[2] == '\n')
			return (8);
		else
			return(ft_is_rr(ope));
	}
	return (0);
}

int	ft_is_operation(char *ope)
{
	if (!ope)
		return (12);
	if (ope[0] == 's')
		return (ft_is_s(ope));
	if (ope[0] == 'p')
		return (ft_is_p(ope));
	if (ope[0] == 'r')
		return (ft_is_r(ope));
	return (0);
}

// int	ft_follow_operations()
int	ft_follow_operations(t_ring **a, t_ring **b)
{
	t_list	*ope_list;
	t_list	*move;

	ope_list = ft_get_operations();
	move = ope_list;
	while (move)
	{
		// ft_print_list(move);
		if (!ft_is_operation(move->content))
		{
			ft_putstr_fd("Error\n", 2);
			ft_lstclear(&ope_list, free);
			return (0);
		}
		move = move->next;
	}
	move = ope_list;
	while(move)
	{
		ft_apply(a, b, ft_is_operation(move->content));
		move = move->next;
	}
	// ft_print_int_list(*a);	//!
	return (1);
}

int	main(int ac, char **av)
{
	t_ring	*a;
	t_ring	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	ft_parse_args(ac, av, &a);
	if (a && ft_check_double(&a))
	{
		ft_clear_ring(&a);
		ft_putstr_fd("Error\n", 2);
	}
	else if (a)
	{
		ft_follow_operations(&a, &b);
		ft_print_int_list(a);
		if (ft_is_sorted(a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	ft_clear_ring(&a);
	ft_clear_ring(&b);
	return (0);
}
