#include "binary_trees.h"

/**
 * heap_extract -> Write a function to extract root node of Max Binary Heap
 *@root: It's a double pointer to the root node of heap
 *Return: The value stored in the root node, if fails -> (0)
 */

int heap_extract(heap_t **root)
{
	size_t size, x;
	char *binary, y, buffer[50];
	int res;
	heap_t *tmp, *head;

	if (!root || !*root)
	{
		return (0);
	}	SETUP_NODE_BLOC;

	if (size == 1)
	{
		FREE_NODE_BLOC;
		return (res);	}
	do {
		CONVERT_LOOP;
	} while (size);

	for (x = 1; x < strlen(binary); x++)
	{
		y = binary[x];
		if (x == strlen(binary) - 1)
		{
			if (y == '1')
			{
				tmp = tmp->right;
				break;			}
			else if (y == '0')
			{
				tmp = tmp->left;
				break;			}
		}
		if (y == '1')
			tmp = tmp->right;
		else if (y == '0')
			tmp = tmp->left;
	}	SWAP_HEAD_BLOC;
	return (res);
}

/**
 * swap -> Write a function to swap 2 nodes in binary tree
 *@f: It's a first node
 *@s: It's a second node
 *Return: A pointer to root
 */

bst_t *swap(bst_t *f, bst_t *s)
{
	bst_t a_copy = INIT_NODE;

	a_copy.n = f->n;
	a_copy.parent = f->parent;
	a_copy.left = f->left;
	a_copy.right = f->right;
	f->parent = s;
	f->left = s->left;
	f->right = s->right;
	if (s->left)
		s->left->parent = f;
	if (s->right)
		s->right->parent = f;
	s->parent = a_copy.parent;
	if (a_copy.parent)
	{
		if (f == a_copy.parent->left)
			a_copy.parent->left = s;
		else
			a_copy.parent->right = s;
	}
	if (s == a_copy.left)
	{
		s->left = f;
		s->right = a_copy.right;
		if (a_copy.right)
			a_copy.right->parent = s;
	}
	else if (s == a_copy.right)
	{
		s->right = f;
		s->left = a_copy.left;
		if (a_copy.left)
			a_copy.left->parent = s;
	}
	while (s->parent)
	{
		s = s->parent;
	}  return (s);
}

/**
 * binary_tree_size -> Write a function that measures size of a binary tree
 *@tree: It's a binary tree
 *Return: An number of descendant child
 */

size_t binary_tree_size(const binary_tree_t *tree)
{

	if (!tree)
	{

		return (0);

	}	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));

}

/**
 * swap_head -> Write a function to help swap head and node
 *@head: It's a pointer to head
 *@node: It's a pointer to node
 *Return: A pointer to severed head
 */

heap_t *swap_head(heap_t *head, heap_t *node)
{

	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	}

	else
	{

		node->parent->right = NULL;

	}	node->parent = NULL;
	node->left = head->left;
	node->right = head->right;

	if (head->left)
	{

		head->left->parent = node;

	}

	if (head->right)
	{

		head->right->parent = node;

	}	return (head);

}

/**
 * percy -> Write a function to percolate head into correct position
 *@node: It's a pointer to head of node
 *Return: A pointer of node
 */

heap_t *percy(heap_t *node)
{
	int maxx;
	heap_t *next = node;

	if (!node)
	{

		return (NULL);

	}	maxx = node->n;

	if (node->left)
	{
		maxx = MAX(node->left->n, maxx);
	}

	if (node->right)
		maxx = MAX(node->right->n, maxx);

	if (node->left && maxx == node->left->n)
		next = node->left;

	else if (node->right && maxx == node->right->n)
		next = node->right;

	if (next != node)
	{
		swap(node, next);
		percy(node);

	}	return (next);
}
