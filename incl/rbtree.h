/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rbtree_int.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 14:36:14 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 16:35:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef rbtree_H
# define rbtree_H

#include <rbtree_int.h>
#include <stdbool.h>

void			rbtree_clear(t_rbtree *rbtree);
int				rbtree_delete(t_rbtree *rbtree, void *key, size_t keysize);
int				rbtree_init(t_rbtree *rbtree, size_t key_type_size,
				t_compare comp, t_destructor del);
void			*rbtree_find(t_rbtree *rbtree, void *key, size_t keysize);
int				rbtree_insert(t_rbtree *rbtree, void *key, size_t keysize,
				void *val);
int				rbtree_assign(t_rbtree *rbtree, void *key, size_t keysize,
				void *val);

t_node			*node_next(t_node *node);
t_node			*node_prev(t_node *node);
t_node			*node_lowest(t_rbtree *rbtree);
t_node			*node_highest(t_rbtree *rbtree);

#endif
