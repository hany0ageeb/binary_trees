#include "binary_trees.h"

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: return a pointer to the lowest common ancestor
 * node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int first_depth = 0, second_depth = 0;
	binary_tree_t *tmp, *f, *s;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->parent == second->parent)
		return (first->parent);
	tmp = first->parent;
	while (tmp != NULL)
	{
		tmp = tmp->parent;
		first_depth++;
	}
	tmp = second->parent;
	while (tmp != NULL)
	{
		tmp = tmp->parent;
		second_depth++;
	}
	f = first->parent;
	s = second->parent;
	while (first_depth > second_depth
}
