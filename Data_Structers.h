#ifndef DATA_STRUCTERS
#define DATA_STRUCTERS
#include <stdio.h>
#include <stdlib.h>

/**************************
LIST RELATED STUFF
***************************/

//List is two-way linked
typedef struct List
{
	int value;
	int *count;
	int *sum;
	struct List *head;
	struct List *last;
	struct List *next;
	struct List *previous;
} List;


/*
wanted to test an option to save head and last as globals though this restricts me to one list at a time
other way was to give an id to each list and have a dynamically allocated array saving pointers in cells matching that id...
Decided to just add more fields to struct

List * lhead
List * llast;
*/
//Create a new list and return a pointer, default constructor does not create new node
List * ctor();

//Create a new List with a give value and same as above
List * ctorv(int data); //ctor with value

//Get a pointer to the head of the list
List * head(List *node);

//Get a pointer to the end of the list
List * last(List *node);

//Get a pointer to the next node given the current node
List * get_next(List *node);

//Get a pointer to the previous node given the current node
List * get_prev(List *node);

//Add an item to the list and return a pointer to said item
List * addItem(List *node, int data);

//Get a pointer to a node and delete it from the list
//Perhaps return a previous or next node instead of just deleting to keep track of the list in case of deleting current node
List * delItem(List *item);

//Get the value inside a node (the int data)
int get_data(List *node);

//Get a node in a list and return the number of nodes in it
int get_len(List *node);

//Get average of values inside a list
double get_avg(List *node);

//Delete List and free memory
void dtor(List *node);







/**************************
END OF LIST RELATED STUFF
***************************/



#endif