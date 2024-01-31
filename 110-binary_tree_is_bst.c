#include "binary_trees.h"

/**
 * binary_tree_is_bst - check if binary tree is BST
 *
 * @tree: pointer to root of the tree to traverse
 * Return: 1 if BST , 0 if not or tree is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree)
	{
		return (node_value_checker(tree, INT_MIN, INT_MAX));
	}
	return (0);
}


/**
 * node_value_checker - check node is within limits
 *
 * @tree: pointer to root of the tree to traverse
 * @min_val: minimum value for node
 * @max_val: max_value for node
 * Return: 1 if node within range, 0 if not
 */
int node_value_checker(const binary_tree_t *tree, int min_val, int max_val)
{
	if (!tree)
		return (1);

	if (tree->n < min_val || tree->n > max_val)
		return (0);

	return (node_value_checker(tree->left, min_val, tree->n - 1)
	&& node_value_checker(tree->right, tree->n + 1, max_val));
}
