#include "binary_trees.h"

/**
 * get_level - get node level and root node
 * @node: node to find its level
 * @root: set to he root node of node
 * Return: node level
 */
int get_level(const binary_tree_t *node, binary_tree_t **root)
{
	int lvl = 0;
	binary_tree_t *tmp = NULL;

	if (node == NULL)
	{
		*root = NULL;
		return (0);
	}
	tmp = (binary_tree_t *)node;
	while (tmp->parent != NULL)
	{
		lvl++;
		tmp = tmp->parent;
	}
	*root = tmp;
	return (lvl);
}
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
	binary_tree_t *f_root = NULL, *s_root = NULL, *f_node, *s_node;
	int f_lvl = 0, s_lvl = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	f_lvl = get_level(first, &f_root);
	s_lvl = get_level(second, &s_root);
	if (f_root == NULL || s_root == NULL)
		return (NULL);
	if (f_root != s_root)
		return (NULL);
	f_node = (binary_tree_t *)first;
	s_node = (binary_tree_t *)second;
	while (f_lvl > s_lvl && f_node != NULL)
	{
		f_node = f_node->parent;
		f_lvl--;
	}
	while (s_lvl > f_lvl && s_node != NULL)
	{
		s_node = s_node->parent;
		s_lvl--;
	}
	if (f_node == NULL || s_node == NULL)
		return (NULL);
	if (f_node == s_node)
		return (f_node);
	while (f_node != NULL && s_node != NULL)
	{
		if (f_node->parent == s_node->parent)
			return (f_node->parent);
		f_node = f_node->parent;
		s_node = s_node->parent;
	}
	return (NULL);
}
