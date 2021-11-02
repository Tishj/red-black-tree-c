/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_delete.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 20:24:20 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree_int.h>
#include <stdlib.h>

/*
**	Free the node and set its corresponding parent->(right/left) pointer to NULL
*/
void	node_delete(t_node **node, t_destructor del)
{
	if (del)
		del((*node)->val);
	free((*node)->key);
	free(*node);
	*node = NULL;
}
