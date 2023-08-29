#include "binary_trees.h"

/**
 * binary_tree_height -> Write a function that measures
 *the height of a binary tree
 *
 *@tree: It's a pointer to the root node of the tree to measure the height
 *Return: tree = (NULL) -> (0)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{

	if (tree)
	{

		size_t le = 0, ri = 0;

		le = tree->left ? 1 + binary_tree_height(tree->left) : 0;

		ri = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((le > ri) ? le : ri);

	}	return (0);

}
