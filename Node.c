/*
 * =====================================================================================
 *
 *       Filename:  Node.c
 *
 *    Description:  Implements the tasks of a single trie data structure.
 *
 *        Version:  1.0
 *        Created:  02/16/2015 02:57:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mochamad A. Prananda (), 
 *    Information:  CSE 374 Winter 2015 HW5
 *
 * =====================================================================================
 */
#include "Node.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  newNode
 *  Description:  Creates a new node with empty string and null children
 *		  Param:  Empty
 * =====================================================================================
 */
Node* newNode ( )
{
	Node* brandNode = (Node*)malloc(sizeof(Node));
	brandNode->child = (Node**)malloc(sizeof(Node*)*10);
	brandNode->word = "";
	int i = 0;
	for(; i < NODE_NUM; i++)
	{
		(brandNode->child)[i] = NULL;
	}	  
	return brandNode;
}		
/* -----  end of function newNode  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  printT
 *  Description:  Prints each node recursively if the node has children
 *		  Param:  (i) a Node pointer that points to current node, (ii) current level of the node
 * =====================================================================================
 */
void printT (Node* tempNode, int level )
{
	if (tempNode == NULL)
	{
		printf(" -> null\n");
		return;
	} 
	printf("\nWord: %s\n", tempNode->word);
	// Traverses each child of node, and recurse if the children are not null.
	int i=0;
	for (; i < 10; i++)
	{
		printf("\ti: %d level: %d", i, level);
		printT((tempNode->child)[i], level + 1);
		printf("\n");
	}
}
/* -----  end of function printT  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  freeT
 *  Description:  Frees the allocated memory used by a node (children, parent, and string)
 *		  Param:  (i) a Node pointer that points to currnet node
 * =====================================================================================
 */

void freeT (Node* tempNode )
{
	if (tempNode == NULL)
	{
		return;
	}
	int i = 0;
	for (; i < NODE_NUM; i++)
	{
		freeT((tempNode->child)[i]);
	}
	// Knows that if it's empty string, there is no memory allocation conventionally.
	if (strcmp(tempNode->word, "") != 0)
	{
		free(tempNode->word);
	}
	free(tempNode->child);
	free(tempNode);
}		
/* -----  end of function freeT  ----- */

