/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_highest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 19:46:41 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree_int.h>
#include <stdbool.h>

t_node	*node_highest(t_rbtree *rbtree)
{
	t_node	*iter;

	iter = rbtree->root;
	while (iter && iter->right)
		iter = iter->right;
	return (iter);
}
