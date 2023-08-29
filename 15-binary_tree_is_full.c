#include "binary_trees.h"

/**
 * binary_tree_is_full -> Write function that checks if a binary tree is full
 *@tree: It's a pointer to the root node of the tree to check
 *Return: tree = (NULL) -> (0)
 */

int binary_tree_is_full(const binary_tree_t *tree)
{

	if (tree == NULL)
	{

		return (0);

	}	return (is_full_recursive(tree));

}

/**
 * is_full_recursive -> Write function that checks if a binary tree is full
 *@tree: It's a pointer to root node of tree to measure
 *Return: tree = (NULL) -> (0)
 */

int is_full_recursive(const binary_tree_t *tree)
{

	if (tree != NULL)
	{

		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
		{
			return (0);
		}

	}	return (1);

}
