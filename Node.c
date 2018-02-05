/**********************************************
	Implement the functions of the Node struct
***********************************************/

#include "Node.h"

/*Allocate memory for the data node*/
Node*	NodeCreation()
{
	p_Node	pStart = (p_Node)malloc(sizeof(Node));
	pStart->str = (char*)malloc(sizeof(char) * STRING_SIZE);

	strcpy(pStart->str, "");	/*Initialize the string(valgrind)*/
	pStart->situation = 0;
	int	i;
	for(i = 0; i < ARRAY_SIZE; i++)
		pStart->math[i] = 0;
	
	return pStart;
}

/*Check if the node contains values
* Return 1 when the node has data and 0 when is empty and -1 when the node is not located*/
int NodeEmptyCheck(Node curr)
{
	if(curr.situation == 1)
		return 1;	/*not empty*/
	else if (curr.situation == 0)
		return 0;	/*empty*/
	else
		return -1;	/*not located*/
}

/*Insert the data that contains the src(source) into dest(destination)
* Return 1 in success and 0 when destination is null or source is empty*/
int NodeInsertData(p_Node dest, Node src)
{
	if(dest == NULL)	/*Check the destination if is not located*/
		return 0;
	if(NodeEmptyCheck(src) == 0)	/*Check the source if contains data*/
		return 0;
	else if(NodeEmptyCheck(src) == -1)	/*Check if the source is located*/
		return 0;
		
	p_Node temp = &src;
	dest->situation = temp->situation;
	strcpy(dest->str, temp->str);
	int i;
	for(i = 0; i < ARRAY_SIZE; i++)
		dest->math[i] = temp->math[i];
		
	return 1;		/*Completed assignment*/
}

/*Printing the values of the node*/
void NodePrintData(Node display)
{
	if(NodeEmptyCheck(display) == 0)	/*Check the content of the node*/
	{
		printf("\n$The node doesn't contain any data\n");
		return;
	}
	printf("$The element's value of the node:\n");
	printf("$description: %s",display.str);
	printf("$data values: |");
	int i;
	for(i = 0; i < ARRAY_SIZE; i++)
		printf("%d|",display.math[i]);
	printf("\n");
	return;
}

/*Directly insert values in to the node from the stdin
* This insertion override any values the node possible contains*/
void NodeDirectInsertData(p_Node pDest)
{
	if(pDest == NULL || (strcmp(pDest->str, "") == 0))	/*check for not created pointer or just located with malloc*/
	{
		printf("\n#Please first perform an initialization.\n");
		return;
	}
	if(strcmp(pDest->str, " ") != 0)	/*Check if initialization has been performed*/
	{
		printf("\n#Please first perform an initialization.\n");
		return;
	}
	int i;
	char *p_instr = NULL;
	
	p_instr = (char*)malloc(sizeof(char) * STRING_SIZE);
	
	printf("\n******************************************************\n");
	printf("Keyboard first the description(100max): ");
	fgets(p_instr, STRING_SIZE, stdin);
	
	strcpy(pDest->str, p_instr);
	
	printf("Keyboard the values[%d]: ", ARRAY_SIZE);
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		if(scanf("%d*d", &pDest->math[i]) == 0)		/*Handle non integer inputs*/
		{
			printf("\n\t#Please input only integer as values.\n");
			i--;		/*Reduce the index to write again the same element of array*/
			Flushing();	/*Clean the stdin buffer of scanf*/
		}
	}
		
	pDest->situation = 1;			/*Contains values*/
	printf("********************************************************\n");
	free(p_instr);	/*Free the p_instr */
	return;
}

/*Zeroing the values and free the commited memory*/
void NodeDeleteData(p_Node pDel)
{
	if(pDel == NULL)	/*Check the data node if is localted*/
	{
		printf("\n$The experiment hasn't initialized.\n");
		return;
	}
	if(NodeEmptyCheck(*pDel) == 0)	/*Check if data node contains values*/
	{
		free(pDel->str);
		return;
	}
	int i;
	for(i = 0; i < ARRAY_SIZE; i++)
		pDel->math[i] = 0;
	free(pDel->str);
	pDel->situation = 0;
	return;
}	

/*Initialize the values of the node to zero*/
void NodeInitialize(p_Node result)
{
	strcpy(result->str, " ");	/*Initialize with one space*/
	int i;
	for(i = 0; i < ARRAY_SIZE; i++)
		result->math[i] = 0;
	
	result->situation = 0;		/*Not contain data*/
	return;
}
