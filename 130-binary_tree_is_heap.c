#include "binary_trees.h"

/**
 * binary_tree_is_heap -> Write a function that checks if
 *a binary tree is a valid Max Binary Heap
 *
 *@tree: It's a pointer to the root node of the tree to check
 *Return: (tree) = (NULL) -> (0)
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{

	if (!binary_tree_is_complete(tree))
	{

		return (0);

	}	return (check_parent(tree->left) && check_parent(tree->right));

}

/**
 * binary_tree_size -> Write a function that measures size of a binary tree
 *@tree: It's a pointer to the root node of the tree to check
 *Return: (tree) = (NULL) -> (0)
 */

size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
	{

		return (0);

	}	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);

}

/**
 * tree_is_complete -> Write a function to check if tree is complete
 *@tree: It's a pointer to tree root
 *@i: It's a node
 *@inodes: It's a number of nodes
 *Return: (1) -> (tree) = (complete), (0) -> otherwise
 */

int tree_is_complete(const binary_tree_t *tree, int i, int inodes)
{

	if (tree == NULL)
	{

		return (1);

	}

	if (i >= inodes)
	{

		return (0);

	}	return (tree_is_complete(tree->left, (2 * i) + 1, inodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, inodes));

}


/**
 * binary_tree_is_complete -> Write a function to call is_com
 *@tree: It's a pointer to tree root
 *Return: (1) -> (tree) = (complete), (0) -> otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	size_t inodes;

	if (tree == NULL)
	{

		return (0);

	}	inodes = binary_tree_size(tree);
	return (tree_is_complete(tree, 0, inodes));

}

/**
 * check_parent -> Write a function to check if parent has a greater value
 *@tree: It's a pointer to tree root
 *Return: (1) -> parent has a greater value, (0) -> otherwise
 */

int check_parent(const binary_tree_t *tree)
{

	if (tree == NULL)
	{
		return (1);
	}

	if (tree->n > tree->parent->n)
	{

		return (0);

	}	return (check_parent(tree->left) && check_parent(tree->right));

}
