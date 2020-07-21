#include "binary_trees.h"

/**
* bst_remove - removes a node value from the tree
* Return: pointer to new root node of the tree
* @root: the root of the tree to remove from
* @value: the value to check for/remove
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *todel, *successor;

	todel = bst_search(root, value);
	if (!todel)
		return (NULL);
	if (todel->right && todel->left)
	{
		successor = io_successor(todel->right);
		return (twokids(root, todel, successor));
/*
*		if (successor)
*		{
*			printf("successor is %i\n", successor->n);
*			successor->parent->left = successor->right;
*			successor->right = successor->parent;
*			successor->parent = todel->parent;
*			successor->left = todel->left;
*			successor->left->parent = successor;
*			successor->right->parent = successor;
*			printf("i know where the seg faults\n");
*		}
*/
	}
	else if (todel->right)
		{
		successor = todel->right;
		successor->parent = todel->parent;
		}
	else
		{
		successor = todel->left;
		successor->parent = todel->parent;
		}
	if (successor->parent)
	{
		if (successor->parent->left == todel)
			successor->parent->left = successor;
		else
			successor->parent->right = successor;
	}
/*	printf("past successor stuff\n");*/
	if (todel == root)
	{
		free(todel);
		return (successor);
	}
	free(todel);
	return (root);
}
/**
* twokids - performs deletion if the node has two kids
* Return: the succesor in the right place
* @root: the root node
* @todel:the node to delete
* @successor: the usccessor node
*/
bst_t *twokids(bst_t *root, bst_t *todel, bst_t *successor)
{
	if (successor)
	{
		successor->parent->left = successor->right;
		successor->right = successor->parent;
		successor->parent = todel->parent;
		if (successor->parent)
		{
			if (successor->parent->left == todel)
				successor->parent->left = successor;
			else
				successor->parent->right = successor;
		}
		successor->left = todel->left;
		successor->left->parent = successor;
		successor->right->parent = successor;
	}
	if (todel == root)
	{
		free(todel);
		return (successor);
	}
	free(todel);
	return (root);
}
/**
* io_successor - finds next in order successor
* Return: pointer to the successor
* @root: the root node to check from
*/
bst_t *io_successor(bst_t *root)
{
	if (!root)
		return (NULL);
	if (!(root->left))
		return (root);
	return (io_successor(root->left));
}
/**
* bst_search - searches ths bst
* Return: return pointer to node with valu
* @tree: pointer to root node
* @value: value to search for
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *) tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
