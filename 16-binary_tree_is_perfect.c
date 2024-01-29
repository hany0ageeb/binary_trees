#include "binary_trees.h"

/**
 * b_tree_is_perfect - checks if tree is perfect
 * @tree: a pointer to the root node of tree
 * @depth: total depth of tree
 * @level: node level
 * Return: 1 if perfect or tree is null otherwise 0
 */
static int b_tree_is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1 ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (b_tree_is_perfect(tree->left, depth, level + 1) &&
			b_tree_is_perfect(tree->right, depth, level + 1));
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
	int depth = 1;
	binary_tree_t *node = tree->left;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	while (node != NULL)
	{
		depth += 1;
		node = node->left;
	}
	return (b_tree_is_perfect(tree, depth, 0));
}
