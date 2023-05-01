/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:49:27 by angassin          #+#    #+#             */
/*   Updated: 2023/03/01 15:42:11 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Compare the null-terminated strings s1 and s2 starting by the end of the
	strings.
	Compares not more than n characters
	Characters that appear after a `\0' character are not compared
	Return an integer greater than, equal to, or less than 0, according as the 
	string s1 is greater than, equal to, or less than the string s2
	The comparison is done using unsigned characters
*/
int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (--n && i && j && s1[i] == s2[j])
	{
		i--;
		j--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
