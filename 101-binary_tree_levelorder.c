#include "binary_trees.h"
#include <stdlib.h>

queue_t *queue_create()
{
	queue_t *q = malloc(sizeof(queue_t));
	q->front = NULL;
	q->rear = NULL;
	return (q);
}
void queue_delete(queue_t *q)
{
	queue_node_t *tmp = NULL;

	if (q != NULL)
	{
		while(q->front != NULL)
		{
			tmp = q->front;
			free(tmp);
			q->front = q->front->next;
		}
		free(q);
	}
}
queue_node_t *queue_enqueue(queue_t *q, binary_tree_t *node)
{
	queue_node_t *tmp = NULL;

	if (q != NULL)
	{
		tmp = malloc(sizeof(queue_node_t));
		if (tmp != NULL)
		{
			tmp->node = node;
			tmp->next = NULL;
			if (q->front == NULL)
			{
				q->front = tmp;
				q->rear = tmp;
			}
			else
			{
				q->rear->next = tmp;
				q->rear = tmp;
			}
		}
	}
	return (tmp);
}
binary_tree_t *queue_dequeue(queue_t *q)
{
	queue_node_t *tmp = NULL;
	binary_tree_t *node = NULL;

	if (q != NULL)
	{
		if (q->front != NULL)
		{
			tmp = q->front;
			q->front = q->front->next;
			node = tmp->node;
			free(tmp);
			if (q->front == NULL)
				q->rear = NULL;
		}
	}
	return (node);
}
/**
 * binary_tree_levelorder -  goes through a binary tree using level-order traversal
 * level-order traversal access nodes in level by level order
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *q = NULL;
	binary_tree_t *tmp = NULL;

	if (tree == NULL || func == NULL)
		return;
	q = queue_create();
	if (q != NULL)
	{
		func(tree->n);
		if (tree->left != NULL)
			queue_enqueue(q, tree->left);
		if (tree->right != NULL)
			queue_enqueue(q, tree->right);
		do {
			tmp = queue_dequeue(q);
			if (tmp != NULL)
			{
				func(tmp->n);
				if (tmp->left != NULL)
					queue_enqueue(q, tmp->left);
				if (tmp->right != NULL)
					queue_enqueue(q, tmp->right);
			}
		} while(tmp != NULL);
		queue_delete(q);
		q = NULL;
	}
}
