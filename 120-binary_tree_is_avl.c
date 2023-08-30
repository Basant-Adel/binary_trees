#include "limits.h"
#include "binary_trees.h"

/**
 * binary_tree_is_avl -> Write a function that checks if
 *a binary tree is a valid AVL Tree
 *
 *@tree: It's a pointer to the root node of the tree to check
 *Return: (1)-> tree is valid AVL tree, (0)-> otherwise, (tree) = (NULL)-> (0)
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{

	if (tree == NULL)
	{

		return (0);

	}	return (is_avl(tree, INT_MIN, INT_MAX));

}

/**
 * height -> Write a function that Measures height of a binary tree
 *@tree: It's a pointer to the root node of the tree
 *Return: (tree) = (NULL)-> (0), (height)
 */

size_t height(const binary_tree_t *tree)
{

	if (tree)
	{

		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;

		return ((l > r) ? l : r);

	}	return (0);

}

/**
 * is_avl -> Write a function that Checks if a binary tree is valid AVL tree
 *@tree: It's a pointer to the root node
 *@sm: It's the value of the smallest node
 *@la: It's the value of the largest node
 *Return: (tree) is a valid AVL tree -> (1), otherwise -> (0)
 */

int is_avl(const binary_tree_t *tree, int sm, int la)
{
	size_t leh, rih, item;

	if (tree != NULL)
	{

		if (tree->n < sm || tree->n > la)
		{

			return (0);

		}	leh = height(tree->left);
		rih = height(tree->right);
		item = leh > rih ? leh - rih : rih - leh;

		if (item > 1)
		{

			return (0);

		}	return (is_avl(tree->left, sm, tree->n - 1) &&
				is_avl(tree->right, tree->n + 1, la));

	}	return (1);
}
