/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:47:06 by angassin          #+#    #+#             */
/*   Updated: 2023/05/01 17:11:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	cat_size(int argc, va_list strs);
static void	get_next_str(va_list *strs, char *cat, int *index);

/*
	Allocates (with malloc(3)) and returns a new string, which is the result of
	the concatenation of ’s1’ and ’s2’.
	Returns the new string or NULL if allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	cat_size;

	if (!s1 || !s2)
		return (NULL);
	cat_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat = malloc(sizeof(*cat) * cat_size);
	if (!cat)
		return (NULL);
	ft_strlcpy(cat, s1, ft_strlen(s1) + 1);
	ft_strlcat(cat, s2, cat_size);
	return (cat);
}

/*
	Same as strjoin but concatenaiting the number of strings sent in argument
*/
char	*variadic_strjoin(int argc, ...)
{
	va_list	strs;
	va_list	strs_cpy;
	char	*cat;
	int		index;
	int		strs_count;

	va_start(strs, argc);
	va_copy(strs_cpy, strs);
	cat = malloc(sizeof(*cat) * (cat_size(argc, strs_cpy) + 1));
	if (cat == NULL)
		return (NULL);
	index = 0;
	strs_count = -1;
	while (++strs_count < argc)
		get_next_str(&strs, cat, &index);
	cat[index] = '\0';
	return (cat);
}

static int	cat_size(int argc, va_list strs)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < argc)
	{
		size += ft_strlen(va_arg(strs, char *));
		++i;
	}
	return (size);
}

static void	get_next_str(va_list *strs, char *cat, int *index)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = va_arg(*strs, char *);
	len = ft_strlen(tmp);
	i = 0;
	while (i < len)
	{
		cat[*index] = tmp[i];
		++i;
		++(*index);
	}
}
