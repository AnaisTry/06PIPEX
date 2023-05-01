/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:17:33 by angassin          #+#    #+#             */
/*   Updated: 2023/03/09 20:33:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Locates the first occurrence of the null-terminated string needle in
	the string haystack.
	If needle is an empty string, haystack is returned; 
	if needle occurs nowhere in haystack, NULL is returned; 
	otherwise a pointer to the first character of the first occurrence 
	of needle is returned.
*/
char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
