#include "binary_trees.h"

/**
 * binary_tree_is_leaf -> Write a function that checks if a node is a leaf
 *@node: It's a pointer to the node to check
 *Return: node = (leaf)-> (1) otherwise (0) or node = (NULL)-> (0)
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{

	if (node == NULL || node->left != NULL || node->right != NULL)
	{

		return (0);

	}	return (1);

}
