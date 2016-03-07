#ifndef DATA_STRUCTERS
#define DATA_STRUCTERS
#include <stdio.h>
#include <stdlib.h>

/**************************
LIST RELATED STUFF
***************************/

typedef struct List
{
	int sum;
	int count;
	struct Node *head;
	struct Node *last;
} List;

typedef struct Node
{
	int value;
	struct Node *next;
	struct Node *previous;
	struct List * lis;
} Node;


//Create a new list and return a pointer, default constructor does not create new node
Node * ctor();

//Create a new List with a give value and same as above
Node * ctorv(int data); //ctor with value

//Get a pointer to the head of the list
Node * head(Node *item);

//Get a pointer to the end of the list
Node * last(Node *item);

//Get a pointer to the next node given the current node
Node * get_next(Node *item);

//Get a pointer to the previous node given the current node
Node * get_prev(Node *item);

//Add an item to the list and return a pointer to said item
Node * addItem(Node *item, int data);

//Get a pointer to a node and delete it from the list
//Perhaps return a previous or next node instead of just deleting to keep track of the list in case of deleting current node
Node * delItem(Node *item);

//Get the value inside a node (the int data)
int get_data(Node *item);

//Get a node in a list and return the number of nodes in it
int get_len(Node *item);

//Get average of values inside a list
double get_avg(Node *item);

//Delete List and free memory
void dtor(Node *item);

/**************************
END OF LIST RELATED STUFF
***************************/



#endif