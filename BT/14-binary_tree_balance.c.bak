#include "binary_trees.h"

/**
 * binary_tree_balance
 * @tree: pointer to root node of tree to measure
 * Return: balance factor left height minus right height, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
return(binaryHeight(tree->left) - binaryHeight(tree->right));

}

/**
 * binaryHeight - Measure the height
 * @tree: pointer to node of tree to measure
 * Return: height of tree or -1 if NULL
 */
int binaryHeight(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);

	if (!tree->left && tree->right == NULL)
		return (0);

	left = binaryHeight(tree->left) + 1;
	right = binaryHeight(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

