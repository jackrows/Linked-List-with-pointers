/*	Author: 	Polychronopoulos
* 	OS: 		Windows
*	Compiler:	Visual Studio
*	Description:Implement linked list with pointer*/

#include "Node.h"
#include "LinkedList.h"
#include "GeneralFunctions.h"


int main(int argc, char *argv[]) 
{
	(void)argc;
	(void)argv;
	int 			option = -1;		/*general varuable to store user action*/
	int				err = -1;			/*error keeping*/ 
	int				scnf_ret = -1;		/*store the return value of scanf*/
	p_LinkedList 	experiment = NULL;	/*Our Linked List*/
	p_Node			result = NULL;		/*To store user's data'*/	
	
	DisplayOptionMenu();
	while( (scnf_ret = scanf(" %d", &option)) == 1)
	{
		if(option == 0)
		{
			printf("\n$Hope see you soon at the lab!!\n");
			return 0;
		}
		else if(option == 1)
		{
			experiment = ListCreation();
			result = NodeCreation();
			break;
		}
		else
		{
			printf("\n#Please give a valid option.\n");
			printf("#To start please press 1\n");
			printf("#If you want to leave the lab press 0\n");
			continue;
		}
	}
	if(scnf_ret == 0)	/*Handle if the user keyboard character instead integer for input*/
	{
		printf("\n\t#You have input a non accesible character.\n");
		printf("\t#Please next time keyboard the apropriate input.\n");
		printf("\t#You are exiting the lab.\n");
		return 0;
	}
	DisplayLabActions();
	while( (scnf_ret = scanf(" %d",&option)) == 1)
	{
		Flushing();
		switch (option) {
			case 1:
				printf("\n#Initializing...\n");
				NodeInitialize(result);
				DisplayLabActions();
				continue;
			case 2:
				NodeDirectInsertData(result);
				DisplayLabActions();
				continue;
			case 3:
				err = ListInsertion(experiment, result);
				if(err == 1)
				{
					printf("\n#Insert complete...\n");
					DisplayLabActions();
					continue;
				}
				else
				{
					printf("\n#Please before store the results, perform right actions.\n");
					DisplayLabActions();
					continue;
				}
			case 4:
				ListPrinting(*experiment);
				DisplayLabActions();
				continue;
			case 5:
				ListDestroy(experiment);
				printf("\n#Exiting...\n");
				break;
			case 6:
				if(ListEmptyCheck(*experiment) == 0)
				{	
					printf("\n#The list with the results is empty.\n");
					DisplayLabActions();
					continue;
				}
				printf("\n#Please give the description of experiment that wish to delete\n");
				char* del_node = (char*)malloc(sizeof(char) * STRING_SIZE);
				fgets(del_node, STRING_SIZE, stdin);
				int ret = ListRemoveNode(experiment, del_node);
				if(ret == 0)
					printf("\n#Nothing removed from the results. Not found the description.\n");
				else if(ret == 1)
				{
					char *pos;
					if ((pos=strchr(del_node, '\n')) != NULL)	/*change the new line character from fgets, because printf print new line*/
    				*pos = '\0';
					printf("\n#Remove the result <%s>\n", del_node);
				}
				DisplayLabActions();
				free(del_node);		/*Free the memory of the string del_node*/	
				continue;
			case 7:;
				int concl = ValuesConclusion(*experiment);
				if(concl == 0)
					printf("\n#The list with the results is empty.\n");
				DisplayLabActions();
				continue;
			case 9:
				ProgramHelp();
				DisplayLabActions();
				continue;
			default:
				printf("\n#Please perform one of the available actions.\n");
				DisplayLabActions();
				continue;
		}
		if(option == 5)
			break;
		Flushing();
	}
	
	if(scnf_ret == 0)	/*Handle if the user input non integer as action*/
	{
		printf("\n\t#You have input a non accesible character.\n");
		printf("\t#Please next time keyboard the apropriate input.\n");
		printf("\t#You are exiting the lab.\n");
		ListDestroy(experiment);
		NodeDeleteData(result);	/*Free the memory of str*/
		free(result);			/*Free the memory for this variable in main*/
		return 0;
	}
	if(err != 1)
		printf("\n#Exiting of the lab without perform any experiment!\n");
	else
		printf("\n#The today experiment end successfully. Thank you.\n");
	
	NodeDeleteData(result);	/*Free the memory of str*/
	free(result);			/*Free the memory for this variable in main*/

	return 0;
}
