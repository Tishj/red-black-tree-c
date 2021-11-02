/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rbtree_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 09:29:40 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree_int.h>

void	*rbtree_find(t_rbtree *rbtree, void *key, size_t keysize)
{
	t_node	**node;

	node = node_find(rbtree, key, keysize, NULL);
	if (!*node)
		return (NULL);
	return ((*node)->val);
}
