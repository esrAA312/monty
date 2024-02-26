#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to find a leaf in.
 * Return: A pointer to the first leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (binary_tree_is_leaf(tree) == 1)
		return (tree);
	if (tree->left)
		return get_leaf(tree->left);
	else
		return get_leaf(tree->right);
}

/**
 * is_perfect- Checks if a binary tree is perfect recursively.
 * @tree: A pointer to check.
 * @D: The depth of one leaf.
 * @L: Level of current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect(const binary_tree_t *tree,
		size_t D, size_t L)
{
	int per_L, per_R;
	if (binary_tree_is_leaf(tree))
		return (L == D);
	if (!(tree->left) || !(tree->right))
		return (0);
	per_L = is_perfect(tree->left, D, L + 1);
	per_R = is_perfect(tree->right, D, L + 1);
	return (per_L && per_R);
}
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

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to check.
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t DI = 0, tB = 0;
	const binary_tree_t *LF;

	if (!tree)
		return (0);
	LF = get_leaf(tree);
	DI = binary_tree_depth(LF);
	tB = is_perfect(tree, DI, 0);
	return (tB);
}
