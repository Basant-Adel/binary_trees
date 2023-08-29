#include "binary_trees.h"

/**
 * binary_tree_leaves -> Write a function that counts leaves in binary tree
 *@tree: It's a pointer to root node of tree to count the number of leaves
 *Return: tree = (NULL) -> (0) or pointer != (leaf) -> (NULL)
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{

	size_t leaves = 0;

	if (tree)
	{

		leaves += (!tree->left && !tree->right) ? 1 : 0;

		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);

	}	return (leaves);

}
