/***************************************************
*	Implement the functions of the Linked List
****************************************************/

#include "LinkedList.h"

/*Create the list and locate memory for the struct linkedlist*/
p_LinkedList ListCreation()
{
	p_LinkedList list = (p_LinkedList)malloc(sizeof(LinkedList));
	
	list->current = NULL;
	list->next = NULL;
	
	return list;
}

/*Check if the list is empty 
* Return 0 if is empty, 1 if contains nodes*/
int ListEmptyCheck(LinkedList list)
{	
	p_LinkedList list_index = list.next;
	
	int count_node = 0;	/*Count the total nodes*/
	
	while(list_index != NULL)
	{
		list_index = list_index->next;
		count_node++;
	}
	if(count_node == 0)	
		return 0;		/*Empty list*/
	else
		return 1;		/*Not empty list*/
}

/*Printing all the nodes of the list*/
void ListPrinting(LinkedList list)
{
	p_LinkedList p_list = &list;
	
	if(ListEmptyCheck(list) == 0)
	{
		printf("\n#The list with the results is empty.\n");
		return;
	}
	
	int i = 1;
	while(p_list->next != NULL)
	{
		if(NodeEmptyCheck(*(p_list->current)) == 0)	/*Extra check for the data of the node*/
		{
			printf("\n%d\n", i++);
			printf("The result is empty!! No data contain!\n");
			p_list = p_list->next;
			continue;
		}
		printf("\n%d.\n", i++);
		NodePrintData(*(p_list->current));
		p_list = p_list->next;
	}
}

/*Assign the values of source node at member current of list 
* First check the situation of the current node and action accordingly
* Check for duplicates values.
* Return 1 in success and other for errors*/
int ListInsertion(p_LinkedList list, p_Node source_node)
{
	int check = -1;
	if(source_node == NULL)
		return check;
	if(NodeEmptyCheck(*source_node) == 0)	/*Check if the source node contains data*/
		return check;

	int duplicate = ListDuplicateNode(*list, *source_node);

	if(duplicate == 1)	/*find another node with same values*/
	{
		int go_on = 0;
		printf("\n#A same experiment has been founded today.\n");
		printf("#Would you like to continue the storing although??\n");
		printf("#1(yes) / 0(no)\n");
		scanf(" %d", &go_on);
		if(go_on == 0)
			return check;
	}
	else	/*No duplicate node*/
	{
		;
	}
	/*Go to the last node of the list*/
	p_LinkedList list_index = list;
	while(list_index->next != NULL)
		list_index = list_index->next;

	list_index->current = NodeCreation();	/*Located the memory for the node of the list*/
	check = NodeInsertData(list_index->current, *source_node);
		
	/*assign the next pointer to null*/
	list_index->next = ListCreation();
	if(check == 0)
		return check;	/*Problem in NodeInsertData*/
	
	return 1;	/*Completed successful*/
}

/*Destroy the list and unlocated the commited memory of the nodes*/
void ListDestroy(p_LinkedList pDel)
{
	p_LinkedList list_destroy = pDel;
	p_Node	node_destroy = NULL;
	
	if(ListEmptyCheck(*list_destroy) == 0)	/*List is empty*/
	{
		free(list_destroy);		/*Free the original list from main, as none node and next list have been created*/
		return;
	}
	
	while(pDel->next != NULL)		/*List with one and more nodes*/
	{
		node_destroy = pDel->current;
		if(NodeEmptyCheck(*node_destroy) != -1)
		{
			NodeDeleteData(node_destroy);	/*This free the memory of str from NodeCreation*/
			free(node_destroy);
		}
		list_destroy = pDel;
		pDel = pDel->next;
		free(list_destroy);
	}
	free(pDel);		/*Free the memory of next list. This free the malloc of ListCreation in ListInsert*/
	return;
}

/*Check every node in the list if the source node already contained
* Return 0 if the new node doesn't exist in the list,  1 if it exists*/
int ListDuplicateNode(LinkedList list, Node new_node)
{
	p_LinkedList p_list = &list;
	Node old_node;
	int i = -1, duplicate = -1;
	
	while(p_list->next != NULL)
	{
		duplicate = -1;
		old_node = *p_list->current;
		for(i = 0; i< ARRAY_SIZE; i++)
		{
			if(old_node.math[i] != new_node.math[i])
			{
				duplicate = 0;
				break;
			}
		}
		if(duplicate == -1)
			break;
		p_list = p_list->next;
	}
	if(i == -1)		/*For the empty list. Essentially check if the inner loop has run and change the variable i*/
		duplicate = 0;
	else if(i != -1 && duplicate == -1)		/*duplicate = -1 means that all values are the same*/
		duplicate = 1;
	return duplicate;
}

