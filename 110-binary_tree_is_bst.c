#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - check recursively if root is bst
 * @root: a pointer to the root node of the tree to check
 * @min: minimum value for root->n
 * @max: maximum value for root->n
 * Return: 1 if bst of root is NULL otherwise 0
 */
int is_bst(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
		return (1);
	if (root->n < min || root->n > max)
		return (0);
	if (root->left == NULL && root->right == NULL)
		return (1);
	if (root->left != NULL && root->left->n >= max)
		return (0);
	if (root->right != NULL && root->right->n <= root->n)
		return (0);
	return (is_bst(root->left, min, root->n - 1) &&
			is_bst(root->right, root->n + 1, max));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * BST has the follwing properties:
 * 1. all nodes in the left subtree has values less than the node's value.
 * 2. all nodes in the right subtree has values greater than node's value.
 * 3. Both left and right subtrees are also BST.
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or not valid BST otherwise 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
