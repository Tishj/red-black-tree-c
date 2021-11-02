/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:24 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:46:35 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>
#include <stdio.h>

int	bstree_insert(t_bstree *bstree, void *key, size_t keysize, void *val)
{
	t_node	**node;
	t_node	*parent;

	node = node_find(bstree, key, keysize, &parent);
	if (!*node)
	{
		*node = node_new(key, keysize, val, parent);
		bstree->size++;
		if (*node)
			return (1);
		return (0);
	}
	return (1);
}
