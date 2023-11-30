/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:14:01 by cumoncoq          #+#    #+#             */
/*   Updated: 2023/11/30 00:11:07 by cumoncoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_stash
{
	int				fd;
	int				end;
	char			*text;
	struct s_stash	*next;
}	t_stash;

typedef struct s_fill
{
	int		i;
	int		j;
	int		found;
	t_stash	*last;
}	t_fill;

typedef struct s_fdo
{
	int	bytes;
	int	fd;
	int	o;
}	t_fdo;

t_stash	*ft_stash_to_line(int fd, char *line, t_stash *stash, int len);
t_stash	*ft_fill_line(int fd, char **line, t_stash *stash);
t_stash	*ft_create(int fd, char *buffer, int end);
void	ft_fill_stash(t_fdo g, char *buffer, char **line, t_stash **stash);
void	ft_add_back(t_stash **stash, t_stash *n);
void	ft_clear_stash(int fd, t_stash **stash);
void	ft_free_text(t_stash *tmp);
char	*get_next_line(int fd);
int		ft_line_len(int fd, t_stash *stash, int result, int found);
int		ft_check_newline(int fd, t_stash *stash);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstadd_back(t_list **lst, t_list *nw);
void	ft_lstadd_front(t_list **lst, t_list *nw);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_putchar_count(char c, int *r);
void	ft_putstr_count(char *s, int *r);
void	ft_putnbr_count(int n, int *r);
void	ft_putunbr_count(unsigned int n, int *r);
void	ft_puthex(unsigned long long hex, char up, int *r);
void	sptr_print(void *sptr, char c, int *r);
void	deci_print(int n, char c, int *r);
void	unsi_print(unsigned int n, char c, int *r);
int		ft_printf(const char *str, ...);

#endif