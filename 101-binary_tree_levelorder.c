#include "binary_trees.h"

/**
 * binary_tree_levelorder -> Write a function that goes through
 *a binary tree using level-order traversal
 *
 *@tree: It's a pointer to the root node of the tree to traverse
 *@func: It's a pointer to a function to call for each node
 *Return: (tree or func) = (NULL) -> do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	size_t hei, b;

	if (tree == NULL || func == NULL)
	{

		return;

	}	hei = binary_tree_height(tree);

	for (b = 1; b <= hei; b++)
	{

		binary_level(tree, b, func);

	}

}

/**
 * binary_tree_height -> Write a function that measures
 *the height of a binary tree
 *
 *@tree: It's a pointer to the root node of the tree to measure the height
 *Return: tree = (NULL) -> (0)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t le, ri;

	if (tree == NULL)
	{

		return (0);

	}	le = binary_tree_height(tree->left);
	ri = binary_tree_height(tree->right);

	if (le >= ri)
	{

		return (1 + le);

	}	return (1 + ri);

}

/**
 * binary_level -> Write a function is used to perform
 *a function on a specific level of a binary tree
 *
 *@tree: It's a pointer to the root of the tree
 *@level: It's the level of the tree to perform the function on
 *@func: It's the function to perform
 *Return: tree = (NULL) -> (0) -> (void)
 */

void binary_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{

	if (tree == NULL)
	{

		return;
	}

	if (level == 1)
	{

		func(tree->n);
	}

	else if (level > 1)
	{
		binary_level(tree->left, level - 1, func);
		binary_level(tree->right, level - 1, func);
	}

}
