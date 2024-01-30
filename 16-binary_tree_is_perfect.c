#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 *
 * @tree: pointer to root of the tree
 * Return: balance factor, 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{	
	if (tree)
	{
		if (binary_tree_balance(tree) == 0)
			{
				if (binary_tree_leaves(tree->left) ==
				binary_tree_leaves(tree->right))
					return (1);
			}
		return (0);
	}	
	return (0);
}

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

/**
 * binary_tree_leaves - function to count binary tree leaves
 *
 * @tree: pointer to root of the tree
 * Return: tree leaves count, 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_count = 0;

	if (tree)
	{
		if (!tree->right && !tree->left)
			return (1);
		leaves_count = binary_tree_leaves(tree->left)
		+ binary_tree_leaves(tree->right);
		return (leaves_count);
	}

	return (0);
}
