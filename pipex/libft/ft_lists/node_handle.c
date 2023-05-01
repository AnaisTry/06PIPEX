/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:50:05 by angassin          #+#    #+#             */
/*   Updated: 2023/04/03 13:00:43 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Iterates the list and applies the function ’f’ on the content of each node.
void	nodes_iter(t_node *node, void (*f)(int))
{
	if (!node || !f)
		return ;
	while (node)
	{
		f(node->value);
		node = node->next;
	}	
}

/*
	Deletes and frees the given node and every successor of that node, 
	using the function free(3).
    Finally, the pointer to the list must be set to NULL.
*/
void	lstclear(t_node **lst)
{
	t_node	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
