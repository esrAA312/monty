#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node
 *
 * @parent: a pointer to the parent node
 *
 * @value: the value to put in a new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nNode;

	nNode = malloc(sizeof(binary_tree_t));
	if (nNode == NULL)
		return (NULL);

	nNode->n = value;
	nNode->parent = parent;
	nNode->left = NULL;
	nNode->right = NULL;

	return (nNode);
}

