#include "binary_trees.h"

/**
 * binary_tree_delete -> Write a function that deletes an entire binary tree
 *@tree: It's a pointer to the root node of the tree to delete
 *Return: tree = (NULL)-> do nothing (void)
 */

void binary_tree_delete(binary_tree_t *tree)
{

	if (tree != NULL)
	{

		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);

		free(tree);
	}

}
