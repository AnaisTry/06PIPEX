/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:10:19 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 14:59:59 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// start at 1 to include zero or the equivalent in any base or the first digit
size_t	ft_unbrlen_base(unsigned long n, unsigned int base)
{
	size_t			nb_len;

	if (!base)
		return (0);
	nb_len = 1;
	while (n / base)
	{
		n = n / base;
		nb_len++;
	}
	return (nb_len);
}
