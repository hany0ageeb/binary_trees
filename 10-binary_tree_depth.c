#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * depth is the number of edges present in path from the root node
 * of a tree to that node.
 * @tree: a pointer to the node to measure the depth
 * Return: 0 if tree is NULL otherwise the depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
