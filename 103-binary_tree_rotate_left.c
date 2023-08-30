#include "binary_trees.h"

/**
 * binary_tree_rotate_left -> Write a function that performs
 *a left-rotation on a binary tree
 *
 *@tree: It's a pointer to the root node of the tree to rotate
 *Return: A pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *le, *ri;

	if (tree == NULL || tree->right == NULL)
	{

		return (NULL);

	}	le = tree->right;
	ri = le->left;
	le->left = tree;
	tree->right = ri;

	if (ri != NULL)
	{

		ri->parent = tree;

	}	ri = tree->parent;
	tree->parent = le;
	le->parent = ri;

	if (ri != NULL)
	{

		if (ri->left == tree)

			ri->left = le;

		else

			ri->right = le;

	}	return (le);
}
