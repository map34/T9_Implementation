/*   
 * =====================================================================================
 *
 *       Filename:  userInput.c
 *
 *    Description:  Handles what user inputs and uses the trie to implement the T9 program.
 *
 *        Version:  1.0
 *        Created:  02/21/2015 23:24:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mochamad Prananda (), 
 *   Organization:  CSE 374 Winter 2015 HW 5
 *
 * =====================================================================================
 */
#include "Node.h"
#include "T9DT.h"

void inputHandler(Node*);
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Starts the T9 program.
 * 		  Param:  (i) number of input arguments, (ii) string of arguments  
 * =====================================================================================
 */

int main ( int argc, char **argv )
{
	// See if there is any error with the input
	if (argc != 2)
	{
		fprintf(stderr, "Please enter just one file.\n");
		return 1;
	}

	// Starts T9 program
	char* fileName = argv[1];
	Node* trie = NULL;
	trie = buildTrie(fileName);
	inputHandler(trie);
	freeT(trie);

	return 0;
}		
/* -----  end of function main  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  inputHandler
 *  Description:  Gets the trie, and handles user interface.
 *        Param:  (i) a Node pointer to current tree.
 * =====================================================================================
 */

void inputHandler ( Node* trie )
{
	// To handle with #
	char prevLine[MAX_LEN] = "";
	// Gets each line from user
	char eachLine[MAX_LEN] = "";
	// Sees if user inputs Ctrl-d
	int quitStatus = 0;

	do
	{
		printf("Enter \"exit\" to quit, or \"#\" to see next word.\n");
		printf("Enter a T9 sequence: ");
		quitStatus = scanf("%s", eachLine);
		if (strcmp(eachLine, "#") == 0)
		{
			strcat(prevLine, eachLine);
		}
		else
		{
			strncpy(prevLine, eachLine, MAX_LEN);
		}
		if (quitStatus >= 0 && strcmp(eachLine, "exit") != 0)
		{
			traverseTrie(trie, prevLine);
		}

	} while(quitStatus >=0 && strcmp(eachLine, "exit") != 0);
}		
/* -----  end of function inputHandler  ----- */
