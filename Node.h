/**********************************
	Header of struct with the data
***********************************/
#ifndef __Node_H__
#define __Node_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GeneralFunctions.h"


#define ARRAY_SIZE	6
#define STRING_SIZE	100 

/*Definition of the struct about the data */
typedef struct Node
{
	char *	str;				/*String that describe the data*/
	int 	math[ARRAY_SIZE];	/*The data*/
	int		situation;			/*Flag - 0:empty but allocated, 1:contain values*/
}Node;

typedef Node* p_Node;

/*Declaration of the functions that opearate the struct*/
p_Node	NodeCreation();					/*Constructor*/
int		NodeEmptyCheck(Node);			/*Check for data in Node, 0 if node is empty - 1 if node contains data*/
int		NodeInsertData(p_Node, Node);	/*Assign at Node the values into members, return 1 in success*/
void	NodePrintData(Node);			/*Printing the content of the node*/
void	NodeDirectInsertData(p_Node);	/*The user can input values in the node overidding the existed*/
void	NodeDeleteData(p_Node);			/*Free the located memory and zero the values*/
void	NodeInitialize(p_Node);			/*Initialize the values of the node*/

#endif
