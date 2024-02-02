#include "binary_trees.h"

avl_t *avl_self_balance(avl_t *node);
int bin_tree_height(binary_tree_t *tree);
avl_t *avl_insert_bst(avl_t *root, avl_t *node);
int is_balanced_avl(const binary_tree_t *tree);

/**
 * avl_insert - inserts node to BST
 *
 * @tree: pointer to root of the tree to traverse
 * @value: node value
 * Return: pointer to inserted node , NULL if failed
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!tree)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!*tree)
	{
		*tree = node;
		return (node);
	}
	node = avl_insert_bst(*tree, node);
	if (node)
		*tree = avl_self_balance(node);
	return (node);
}

/**
 * avl_insert_bst - inserts node to BST
 *
 * @root: pointer to root of the tree to traverse
 * @node: pointer to the node to insert
 */
avl_t *avl_insert_bst(avl_t *root, avl_t *node)
{
	if (root->n > node->n)
	{
		if (!root->left)
		{
			root->left = node;
			node->parent = root;
			return node;
		}
		return (avl_insert_bst(root->left, node));
	}
	if (root->n < node->n)
	{
		if (!root->right)
		{
			root->right = node;
			node->parent = root;
			return node;
		}
		return (avl_insert_bst(root->right, node));
	}
	free(node);
	return NULL;
}

/**
 * avl_self_balance - the magic of the AVL tree
 *
 * @node: pointer to the node you just inserted
 * Return: the root of the balanced tree
 */
avl_t *avl_self_balance(avl_t *node)
{
	avl_t *parent = node->parent;
	char step1, step2;

	while (parent)
	{
		step1 = parent->left == node ? 'L' : 'R';
		if (is_balanced_avl(parent) == 0)
		{
			if (step1 == 'L' && step2 == 'L')
				parent = binary_tree_rotate_right(parent);

			if (step1 == 'R' && step2 == 'R')
				parent = binary_tree_rotate_left(parent);

			if (step1 == 'L' && step2 == 'R')
			{
				parent->left = binary_tree_rotate_left(parent->left);
				parent = binary_tree_rotate_right(parent);
			}
			if (step1 == 'R' && step2 == 'L')
			{
				parent->right = binary_tree_rotate_right(parent->right);
				parent = binary_tree_rotate_left(parent);
			}
		}
		step2 = step1;
		node = parent;
		parent = node->parent;
	}
	return (node);
}


/**
 * is_balanced_avl - check if binary tree is AVL
 *
 * @tree: pointer to root of the tree to traverse
 * Return: 1 if AVL , 0 if not or tree is NULL
 */
int is_balanced_avl(const binary_tree_t *tree)
{
	int diff;

	if (!tree)
		return (1);

	diff = bin_tree_height(tree->left) - bin_tree_height(tree->right);
	if (diff > 1 || diff < -1)
		return (0);

	return (is_balanced_avl(tree->left) && is_balanced_avl(tree->right));
}
