#include "binary_trees.h"
bst_t *remove_onekid(bst_t *todel);
/**
* bst_remove - removes a node value from the tree
* Return: pointer to new root node of the tree
* @root: the root of the tree to remove from
* @value: the value to check for/remove
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *todel, *successor;

	printf("into the function\n");
	if (!root)
		return (NULL);
	printf("past root nullchekc\n");
	todel = bst_search(root, value);
	if (!todel)
		return (NULL);
	printf("past nullchecks\n");
	if (!(todel->right) && !(todel->left))
	{
		printf("into oduble null if\n");
		if (todel->parent && todel->parent->right == todel)
			todel->parent->right = NULL;
		if (todel->parent && todel->parent->left == todel)
			todel->parent->left = NULL;
		if (todel == root)
		{
			free(todel);
			return (NULL);
		}
		free(todel);
		return (root);
	}
	printf("past the no child if\n");
	if (todel->right && todel->left)
	{
		successor = io_successor(todel->right);
		printf("print successor: %i\n", successor->n);
		binary_tree_print(successor);
		todel->n = successor->n;
		if (root == todel)
		{
			printf("root is todel\n");
			remove_onekid(successor);
			return (root);
		}
		remove_onekid(successor);
		return (root);
	}
/* remove the one child node */
	if (todel == root)
		return (remove_onekid(todel));
	remove_onekid(todel);
	return (root);
/* older stuff below */
	if (todel->right)
		successor = todel->right;
	else
		successor = todel->left;
	successor->parent = todel->parent;
	if (successor->parent)
	{
		if (successor->parent->left == todel)
			successor->parent->left = successor;
		else
			successor->parent->right = successor;
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
* remove_onekid - removes node with one child
* Return: the node that took it's place
* @todel: the node to remove
*/
bst_t *remove_onekid(bst_t *todel)
{
	bst_t *replacement = NULL;

	printf("into remove onkid\n");
	if (!todel)
		return (NULL);
	printf("todel not null\n");
	if (todel->right)
	{
		printf("todel has a right\n");
		replacement = todel->right;
		todel->right->parent = todel->parent;
		if (todel->parent && todel->parent->left == todel)
			todel->parent->left = todel->right;
		if (todel->parent && todel->parent->right == todel)
			todel->parent->right = todel->right;
	}
	else if (todel->left)
	{
		printf("todel has a left");
		replacement = todel->left;
		todel->left->parent = todel->parent;
		if (todel->parent && todel->parent->left == todel)
			todel->parent->left = todel->left;
		if (todel->parent && todel->parent->right == todel)
			todel->parent->right = todel->left;
	}
	else
	{
		if (todel->parent && todel->parent->left == todel)
			todel->parent->left = NULL;
		if (todel->parent && todel->parent->right == todel)
			todel->parent->right = NULL;
	}
	free(todel);
	return (replacement);
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
	printf("into twokids todel: %i successor: %i\n", todel->n, successor->n);
	if (successor)
	{
		printf("into the successor if\n");
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
		if (successor->left)
			successor->left->parent = successor;
		if (successor->right)
			successor->right->parent = successor;
	}
	printf("ended successor\n");
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