/*Remove a specific node consider the description user wish
* Return 1 in success removing, 0 if no removing happen*/
int ListRemoveNode(p_LinkedList list, char* node_desc)
{
	p_LinkedList list_index = list;
	p_LinkedList temp = NULL;		/*keep the list that will be deleted*/
	p_Node current_node = NULL;		/*Keep the node with the willing values to deleted*/
	
	if(ListEmptyCheck(*list) == 0)	/*Check if the list is empty*/
		return 0;
	
	/*For list with one node*/
	if(list_index->next->next == NULL)	
	{
		current_node = list_index->current;
		if(strcmp(current_node->str, node_desc) != 0)	/*Compare the descriptions*/
			return 0;
		NodeDeleteData(current_node);	/*Free the str pointer*/
		free(current_node);			/*Unlocated the node malloc*/
		free(list_index->next);
		list_index->next = NULL;	
		return 1;	/*success*/
	}
	/*For any node*/
	while(list_index->next != NULL)	/*Iterate to node that will be removed*/
	{
		current_node = list_index->current;
		if(strcmp(current_node->str, node_desc) == 0)
		{
			temp = list_index;		/*Store the list that will be removed*/
			break;
		}
		list_index = list_index->next;
	}
	if(temp == NULL)
		return 0;
	list_index = list;
	
	if(list_index == temp)	/*Pop up the first node*/
	{
		ListRemoveFirstNode(list);
		return 1;	/*success*/
	}
	
	while(list_index->next != temp)	/*Iterate to the previous list node of this that will be removed*/
		list_index = list_index->next;
	
	list_index->next = temp->next;	/*Override the pointer to point at the next of the list node that will be deleted*/
	NodeDeleteData(current_node);	/*Free the memory of node->str from NodeCreation*/
	free(current_node);				/*Free the memory of data node*/
	free(temp);						/*Free the list node*/
	return 1;
}

/*Remove the first node from the list
* Create new one copy from the old all nodes except the first
* And copy again the new to original list*/
void ListRemoveFirstNode(p_LinkedList p_list)
{
	p_LinkedList new_list = ListCreation();
	p_LinkedList list_index = p_list->next;		/*Iterate the original list*/
	p_LinkedList new_list_index = new_list;		/*Iterate the new list*/
	
	while(list_index->next != NULL)		/*Access the original list*/
	{
		ListInsertion(new_list_index, list_index->current);	/*Insert to new list the values from the old*/
		new_list_index = new_list_index->next;
		list_index = list_index->next;
	}
	ListDestroy(p_list);		/*Destroy the old*/
	*p_list = *ListCreation();	/*Recreate the old*/
	list_index = p_list;
	new_list_index = new_list;
	while(new_list_index->next != NULL)	/*Access the new list*/
	{
		ListInsertion(list_index, new_list_index->current);		/*Insert to original list the values from the new*/
		list_index = list_index->next;
		new_list_index = new_list_index->next;
	}
	ListDestroy(new_list);
}

/*Calculate the summary and the average of the values of every node
* and of all nodes*/
int ValuesConclusion(LinkedList list)
{
	if(ListEmptyCheck(list) == 0)
		return 0;	/*None conclusion*/
	
	p_LinkedList list_index = &list;
	p_Node node_index = NULL;
	long int sum = 0, list_sum = 0;				/*sum: for every node, list_sum: for all nodes*/
	double average = 0.0, list_average = 0.0;	/*average: for every node, list_average: for all nodes*/
	short int total_nodes = 0;					/*counter for doing average*/
	int i;
	
	printf("\n==============================================================================\n");
	while(list_index->next != NULL)
	{
		sum = 0;
		node_index = list_index->current;
		for(i = 0; i < ARRAY_SIZE; i++)
			sum += node_index->math[i];
		average = (double)sum / ARRAY_SIZE;
		total_nodes++;
		list_sum += sum;
		printf("\n#*****From experiment %s", node_index->str);
		printf("\t$The sum of the values is : %ld\n", sum);
		printf("\t$The average of values is : %.2lf\n",average);
		list_index = list_index->next;
	}
	printf("\n==============================================================================\n");
	printf("\n$From %d experiments the final result are:\n", total_nodes);
	printf("\t$Total sum : %ld\n", list_sum);
	list_average = (double)list_sum / (double)total_nodes;
	printf("\t$Total average : %.2lf\n", list_average);
	printf("\n==============================================================================\n");
	return 1;
}
