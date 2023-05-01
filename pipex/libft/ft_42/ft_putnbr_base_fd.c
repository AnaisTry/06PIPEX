/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:51:56 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:19 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Recursive function to display a number in the given base
void	ft_putnbr_base_fd(long n, char *base, int fd)
{
	unsigned int	base_len;

	if (!base)
		return ;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= base_len)
	{
		ft_putnbr_base_fd(n / base_len, base, fd);
		ft_putnbr_base_fd(n % base_len, base, fd);
	}
	if (n >= 0 && n < base_len)
		ft_putchar_fd(base[n], fd);
}
