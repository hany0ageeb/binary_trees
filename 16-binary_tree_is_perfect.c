#include "binary_trees.h"

/**
 * bt_depth - calcukate the depth of the tree
 * @root: the root node of the tree
 * Return: depth of tree
 */
int bt_depth(const binary_tree_t *root)
{
	int depth = 0;

	while (root != NULL)
	{
		depth++;
		root = root->left;
	}
	return (depth);
}
/**
 * is_perfect - check if a binary tree is perfect
 * @tree: the root node of the tree.
 * @depth: depth of the tree
 * @lvl: current level
 * Return: 1 if perfect 0 otherwise.
 */
int is_perfect(const binary_tree_t *tree, int depth, int lvl)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (depth == lvl + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, depth, lvl + 1) &&
			is_perfect(tree->right, depth, lvl + 1));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * every internal node has exactly two child nodes and
 * all the leaf nodes are at the same level.
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or not perfect otherwise 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	depth = bt_depth(tree);
	return (is_perfect(tree, depth, 0));
}
