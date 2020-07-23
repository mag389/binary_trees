#include "binary_trees.h"

/**
* avl_insert - inserts new avl node
* Return: created node
* @tree: the tree to add to
* @value: new number to add
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newt, *temp, *temp2, *ncheck;

	printf("tying to insert %i\n", value);
	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	ncheck = (*tree)->parent;
	if ((*tree)->n == value)
		return (*tree);
	if ((*tree)->n > value)
	{
		if (!((*tree)->left))
		{
			(*tree)->left = binary_tree_node(*tree, value);
			newt = (*tree)->left;
			temp = rebalance((*tree)->left);
/*			if (temp)
				printf("temp issa %i\n", temp->n);
			else
				printf("apparently tmep is null for the rebalance here\n");
			if (temp && !(temp->parent))
				printf("##########################\n");
			while ((*tree)->parent && 0)
				*tree = (*tree)->parent;
			if (temp && temp->parent == NULL && (*tree)->parent == NULL)
				*tree = temp;*/
			return (newt);
		}
		else
		{
			temp = avl_insert((&(*tree)->left), value);
/*			if (temp && !(temp->parent) && (*tree)->parent == NULL)
				*tree = temp;*/
			return (temp);
		}
	}
	else if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
		{
			printf("is 514 here\n");
			(*tree)->right = binary_tree_node(*tree, value);
			newt = (*tree)->right;
			temp = rebalance((*tree)->right);
/*                      if (temp)
                                printf("temp issa %i\n", temp->n);
                        else
                                printf("apparently tmep is null for the rebalance here\n");
                        if (temp && !(temp->parent))
			{
                                printf("********************************\n");
				printf("tree is %i\n", (*tree)->n);
				while ((*tree)->parent)
					*tree = (*tree)->parent;
			}
			if (temp && temp->parent == NULL && (*tree)->parent == NULL)
				*tree = temp;
*/
			return (newt);
		}
		else
		{
			printf("we're in the else!!!!!!!\n");
			temp = avl_insert((&(*tree)->right), value);
			printf("I think here's where we need to change\n");
			temp2 = temp;
			while (temp2 && temp2->parent)
			{
				printf("++++++++++++++++++++++++++++++\n");
				binary_tree_print(temp2);
				temp2 = temp2->parent;
				printf("===============================\n");
			}
			printf("is the where it segafults\n");
			if (temp2 && *tree && !(temp2->parent) && (*tree)->parent && !ncheck)
				*tree = temp2;
			printf("nope %i\n", temp2->n);
			
/*			if (temp && !(temp->parent) && !((*tree)->parent))
			{
				*tree = temp;
				printf("actually changed in the other section\n");
			}
*/
/*			while ((*tree)->parent != NULL)
				*tree = (*tree)->parent;*/
			return (temp);
		}
	}
	(void) temp;
	return (NULL);
}

/**
* rebalance - rebalnces the avl tree from new node up
* Return: the inserted(given arg) node
* @newt: the newly inserted node
*/
avl_t *rebalance(avl_t *newt)
{
	int balance;
	avl_t *temp;

	if (!newt || !(newt->parent) || !(newt->parent->parent))
		return (NULL);
	printf("--------------------------------------------\n");
	binary_tree_print(newt->parent->parent);
	balance = binary_tree_balance(newt->parent->parent);
	if (balance <= 1 && balance >= -1)
		return (rebalance(newt->parent));
	if (balance > 1)
	{
		if (newt->n > newt->parent->n)
		{
			newt->parent->parent->left = binary_tree_rotate_left(newt->parent);
			temp = binary_tree_rotate_right(newt->parent);
			return (temp);
		}
		temp = binary_tree_rotate_right(newt->parent->parent);
		return (temp);
	}
	else
	{
		if (newt->n < newt->parent->n)
		{
			binary_tree_rotate_right(newt->parent);
			temp = binary_tree_rotate_left(newt->parent);
			return (temp);
		}
		temp = binary_tree_rotate_left(newt->parent->parent);
		return (temp);
	}
}
