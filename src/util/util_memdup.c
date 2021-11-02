/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_memdup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 14:41:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:28:13 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <bstree_int.h>
#include <stdlib.h>

void	*util_memdup(void *src, size_t size)
{
	void	*dup;

	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);
	util_memcpy(dup, src, size);
	return (dup);
}
