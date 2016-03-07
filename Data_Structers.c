#include "Data_Structers.h"

/*
Documentation of functions in header file
*/

/*
List;
{
	int sum;
	int count;
	struct Node *head;
	struct Node *last;
} 

Node;
{
	int value;
	struct Node *next;
	struct Node *previous;
	struct List * list;
} 

*/
/**************************
LIST RELATED STUFF
***************************/

Node * ctor()
{
	Node *nodes = malloc(sizeof(Node));
	List *list = malloc(sizeof(List));
	nodes->previous = nodes->next = NULL;
	list->head = list->last = nodes;
	list->sum = 0;
	list->count = 0;
	nodes->lis = list;
	return nodes;
}


Node * ctorv(int data)
{
	Node *nodes = malloc(sizeof(Node));
	List *list = malloc(sizeof(List));
	nodes->previous = nodes->next = NULL;
	list->head = list->last = nodes;
	list->sum = data;
	list->count = 1;
	nodes->lis = list;
	nodes->value = data;
	return nodes;

}

Node * head(Node *item)
{
	if (item != NULL)
	{
		return item->lis->head;
	}
	return NULL;
}

Node * last(Node *item)
{
	if(item != NULL)
	{
		return item->lis->last;
	}
	return NULL;
}

Node * get_next(Node *item)
{
	if (item != NULL)
	{
		return (item->next);
	}
	return NULL;
}

Node * get_prev(Node *item)
{
	if (item != NULL)
	{
		return (item->previous);
	}
	return NULL;
	
}
/*
Get a pointer to a node (part of a list) and add a node to the end of the list
*/
Node * addItem(Node *item, int data)
{
	Node *temp = malloc(sizeof(Node));
	item = item->lis->last; //push the node after the last node in the list
	temp->next = item->next;
	item->next = temp;
	temp->value = data;
	temp->next = NULL;
	temp->previous = item;
	temp->lis = item->lis;
	temp->lis->last = temp;
	temp->lis->count++;
	temp->lis->sum += data;
	return temp;
	

}


Node * delItem(Node *item)
{
	Node *temp = NULL;
	if (item->previous != NULL && item->next == NULL)
	{ //deleting last node
		temp = item->previous;
		temp->lis->last = temp;
		temp->next = NULL;
	}
	else if (item->previous == NULL && item->next != NULL)
	{ //deleting first node
		temp = item->next;
		temp->lis->head = temp;
		temp->previous = NULL;
	}
	else
	{ //deleting from the middle of the list
		temp = item->previous; //derefrencing the item node from previous and next nodes
		temp->next = item->next;
		item->next->previous = temp;
	}
	temp->lis->count--;
	temp->lis->sum -= temp->value;
	free(item);
	return temp;
}

int get_len(Node *item)
{
	return item->lis->count;
}

int get_data(Node *item)
{
	return item->value;
}

double get_avg(Node *item)
{
	int s = item->lis->sum;
	int c = item->lis->count;
	return (s / c);
}


void dtor(Node *item)
{
	List *temp = item->lis;
	item = temp->head;
	while (item != temp->last)
	{
		item = item->next;
		free(item->previous);
	}
	free(item);
	free(temp);
}



/**************************
END OF LIST RELATED STUFF
***************************/
