#include "binary_trees.h"

/**
 * binary_tree_is_root -> Write a function that checks
 *if a given node is a root
 *
 *@node: It's a pointer to the node to check
 *Return: node = (root)-> (1) otherwise (0) or node = (NULL)-> (0)
 */

int binary_tree_is_root(const binary_tree_t *node)
{

	if (node == NULL || node->parent != NULL)
	{
		return (0);

	}	return (1);

}
