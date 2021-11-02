/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:24 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree_int.h>
#include <stdio.h>

int	rbtree_insert(t_rbtree *rbtree, void *key, size_t keysize, void *val)
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
	return (1);
}
