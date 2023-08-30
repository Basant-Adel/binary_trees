#include "binary_trees.h"

/**
 * bst_search -> Write function to search for a value in Binary Search Tree
 *@tree: It's a pointer to the root node of the BST to search
 *@value: It's the value to search in the tree
 *
 *Return: A pointer to the node containing a value equals to value
 *(tree) = (NULL) or nothing is found -> (NULL)
 */

bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree != NULL)
	{

		if (tree->n == value)

			return ((bst_t *)tree);

		if (tree->n > value)
		{

			return (bst_search(tree->left, value));

		}	return (bst_search(tree->right, value));

	}	return (NULL);

}
