/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:46:22 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 15:00:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Allocates (with malloc(3)) and returns a new node. 
	The member variable ’content’ is initialized with the value of the 
	parameter ’content’. The variable ’next’ is initialized to NULL.
*/
t_list	*ft_lstnew(void	*content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
