/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:33:18 by angassin          #+#    #+#             */
/*   Updated: 2023/05/01 16:49:50 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//	exit, malloc, free, size_t, NULL
# include <stdlib.h>
// INT_MAX, OPEN-MAX
# include <limits.h>
//	pipe, fork, dup2, execve, access, unlink, read, write, *_FILENO
# include <unistd.h>
# include "get_next_line.h"
# include "libftprintf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;

/* libc */

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strstr(const char *haystack, const char *needle);
long	ft_atol(const char *str);

/* ft_42 */

char	*ft_substr(char	const *s, unsigned int start, size_t len);
// ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);
char	*variadic_strjoin(int argc, ...);

char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char const *s, void (*f)(unsigned int, char*));
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base_fd(long n, char *base, int fd);
void	ft_put_unbr_base_fd(unsigned long n, char *base, int fd);
ssize_t	ft_nbrlen_base(long n, unsigned int base);
size_t	ft_unbrlen_base(unsigned long n, unsigned int base);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
void	*ft_free_array(char **arr);

/* ft_lists */

t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// node_create.c
t_node	*newnode(int value);
t_node	*lastnode(t_node *node);
void	node_add_front(t_node **lst, t_node *new);
void	node_add_back(t_node **lst, t_node *new);
int		lstsize(t_node *node);

// node_handle.c
void	nodes_iter(t_node *node, void (*f)(int));
void	lstclear(t_node **lst);
#endif
