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

	if (!binary_is_com(tree))
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

	}	return (binary_tree_size(tree->left) + binary_tree_size(tree->right + 1));

}

/**
 * is_com -> Write a function to check if tree is complete
 *@tree: It's a pointer to tree root
 *@n: It's a node
 *@num: It's a number of nodes
 *Return: (1) -> (tree) = (complete), (0) -> otherwise
 */

int is_com(const binary_tree_t *tree, int n, int num)
{

	if (tree == NULL)

		return (1);

	if (n >= num)
	{

		return (0);

	}	return (is_com(tree->left, (2 * n) + 1, num) &&
			is_com(tree->right, (2 * n) + 2, num));

}

/**
 * binary_is_com -> Write a function to call is_com
 *@tree: It's a pointer to tree root
 *Return: (1) -> (tree) = (complete), (0) -> otherwise
 */

int binary_is_com(const binary_tree_t *tree)
{

	if (tree == NULL)
	{

		return (0);

	}	return (is_com(tree, 0, binary_tree_size(tree)));

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
