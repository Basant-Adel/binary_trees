#include "binary_trees.h"

/**
 * bst_remove -> Write a function that removes a node from Binary Search Tree
 *@root: It's a pointer to the root node of tree where you will remove a node
 *@value: It's the value to remove in the tree
 *
 *Return: A pointer to the new root node of the
 *tree after removing the desired value (Successful)
 */

bst_t *bst_remove(bst_t *root, int value)
{

	return (bst_reoccurs(root, root, value));

}

/**
 * bst_tsearch -> Write a function to find leftmost node in binary search tree
 *@root: It's a pointer to the root node
 *Return: Root (Successful)
 */

bst_t *bst_tsearch(bst_t *root)
{

	while (root->left != NULL)
	{

		root = root->left;

	}	return (root);

}

/**
 * bst_delete -> Write a function that deletes a node from binary search tree
 *@root: It's a pointer to the root node
 *@node: It's a pointer to the node to delete
 *Return: A pointer to new root node after deletion (Successful)
 */

bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *reoccurs = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
		{
			parent->left = node->right;
		}

		else if (parent != NULL)

			parent->right = node->right;

		if (node->right != NULL)
		{
			node->right->parent = parent;

		}	free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;

		else if (parent != NULL)
			parent->right = node->left;

		if (node->left != NULL)
		{
			node->left->parent = parent;

		}	free(node);
		return (parent == NULL ? node->left : root);

	}	reoccurs = bst_tsearch(node->right);
	node->n = reoccurs->n;
	return (bst_delete(root, reoccurs));
}

/**
 * bst_reoccurs -> Write a function that removes
 *a node from a binary search tree recursively
 *
 *@root: It's a pointer to the root node
 *@node: It's a pointer to the current node
 *@value: It's the value to remove
 *Return: A pointer to root node after deletion (Successful)
 */

bst_t *bst_reoccurs(bst_t *root, bst_t *node, int value)
{

	if (node != NULL)
	{

		if (node->n == value)

			return (bst_delete(root, node));

		if (node->n > value)
		{

			return (bst_reoccurs(root, node->left, value));

		}	return (bst_reoccurs(root, node->right, value));

	}	return (NULL);

}
