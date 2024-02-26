#include "binary_trees.h"
/**
 * binary_tree_height - Measure the height of a binary tree from a given node
 * @tree: pointer to node of tree to measure
 * Return: height of tree or 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	size_t left = binary_tree_height(tree->left);
	size_t right = binary_tree_height(tree->right);

	return (1 + (left > right ? left : right));
}
/**
 * binary_tree_levelorder - level-order traversal
 * @tree: pointer to the tree
 * @func: pointer to a function
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, level = 1;

	if (!tree || func == NULL)
		return;

	height = binary_tree_height(tree);


	while(level <= height + 1)
	{
		print_nodes_at_level(tree, func, level);

		level++;
	}
}

/**
 * print_nodes_at_level - print the nodes at a specific level
 * @node: pointer to the node
 * @func: pointer to a function
 * @level: the level
 * Return: nothing
 */
void print_nodes_at_level(const binary_tree_t *node, void (*func)(int), int level)
{
	if (!node || level < 1)
		return;

	if (level == 1)
		func(node->n);
	else
	{
		print_nodes_at_level(node->left, func, level - 1);
		print_nodes_at_level(node->right, func, level - 1);
	}
}

