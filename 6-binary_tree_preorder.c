#include "binary_trees.h"

/**
 * binary_tree_preorder -> Write a function that goes through
 *a binary tree using pre-order traversal
 *
 *@tree: It's a pointer to the root node of the tree to traverse
 *@func: It's a pointer to a function to call for each node
 *Return: (tree or func) = (NULL) -> do nothing (void)
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree && func)
	{
		func(tree->n);

		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}

}
