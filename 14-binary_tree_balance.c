#include "binary_trees.h"

/**
 * binary_tree_balance - function to calculate binary tree balance factor
 *
 * @tree: pointer to root of the tree
 * Return: balance factor, 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;

	if (tree)
	{
		balance_factor = bin_tree_height(tree->left) -
		bin_tree_height(tree->right);
		return (balance_factor);
	}
	return (0);
}


/**
 * bin_tree_height - function to calculate binary tree height
 *
 * @tree: pointer to root of the tree
 * Return: tree height
 */

int bin_tree_height(binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree)
	{
		left_height = 1 + bin_tree_height(tree->left);
		right_height = 1 + bin_tree_height(tree->right);
		if (left_height > right_height)
			return (left_height);
		else
			return (right_height);
	}
	return (0);
}
