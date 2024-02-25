#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 *
 * @node: A pointer to the node to find the uncle.
 *
 * Return: A pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandPA;

	if (!node || !node->parent || node->parent->parent == NULL)
	{
		return (NULL);
	}

	grandPA = node->parent->parent;

	if (grandPA->left == node->parent)
	{
		return (grandPA->right);
	}
	else
	{
		return (grandPA->left);
	}
}

