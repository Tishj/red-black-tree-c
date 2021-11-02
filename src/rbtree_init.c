/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:36 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree_int.h>

int	rbtree_init(t_rbtree *rbtree, size_t key_type_size,
	t_compare comp, t_destructor del)
{
	rbtree->key_type_size = key_type_size;
	rbtree->root = NULL;
	rbtree->size = 0;
	if (comp)
		rbtree->comp = comp;
	else
		rbtree->comp = util_memcmp;
	rbtree->del = del;
	return (1);
}
