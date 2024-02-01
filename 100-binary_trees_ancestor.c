#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest commont ancestor of 2 nodes
 *
 * @first:  pointer to the first  node
 * @second: pointer to the second node
 * Return:  pointer to the lowest common ancestor (if found)
 */
binary_tree_t *
binary_trees_ancestor(
	const
	binary_tree_t *
	first,

	const
	binary_tree_t *
	second
)
{
	binary_tree_t *s, *f = (binary_tree_t *)first;

	while (f)
	{
		s = (binary_tree_t *)second;
		while (s)
		{
			if (s == f)
				return (s);
			s = s->parent;
		}
		f = f->parent;
	}
	return (NULL);
}
