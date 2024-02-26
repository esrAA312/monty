#include "binary_trees.h"

/**
 * binary_tree_insert_left
 *
 * @parent: a pointer to the parent node of the node to create
 *
 * @value: the value to put in a new node
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nNode;

	if (!parent)
		return (NULL);

	nNode = binary_tree_node(parent, value);
	if (!nNode)
		return (NULL);

	if (parent->left)
	{
		nNode->left = parent->left;
		parent->left->parent = nNode;
	}
	parent->left = nNode;

	return (nNode);
}

