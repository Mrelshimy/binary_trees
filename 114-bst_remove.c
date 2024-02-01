#include "binary_trees.h"

/**
 * bst_remove - remove node from BST
 *
 * @root: pointer to tree
 * @value: value of node to delete
 * Return: pointer to new tree after node deleted, NULL if failed
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *search_pointer = root, *new_root;

	if (root && value)
	{
		search_pointer = bst_search(root, value);
		if (search_pointer->right == NULL && search_pointer->left == NULL)
		{
			if (search_pointer == root)
				root = NULL;
			else if (search_pointer == search_pointer->parent->left)
				search_pointer->parent->left = NULL;
			else
				search_pointer->parent->right = NULL;
			free(search_pointer);
			return (root);
		}

		if (search_pointer->left == NULL || search_pointer->right == NULL)
		{
			new_root = one_child_nodes(search_pointer, root);
			return (new_root);
		}

		new_root = two_child_nodes(search_pointer, root);
		return (new_root);
	}
	return (NULL);
}


/**
 * two_child_nodes - get the first inorder successor of the node
 *
 * @root: pointer to tree
 * @node: node
 * Return: pointer to new tree after node deleted, NULL if failed
 */

bst_t *two_child_nodes(bst_t *node, bst_t *root)
{
	bst_t *search_pointer = node->right;

	while (search_pointer->left)
		search_pointer = search_pointer->left;
	if (search_pointer->parent->left == search_pointer)
		search_pointer->parent->left = NULL;
	else
		search_pointer->parent->right = NULL;
	search_pointer->parent = node->parent;
	if (node != root)
	{
		if (node == node->parent->left)
			node->parent->left = search_pointer;
		else
			node->parent->right = search_pointer;
	}
	search_pointer->right = node->right;
	if (node->right)
		node->right->parent = search_pointer;
	search_pointer->left = node->left;
	if (node->left)
		node->left->parent = search_pointer;
	if (node == root)
		root = search_pointer;
	free(node);
	return (root);
}


/**
 * one_child_nodes - delete node with 1 child
 *
 * @root: pointer to tree
 * @node: node
 * Return: pointer to new tree after node deleted, NULL if failed
 */

bst_t *one_child_nodes(bst_t *node, bst_t *root)
{
	if (node && root)
	{
		if (node->right == NULL)
		{
			if (node == root)
			{	root = root->left;
				free(node);
				return (root);
			}
			node->left->parent = node->parent;
			if (node == node->parent->left)
				node->parent->left = node->left;
			else
				node->parent->right = node->left;
			free(node);
			return (root);
		}
		if (node->left == NULL)
		{
			if (node == root)
			{	root = root->right;
				free(node);
				return (root);
			}
			node->right->parent = node->parent;
			if (node == node->parent->left)
				node->parent->left = node->right;
			else
				node->parent->right = node->right;
			free(node);
			return (root);
		}
	}
	return (NULL);
}
