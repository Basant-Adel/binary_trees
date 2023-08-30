#include "binary_trees.h"

/**
 * bst_insert -> Write a function that inserts a value in a Binary Search Tree
 *@tree: It's a double pointer to the root node of the BST to insert the value
 *@value: It's the value to store in the node to be inserted
 *Return: A pointer to the created node || (NULL)-> failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *le, *ri;

	if (tree != NULL)
	{
		le = *tree;

		if (le == NULL)
		{
			ri = binary_tree_node(le, value);
			if (ri == NULL)
			{
				return (NULL);
			}	return (*tree = ri);
		}

		if (value < le->n)
		{
			if (le->left != NULL)
			{
				return (bst_insert(&le->left, value));
			}	ri = binary_tree_node(le, value);
			if (ri == NULL)
			{
				return (NULL);
			}	return (le->left = ri);
		}
		if (value > le->n)
		{
			if (le->right != NULL)
			{
				return (bst_insert(&le->right, value));
			}	ri = binary_tree_node(le, value);
			if (ri == NULL)
			{
				return (NULL);
			}	return (le->right = ri);		}
	}	return (NULL);
}
