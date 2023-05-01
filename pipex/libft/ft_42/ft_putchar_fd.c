/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:28:53 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:09 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//	Outputs the character ’c’ to the given file descriptor.
//	Returns size of output.
ssize_t	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
