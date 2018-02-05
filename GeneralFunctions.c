/*****************************************
*	General functions
*******************************************/
#include "GeneralFunctions.h"

/*The welcome and pre available actions*/
void DisplayOptionMenu()
{
	printf("#Welcome to the lab.\n");
	printf("#Lets start the today experiments.\n");
	printf("#To start please press 1\n");
	printf("#If you want to leave the lab press 0\n");
}

void DisplayLabActions()
{
	printf("\n#Available actions:\n");
	printf("\t1 -Initialize the values before the experiment\n");	/*Run NodeCreation*/
	printf("\t2 -Perform an experiment\n");							/*Run NodeDirectlyInsertData*/
	printf("\t3 -Store the results\n");								/*Run ListInsertion*/
	printf("\t4 -Display the previous experiments\n");				/*Run ListPrinting*/
	printf("\t5 -Exiting the lab\n");								/*Run LIstDestroy*/
	printf("\t6 -Remove an experiment with specific description\n");/*Run ListRemoveNode*/
	printf("\t7 -Take a conclusion of the experiments\n");			/*Run ValuesConclusion*/
	printf("\t9 -Explaining the usage of the lab\n");				/*Run ProgramHelp*/
}

/*Flush the buffer of input stream*/
void Flushing()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

/*Display a proper message to the user, explaining how to use the program*/
void ProgramHelp()
{
	char *str = "\n\tThis is a lab simulation that doing experiments using integer as values.\n The data description(string) and the values(array) corresponds to one experiment each time.\n";
	printf("%s", str);
	//printf("\n\tThis is a simulation of a lab that make experiments using integer values.\n");
	//printf(" Any block of values represent a different experiment which determined by the description.\n");
	printf(" The actions that user can perform display every time where user have to give the input.\n");
	printf(" Correct input is the range 0-9, where the user can implement basics action in the lab.\n");

	GraphicalDiagram();
}

/*Graphical simulation of the linked list and a short explanation of the members*/
void GraphicalDiagram()
{
	int i, j;
	printf("\n\t\t\tLAB LIST\n\n");
	for(j = 0; j < 3; j++)
		printf("experiment\t");
	printf("\n");
	for(j = 0; j < 3; j++)
	{
		
		printf("---------\t");
	}
	printf("\n");
		
	for(i = 0; i < 5; i++)
	{
		if(i == 1)
		{
			for(j = 0; j < 3; j++)
				printf("|descrip|\t");
			printf("\n");
		}
		else if(i == 2)
		{
			for(j = 0; j < 3; j++)
				printf("|\t|----->\t");
			printf(" ...  -----> NULL\n");
		}
		else if(i == 3)
		{
			for(j = 0; j < 3; j++)
				printf("|values |\t");
			printf("\n");
		}
		else
		{
			for(j = 0; j < 3; j++)
			{
				printf("|\t|\t");
			}
			printf("\n");
		}
	}
	
	for(j = 0; j < 3; j++)
		printf("---------\t");
	printf("\n");
	
	printf("the values: ");
	for(i = 0; i < 6; i++)
		printf("|xx|");
	printf(" represent an experiment with these specific values\n");
	printf("\n");
}
