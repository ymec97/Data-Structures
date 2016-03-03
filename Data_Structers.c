#include "Data_Structers.h"

/*
Documentation of functions in header file
*/

/*
List
{
	int *sum;
	int *count;
	int value;
	struct List *head;
	struct List *last;
	struct List *next;
	struct List *previous;
}
*/
/**************************
LIST RELATED STUFF
***************************/

List * ctor()
{
	List *nodes = malloc(sizeof(List *));
	nodes->count = NULL;
	nodes->sum = NULL;
	nodes->previous = NULL;
	nodes->next = NULL;
	nodes->head = nodes;
	nodes->last = nodes;
	return nodes;
}


List * ctorv(int data)
{
	List *nodes = malloc(sizeof(List));
	nodes->count = malloc(sizeof(int));
	nodes->sum = malloc(sizeof(int));
	*(nodes->count) = 1;
	*(nodes->sum) = data;
	nodes->value = data;
	nodes->next = NULL;
	nodes->previous = NULL;
	nodes->head = nodes;
	nodes->last = nodes;

	return nodes;
}


List * head(List *node)
{
	if (node != NULL)
	{
		return node->head;
	}
	return NULL;
}

List * last(List *node)
{
	if (node != NULL)
	{
		return node->last;
	}
	return NULL;
}

List * get_next(List *node)
{
	if (node != NULL)
	{
		return node->next;
	}
	return NULL;
}

List * get_prev(List *node)
{
	if (node != NULL)
	{
		return node->previous;
	}
	return NULL;
	
}

List * addItem(List *node, int data)
{
	List *temp = node->last;
	List *temp1 = temp;
	if (node->count == NULL && node->sum == NULL) //node was not initialized (created with ctor)
	{
		node->count = malloc(sizeof(int));
		node->sum = malloc(sizeof(int));
	}
	temp->next = malloc(sizeof(List));
	temp->last = temp->next;
	temp = temp->next;
	temp->head = temp1->head;
	temp->next = NULL;
	temp->previous = temp1;
	temp->value = data;
	temp->sum = temp1->sum; ////saving the same address for sum on all nodes -> easier to manipulate without loops
	temp->count = temp1->count; //saving the same address for count on all nodes
	*(temp->count) += 1;
	*(temp->sum) += data;
	return temp;
}

List * delItem(List *item)
{
	List *temp;
	if (item->previous != NULL)
	{
		temp = item->previous;
		*(temp->count) -= 1;
		*(temp->sum) -= temp->value;
		temp->next = item->next;
		item->count = NULL;
		item->sum = NULL;
		free(item);
		return temp;
	}
	else if (item->next != NULL)
	{
		temp = item->next;
		temp->previous = item->previous;
		*(temp->count) -= 1;
		*(temp->sum) -= temp->value;
		item->count = NULL;
		item->sum = NULL;
		free(item);
		return temp;
	}
	else //incase only one node in list
	{
		item->count = NULL;
		item->sum = NULL;
		free(item);
	}
	return NULL;
}

int get_len(List *node)
{
	return *(node->count);
}

int get_data(List *node)
{
	return node->value;
}

double get_avg(List *node)
{
	int s = *(node->sum);
	int c = *(node->count);
	return (s / c);
}

void dtor(List *node)
{
	List * temp;
	node = node->head;
	temp = node;
	free(temp->count); //count and sum have the same address on all nodes - no need to free for each node
	free(temp->sum);
	while (node->next != NULL)
	{
		node = node->next;
		free(node->previous);
	}
	free(node);
}



/**************************
END OF LIST RELATED STUFF
***************************/