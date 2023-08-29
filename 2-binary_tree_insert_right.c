#include "binary_trees.h"

/**
 * binary_tree_insert_right -> Write a function that inserts a node
 *as the right-child of another node
 *
 *@parent: It's a pointer to the node to insert the right-child in
 *@value: It's the value to store in the new node
 *Return: A pointer to the created node or (NULL)-> failure or parent
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

	binary_tree_t *nnode;

	if (parent == NULL)
	{
		return (NULL);

	}	nnode = binary_tree_node(parent, value);

	if (nnode == NULL)

		return (NULL);

	if (parent->right != NULL)
	{
		nnode->right = parent->right;
		parent->right->parent = nnode;

	}	parent->right = nnode;
	return (nnode);

}
