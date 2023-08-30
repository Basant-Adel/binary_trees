#include "limits.h"
#include "binary_trees.h"

/**
 * binary_tree_is_bst -> Write a function that checks if a binary
 *tree is a valid Binary Search Tree
 *
 *@tree: It's a pointer to the root node of the tree to check
 *Return: tree is valid BST -> (1) & (0) -> otherwise, (tree) = (NULL) -> (0)
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (tree == NULL)
	{

		return (0);

	}	return (binary_bst(tree, INT_MIN, INT_MAX));

}

/**
 * binary_bst -> Write a function that checks if a binary
 *tree is a valid Binary Search Tree
 *
 *@tree: It's a pointer to the root node of the tree to check
 *@sm: It's The value of the smallest node
 *@la: It's The value of the largest node
 *Return: tree is a valid BST -> (1) otherwise -> (0)
 */

int binary_bst(const binary_tree_t *tree, int sm, int la)
{

	if (tree != NULL)
	{

		if (tree->n < sm || tree->n > la)
		{

			return (0);

		}	return (binary_bst(tree->left, sm, tree->n - 1) &&
				binary_bst(tree->right, tree->n + 1, la));

	}	return (1);

}
