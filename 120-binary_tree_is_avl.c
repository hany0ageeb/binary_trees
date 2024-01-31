#include "binary_trees.h"
#include <limits.h>

/**
 * height - get tree height i.e max depth
 * @tree: a pointer to tree root node
 * Return: tree height
 */
static int height(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);
	l_height = height(tree->left);
	r_height = height(tree->right);
	if (l_height > r_height)
		return (1 + l_height);
	return (1 + r_height);
}
/**
 * is_bst - check if tree is valid binary serch tree
 * @tree: a pointer to the tree root node
 * @min: minimum value
 * @max: maximum value
 * Return: 0 if not BST otherwise 1
 */
static int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, max));
}
/**
 * is_avl - check if tree is valid AVL tree
 * @tree: a pointer to tree root node
 * Return: 1 if valid AVL otherwise 0
 */
static int is_avl(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0, diff = 0;

	if (tree == NULL)
		return (1);
	left_height = height(tree->left);
	right_height = height(tree->right);
	diff = left_height - right_height;
	if (diff < 0)
		diff *= -1;
	return (diff <= 1 && is_avl(tree->left) && is_avl(tree->right));
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * AVL Tree: In an AVL tree, the heights of the two child subtrees
 * of any node differ by at most one;
 * if at any time they differ by more than one,
 * rebalancing is done to restore this property.
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or not AVL tree otherwise 1
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);
	return (is_avl(tree));
}
