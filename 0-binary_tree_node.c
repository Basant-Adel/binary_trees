#include "binary_trees.h"

/**
 * binary_tree_node -> Write a function that creates a binary tree node
 *@parent: It's a pointer to the parent node of the node to create
 *@value: It's the value to put in the new node
 *Return: A Pointer to the new node or (NULL)-> failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *nnode = malloc(sizeof(binary_tree_t));

	if (nnode == NULL)
	{

		return (NULL);

	}	nnode->n = value;

	nnode->parent = parent;
	nnode->left = NULL;
	nnode->right = NULL;
	return (nnode);

}
