#include "binary_trees.h"

/**
 * count_nodes - count number of nodes
 * @root: the root of the tree
 * Return: the number of nodes in the tree
 */
static int count_nodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}
/**
 * is_complete - the core function
 * @root: the root of the tree
 * @index: index
 * @num_nodes: number of nodes
 * Return: 1 if complete otherwise 0
 */
static int is_complete(const binary_tree_t *root, int index, int num_nodes)
{
	if (root == NULL)
		return (1);
	if (index >= num_nodes)
		return (0);
	return (is_complete(root->left, 2 * index + 1, num_nodes) &&
			is_complete(root->right, 2 * index + 2, num_nodes));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * A complete binary tree is a binary tree in which
 * all the levels are completely filled except
 * possibly the lowest one, which is filled from the left.
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if not complete or tree is NULL otherwise 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int num_nodes;

	if (tree == NULL)
		return (0);
	num_nodes = count_nodes(tree);
	return (is_complete(tree, 0, num_nodes));
}
