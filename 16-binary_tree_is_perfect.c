#include "binary_trees.h"

/**
 * binary_tree_is_perfect -> Write func to check if binary tree is perfect
 *@tree: It's  a pointer to the root node of the tree to check
 *Return: tree = (NULL) -> (0)
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (tree == NULL)
	{

		return (0);

	}	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));

}

/**
 * depth -> Write a function that measures
 *the depth of a node in a binary tree
 *
 *@tree: It's a pointer to the node to measure the depth
 *Return: tree = (NULL) -> (0)
 */

size_t depth(const binary_tree_t *tree)
{

	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);

}

/**
 * get_leaf -> Write a function that checks if a node is a leaf
 *@tree: It's a pointer to the node to check
 *Return: node = (tree)-> (1)
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{

	if (is_leaf(tree) == 1)
	{

		return (tree);

	}	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));

}

/**
 * is_perfect_recursive -> It's a perfect recursive
 *@tree: It's a pointer to the node to check
 *@leaf_depth: It's a leaf depth
 *@level: It's a level
 *Return: tree = (NULL) -> (0)
 */

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{

	if (is_leaf(tree))

		return (level == leaf_depth ? 1 : 0);

	if (tree->left == NULL || tree->right == NULL)
	{

		return (0);

	}	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * is_leaf -> Write a function to Check if a node is a leaf of a binary tree
 *@node: It's a pointer to the node
 *Return: (node) = (leaf)-> (1) otherwise -> (0)
 */

unsigned char is_leaf(const binary_tree_t *node)
{

	return ((node->left == NULL && node->right == NULL) ? 1 : 0);

}
