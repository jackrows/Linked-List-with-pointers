/*********************************************************
	Header of Data Structure Linked List with pointers
**********************************************************/
#ifndef __Linked_List_H__
#define __Linked_List_H__

#include "Node.h"


/*Definition of the struct of Linked list*/
typedef struct LinkedList
{
	p_Node			current;		/*a pointer to the current data*/
	struct LinkedList * next;		/*a pointer to the next node with data or null*/
}LinkedList;

typedef LinkedList* p_LinkedList;

/*Declaration of the functions of Linked List*/
p_LinkedList	ListCreation();							/*Create the list located the memory*/
void		 	ListDestroy(p_LinkedList);				/*Destroy the list, free the located memory*/
int				ListInsertion(p_LinkedList, p_Node);	/*Insert in the next node of the list*/
void			ListPrinting(LinkedList);				/*Print the data of the existed nodes of the list*/
int				ListEmptyCheck(LinkedList);				/*Check if the list contains any node with data*/
int				ListDuplicateNode(LinkedList, Node);	/*Access whole list and check every node if has exactly the same values with new node*/
int				ListRemoveNode(p_LinkedList, char*);	/*Remove from the list the node with specific description*/
int  			ValuesConclusion(LinkedList);			/*Implement some actions like, sum, average*/
void			ListRemoveFirstNode(p_LinkedList);		/*Remove from the list the first item*/

#endif
