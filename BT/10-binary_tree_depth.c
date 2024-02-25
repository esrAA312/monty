#include "binary_trees.h"

/**
 * binary_tree_depth - Measure the depth of a binary tree from a given node
 * @tree: pointer to node of tree to measure
 * Return: depth of tree or 0 if NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

