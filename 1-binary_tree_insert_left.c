#include "binary_trees.h"

/**
 * binary_tree_insert_left -> Write a function that inserts a node
 *as the left-child of another node
 *
 *@parent: It's a pointer to the node to insert the left-child in
 *@value: It's the value to store in the new node
 *Return: A pointer to the created node or (NULL)-> failure or parent
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *nnode;

	if (parent == NULL)
	{
		return (NULL);

	}	nnode = binary_tree_node(parent, value);

	if (nnode == NULL)

		return (NULL);

	if (parent->left != NULL)
	{
		nnode->left = parent->left;
		parent->left->parent = nnode;

	}	parent->left = nnode;
	return (nnode);

}
