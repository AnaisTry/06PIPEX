/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:08:05 by angassin          #+#    #+#             */
/*   Updated: 2023/03/30 10:39:24 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(const char *str)
{
	unsigned long	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r' )))
		str++;
	while (*str == '-' || *str == '+')
	{	
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		if ((nb > LONG_MAX / 10) && sign == -1)
			return (LONG_MIN);
		else if ((nb > LONG_MAX / 10) && sign == 1)
			return (LONG_MAX);
		str++;
	}
	return (nb * sign);
}
