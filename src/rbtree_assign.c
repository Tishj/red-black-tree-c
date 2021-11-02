/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rbtree_assign.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 09:44:43 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree_int.h>

int	rbtree_assign(t_rbtree *rbtree, void *key, size_t keysize, void *val)
{
	t_node	**node;
	t_node	*parent;

	node = node_find(rbtree, key, keysize, &parent);
	if (!*node)
	{
		*node = node_new(key, keysize, val, parent);
		rbtree->size++;
		if (*node)
			return (1);
		return (0);
	}
	if (rbtree->del)
		rbtree->del((*node)->val);
	(*node)->val = val;
	return (1);
}
