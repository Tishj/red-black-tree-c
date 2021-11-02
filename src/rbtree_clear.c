/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rbtree_clear.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 21:57:02 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree_int.h>

/*
**	Go left or right until you hit a leaf node, delete the leaf node and
**	set node back to the '&parent->(left/right)' of its parent
*/
void	rbtree_clear(t_rbtree *rbtree)
{
	t_node	**node;
	t_node	**parent;

	node = &rbtree->root;
	while (*node)
	{
		if ((*node)->left)
			node = &(*node)->left;
		else if ((*node)->right)
			node = &(*node)->right;
		else
		{
			if (*node == rbtree->root || (*node)->parent == rbtree->root)
				parent = &rbtree->root;
			else if ((*node)->parent->parent->left == (*node)->parent)
				parent = &(*node)->parent->parent->left;
			else
				parent = &(*node)->parent->parent->right;
			node_delete(node, rbtree->del);
			node = parent;
		}
	}
}
