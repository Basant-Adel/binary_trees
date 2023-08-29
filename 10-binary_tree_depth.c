#include "binary_trees.h"

/**
 * binary_tree_depth -> Write a function that measures
 *the depth of a node in a binary tree
 *
 *@tree: It's a pointer to the node to measure the depth
 *Return: tree = (NULL) -> (0)
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{

	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);

}
