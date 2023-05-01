/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:28:38 by angassin          #+#    #+#             */
/*   Updated: 2023/04/17 18:18:38 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*									[Includes]								*/

// BUFSIZ, strerror, perror
# include <stdio.h>
# include "libft.h"
/*									[Macros]								*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

/*									[Functions]								*/

//get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif
