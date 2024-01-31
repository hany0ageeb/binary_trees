#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bst_find - find value in binary search tree
 * @root: root node of the tree
 * @value: value to find
 * Return: node with value or NULL if not found
 */
bst_t *bst_find(bst_t *root, int value)
{
	while (root != NULL)
	{
		if (root->n == value)
			return (root);
		else if (root->n < value)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}
/**
 * find_in_order_successor - find node in order predecessor
 * @node: node to find its predecessor
 * Return: the prdecessor of node
 */
bst_t *find_in_order_successor(bst_t *node)
{
	bst_t *p;

	if (node->right != NULL)
	{
		node = node->right;
		while (node->left != NULL)
			node = node->left;
		return (node);
	}
	else
	{
		p = node->parent;
		while (p != NULL && node != p->right)
		{
			node = p;
			p = p->parent;
		}
		return (p);
	}
}
/**
 * bst_rm_leaf - remove leaf node
 * @node: node to remove
 */
void bst_rm_leaf(bst_t *node)
{
	if (node->parent != NULL && node->parent->left == node)
	{
		if (node->parent != NULL && node->parent->left == node)
			node->parent->left = NULL;
		else if (node->parent != NULL && node->parent->right == node)
			node->parent->right = NULL;
	}
}
/**
 * bst_remove_internal_node - remove non leaf node
 * @node: node to remove
 * @successor: its successor
 */
void bst_remove_internal_node(bst_t *node, bst_t *successor)
{
	if (successor->parent != NULL)
	{
		if (successor->parent->left == successor)
			successor->parent->left = NULL;
		else
			successor->parent->right = NULL;
	}
	successor->parent = node->parent;
	if (successor->parent != NULL)
	{
		if (successor->parent->left == node)
			successor->parent->left = successor;
		else
			successor->parent->right = successor;
	}
	successor->left = node->left;
	if (node->left != NULL)
		node->left->parent = successor;
	successor->right = node->right;
	if (node->right != NULL)
		node->right->parent = successor;
}
/**
 * bst_remove -  removes a node from a Binary Search Tree
 * @root:  a pointer to the root node of the tree where you will remove a node
 * @value:  the value to remove in the tree
 * Return:  pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = bst_find(root, value);
	bst_t *successor = NULL;

	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
			bst_rm_leaf(node);
		else
		{
			successor = find_in_order_successor(node);
			if (successor != NULL)
			{
				if (node->right != NULL)
					bst_remove_internal_node(node, successor);
				else if (node->parent == successor)
				{
					node->left->parent = successor;
					if (successor->right == node)
						successor->right = node->left;
				}
			}
		}
	}
	if (root == node)
		root = successor;
	if (node != NULL)
		free(node);
	return (root);
}
