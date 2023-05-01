/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:45:36 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 14:58:59 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// start at 1 to include zero or the equivalent in any base or the first digit
ssize_t	ft_nbrlen_base(long n, unsigned int base)
{
	ssize_t			nb_len;

	if (!base)
		return (0);
	nb_len = 1;
	if (n < 0)
	{
		nb_len += 1;
		n = -n;
	}
	while (n / base)
	{
		n = n / base;
		nb_len++;
	}
	return (nb_len);
}
