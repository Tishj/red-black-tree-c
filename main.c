/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 17:56:45 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rbtree.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void	find_element(t_rbtree *rbtree, void *key, size_t keysize)
{
	void	*value;

	value = rbtree_find(rbtree, key, keysize);
	if (value)
//		printf("Found key \"%s\", containing value: %d\n", key.data, (int)(unsigned long)(*node)->val.data);
		printf("Found key \"%s\", containing value: %s\n", (char*)key, (char*)value);
	else
		printf("Did not find a node with key \"%s\"\n", (char *)key);
}

void	iter_plusplus(t_node *node)
{
	while (node)
	{
		printf("key: %s - val: %s\n", (char *)node->key, (char*)node->val);
		node = node_next(node);
	}
}

void	iter_minmin(t_node *node)
{
	while (node)
	{
//		printf("key: %s - val: %d\n", node->key.data, (int)(unsigned long)node->val.data);
		printf("key: %s - val: %s\n", (char *)node->key, (char*)node->val);
		node = node_prev(node);
	}
}

char	**str2dup(char **original, size_t amount)
{
	char	**dup;
	size_t	i;

	dup = malloc(sizeof(char *) * (amount + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		dup[i] = util_strdup(original[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

int	main(void)
{
	t_rbtree	rbtree;
	t_node		**node;
	char		*keys[] = {
		"yeet",
		"chad",
		"nemo",
		"hila",
		"moth",
		"boom",
		"vogel",
		"afrika"
	};
	char		**dup;
	size_t		len;

	len = (sizeof(keys) / sizeof(char*));
	dup = str2dup(keys, len);
	if (!dup)
		return (1);
	srand(time(NULL));
	if (!rbtree_init(&rbtree, sizeof(char), util_memcmp, free))
		return (1);
	find_element(&rbtree, "hello", 5);
	if (!rbtree_assign(&rbtree, "hello", strlen("hello") + 1, strdup("yeet")))
		return (1);
	for (size_t i = 0; i < len; i++)
		if (!rbtree_assign(&rbtree, keys[i], strlen(keys[i]) + 1, dup[len - i - 1]))
			return (1);
	printf("yeet\n");
	iter_plusplus(node_lowest(&rbtree));
	printf("\n---\n");
	iter_minmin(node_highest(&rbtree));
	// if (!rbtree_delete(&rbtree, "moth", 5))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "afrika", 7))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "hello", 6))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "hila", 5))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "yeet", 5))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "chad", 5))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "vogel", 6))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "boom", 5))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "nemo", 5))
	// 	return (1);
	// if (!rbtree_delete(&rbtree, "nemo", 5))
	// 	return (1);
	for (size_t i = 0; i < sizeof(keys) / sizeof(char*); i++)
		find_element(&rbtree, keys[i], strlen(keys[i]));
	find_element(&rbtree, "hello", 6);
	rbtree_clear(&rbtree);
	free(dup);
	return (0);
}
