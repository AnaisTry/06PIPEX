/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:46:11 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:27 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Output the string s to the filedescriptor fd.
	Return the number of characters printed.
*/

ssize_t	ft_putstr_fd(char *s, int fd)
{
	ssize_t	len;

	if (!s)
		return (0);
	len = write(fd, s, ft_strlen(s));
	return (len);
}
