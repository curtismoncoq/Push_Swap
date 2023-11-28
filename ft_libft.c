/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:56:09 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/28 04:00:49 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <limits.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
		ft_putchar_fd(*s++, fd);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > INT_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

static	int	ft_count_words(const char *str, char c)
{
	int	i;
	int	words;
	int	nw;

	i = 0;
	words = 0;
	nw = 1;
	while (str[i])
	{
		if (c != str[i] && nw == 1)
		{
			nw = 0;
			words++;
		}
		if (c == str[i])
			nw = 1;
		i++;
	}
	return (words);
}

static	void	ft_fill_tab(const char *str, char c, char **tab, int *lens)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (lens[i])
	{
		while (c == str[s])
			s++;
		j = 0;
		while (j < lens[i])
			tab[i][j++] = str[s++];
		tab[i++][j] = 0;
	}
}

static	void	ft_words_len(const char *str, char c, int *lens)
{
	int	i;
	int	d;
	int	nw;
	int	index;

	i = -1;
	nw = 1;
	index = -1;
	while (str[++i])
	{
		if (c == str[i] && !nw)
		{
			lens[index] = i - d;
			nw = 1;
		}
		else if (c != str[i] && nw)
		{
			index++;
			d = i;
			nw = 0;
		}
	}
	if (nw == 0)
		lens[index] = i - d;
	lens[index + 1] = 0;
}

static int	ft_free_if(char **tab, int word)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (tab && i < word)
	{
		if (!tab[i])
			f = 1;
		i++;
	}
	i = 0;
	if (f)
	{
		while (tab && i < word)
		{
			if (tab[i])
				free (tab[i]);
			i++;
		}
		free (tab);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		*lens;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	word = ft_count_words(s, c);
	tab = (char **)ft_calloc(sizeof(*tab), (word + 1));
	if (!tab)
		return (NULL);
	lens = (int *)ft_calloc(sizeof(*lens), (word + 1));
	ft_words_len(s, c, lens);
	while (++i < word)
		tab[i] = (char *)ft_calloc(sizeof(**tab), lens[i] + 1);
	if (ft_free_if(tab, word))
	{
		free (lens);
		return (NULL);
	}
	ft_fill_tab(s, c, tab, lens);
	tab[word] = 0;
	free(lens);
	return (tab);
}


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











// #include "push_swap.h"
// #include <stdio.h>

// t_ring	*ft_create_element(int data)
// {
// 	t_ring	*n;

// 	n = (t_ring *)malloc(sizeof(t_ring));
// 	if (!n)
// 		return (NULL);
// 	n->data = data;
// 	n->next = NULL;
// 	n->prev = NULL;
// 	n->target = NULL;
// 	n->cost = 0;
// 	return (n);
// }

// void	ft_ra(t_ring **a)
// {
// 	*a = (*a)->next;
// 	printf("ra\n");
// }

// void	ft_rra(t_ring **a)
// {
// 	*a = (*a)->prev;
// 	printf("rra\n");
// }

// void ft_ring_push_top(t_ring **top, int data)
// {
// 	t_ring	*n;

// 	n = ft_create_element(data);
// 	if (n)
// 	{
// 		if (*top)
// 		{
// 			n->next = *top;
// 			n->prev = (*top)->prev;
// 			n->prev->next = n;
// 			(*top)->prev = n;
// 		}
// 		else
// 		{
// 			n->next = n;
// 			n->prev = n;
// 		}
// 		*top = n;
// 	}
// }	

// void	ft_print_ring(t_ring *top)
// {
// 	t_ring	*move;

// 	if (!top)
// 	{
// 		printf("NULL\n");
// 		return ;
// 	}
// 	printf("\n");
// 	move = top->next;
// 	printf(">%dc%d\n", top->data, top->cost);
// 	while (move != top)
// 	{
// 		printf(">%dc%d\n", move->data, move->cost);
// 		move = move->next;
// 	}
// }	

// void	ft_remove_top(t_ring **top)
// {
// 	(*top)->next->prev = (*top)->prev;
// 	(*top)->prev->next = (*top)->next;
// 	(*top) = (*top)->next;
// }	

// void	ft_swap(t_ring **top)
// {
// 	int	one;
// 	int	two;

// 	one = (*top)->data;
// 	two = (*top)->next->data;
// 	ft_remove_top(top);
// 	ft_remove_top(top);
// 	ft_ring_push_top(top, one);
// 	ft_ring_push_top(top, two);
// 	printf("sa\n");
// }

// void ft_order_three_suport(t_ring **a, int min, int max)
// {
// 	int	one;
// 	int	two;
// 	int	three;

// 	one = (*a)->data;
// 	two = (*a)->next->data;
// 	three = (*a)->next->next->data;

// 	if (one == max && two == min)
// 		ft_ra(a);
// 	else if (two == max && three == min)
// 		ft_rra(a);
// 	else if (two == min && three == max)
// 		ft_swap(a);
// 	else if (one == min && two == max)
// 	{
// 		ft_swap(a);
// 		ft_ra(a);
// 	}
// 	else if (one == max && three == min)
// 	{
// 		ft_swap(a);
// 		ft_rra(a);
// 	}
// }

// void	ft_order_three(t_ring **a)
// {
// 	int	max;
// 	int min;
// 	t_ring *move;

// 	max = (*a)->data;
// 	min = (*a)->data;
// 	move = (*a)->next;
// 	while (move != *a)
// 	{
// 		if (max < move->data)
// 			max = move->data;
// 		if (min > move->data)
// 			min = move->data;
// 		move = move->next;
// 	}
// 	ft_order_three_suport(a, min, max);
// }

// void	ft_clear_ring(t_ring **top)
// {
// 	t_ring	*move;
// 	t_ring	*tmp;

// 	if (!(*top))
// 		return ;
// 	move = (*top)->next;
// 	while (move != *top)
// 	{
// 		tmp = move;
// 		move = move->next;
// 		free (tmp);
// 	}
// 	free(*top);
// 	*top = NULL;
// }	

// int main()
// {
// 	t_ring	*top;

// 	top = NULL;
// 	ft_ring_push_top(&top, 0);
// 	ft_ring_push_top(&top, 7);
// 	ft_ring_push_top(&top, 9);
// 	ft_print_ring(top);
// 	ft_order_three(&top);
// 	ft_print_ring(top);
// 	return (0);
// }