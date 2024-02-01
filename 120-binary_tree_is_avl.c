#include "binary_trees.h"

int bin_tree_is_balanced(const binary_tree_t *tree);
int bin_tree_height(binary_tree_t *tree);
int node_value_checker(const binary_tree_t *tree, int min_val, int max_val);

/**
 * binary_tree_is_avl - check if binary tree is AVL
 *
 * @tree: pointer to root of the tree to traverse
 * Return: 1 if AVL , 0 if not or tree is NULL
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (
		node_value_checker(tree, INT_MIN, INT_MAX) &&
		bin_tree_is_balanced(tree)
	);
}


/**
 * bin_tree_is_balanced - check if binary tree is AVL
 *
 * @tree: pointer to root of the tree to traverse
 * Return: 1 if AVL , 0 if not or tree is NULL
 */

int bin_tree_is_balanced(const binary_tree_t *tree)
{
	int diff;

	if (!tree)
		return (1);

	diff = bin_tree_height(tree->left) - bin_tree_height(tree->right);
	if (diff > 1 || diff < -1)
		return (0);

	return (
		bin_tree_is_balanced(tree->left) &&
		bin_tree_is_balanced(tree->right)
	);
}


/**
 * bin_tree_height - function to calculate binary tree height
 *
 * @tree: pointer to root of the tree
 * Return: tree height
 */

int bin_tree_height(binary_tree_t *tree)
{
	int height_l;
	int height_r;

	if (!tree)
		return (-1);

	height_l = 1 + bin_tree_height(tree->left);
	height_r = 1 + bin_tree_height(tree->right);
	return (height_l > height_r ? height_l : height_r);
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
