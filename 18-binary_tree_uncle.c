#include "binary_trees.h"

/**
 * binary_tree_uncle -> Write a function that finds the uncle of a node
 *@node: It's a pointer to the node to find the uncle
 *
 *Return: The pointer to uncle node or node has no uncle -> (NULL),
 *(node) = (NULL) -> (NULL)
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)

		return (NULL);

	if (node->parent->parent->left == node->parent)
	{

		return (node->parent->parent->right);

	}	return (node->parent->parent->left);

}
