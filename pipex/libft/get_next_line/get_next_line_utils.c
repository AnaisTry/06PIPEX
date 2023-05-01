/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:03:44 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 15:07:25 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/*
	Locates the first occurrence of c (converted to a char) in the string 
	pointed to by s.  The terminating null character is considered to be part 
	of the string; 
	therefore if c is `\0', the functions locate the terminating `\0'
	Return a pointer to the located character, or NULL if the character does 
	not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
	Allocates (with malloc(3)) and returns a new string, which is the result of 
	the concatenation of ’s1’ and ’s2’.
	Returns the new string or NULL if allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	cat = malloc(sizeof(*cat) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		cat[j++] = s1[i++];
	i = 0;
	while (s2[i])
		cat[j++] = s2[i++];
	cat[j] = '\0';
	return (cat);
}

/*
	Allocates and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
	Returns the substring or NULL if allocation fails.
*/
char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*src;
	size_t	sub_size;
	size_t	dstsize;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_size = ft_strlen(&s[start]);
	if (sub_size > len)
		sub_size = len;
	sub = malloc(sizeof(*sub) * (sub_size + 1));
	if (!sub)
		return (NULL);
	src = (char *)&s[start];
	dstsize = sub_size + 1;
	while ((dstsize > 1) && *src)
	{
		*sub++ = *src++;
		dstsize--;
	}
	if (dstsize)
		*sub = '\0';
	return (sub - sub_size);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
	The strdup() function allocates sufficient memory for a copy of the 
	string s1, does the copy, and returns a pointer to it.  
	The pointer may subsequently be used as an argument to the function free.
	If insufficient memory is available, NULL is returned and errno is set 
	to ENOMEM.
*/
char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	dstsize;
	size_t	i;

	cpy = malloc(sizeof(*cpy) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	dstsize = ft_strlen(s1) + 1;
	while ((dstsize > 1) && s1[i])
	{
		cpy[i] = s1[i];
		i++;
		dstsize--;
	}
	if (dstsize)
		cpy[i] = '\0';
	return (cpy);
}
