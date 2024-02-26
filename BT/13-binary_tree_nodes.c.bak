#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: nbr of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t conN = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		conN = 1;

	conN += binary_tree_nodes(tree->left);
	conN += binary_tree_nodes(tree->right);

	return (conN);
}

