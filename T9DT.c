/*
 * =====================================================================================
 *
 *       Filename:  T9DT.c
 *
 *    Description:  Implements the T9 trie data structure object (contains the data structure and tasks)
 *
 *        Version:  1.0
 *        Created:  02/20/2015 18:27:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mochamad Prananda (), 
 *    Information:	CSE 374 Winter 2015 HW 5  
 *
 * =====================================================================================
 */
#include<ctype.h>
#include "Node.h"
#include "T9DT.h"
// Arrays of numbers that correspond to each alphabet (example: a b c d => 2 2 2 3), 26 letters
const int CHAR_ARRAY[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

// Private functions prototypes
int* charToImp(char*);
Node* addWordToTree(Node*, char*, int*, int);
int isValidString(char*);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addWord
 *  Description:  Adds word to the current trie with the T9 sequence traversal
 *  	  Param:  (i) a Node pointer that points to current trie, (ii) string to put in trie
 * =====================================================================================
 */
Node* addWord (Node* tree, char* word )
{
	// contains the sequence of numbers
	int *translateInt = NULL;
	// how many sequence of numbers to traverse
	int counter=0;
	// To eliminate hassle when adding word, newlines are eliminated
	if(word[strlen(word)-1] == '\n')
	{
		word[strlen(word)-1] = '\0';
	}	
	if(isValidString(word))
	{ 
		translateInt = charToImp(word);	
		counter = strlen(word);
		tree = addWordToTree(tree, word, translateInt, counter);
		free(translateInt);	
	}
	return tree;	
}	
/* -----  end of function addWord  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  buildTrie
 *  Description:  Builds a trie from the given file input, puts each line to appropriate places in trie
 *  	  Param:  (i) filename to read
 * =====================================================================================
 */

Node* buildTrie (char* fileName)
{
	// string to save each line
	char word[MAX_LEN] = "";
	// trie to build
	Node* trie = NULL;
	// Reading the file
	FILE *fr = NULL;
	fr = fopen(fileName, "rt");
	if (fr != NULL)
	{
		while(fgets(word, MAX_LEN, fr) != NULL)
		{
			trie = addWord(trie, word);
		}
		printf("%s is successfully loaded. :) \n", fileName);
	}
	else
	{
		fprintf(stderr, "%s failed to load! :(\n", fileName);
		exit(1);
	}
	fclose(fr);
	return trie;
}
/* -----  end of function buildTrie  ----- */

/*  
 * ===  FUNCTION  ======================================================================
 *
 *         Name:  traverseTrie
 *  Description:  With the given sequence of numbers, 
 *  			  finds the word with the corresponding sequence in tree
 *        Param:  (i) a Node pointer to current tree, (i) sequence of numbers in string form
 * 
 * =====================================================================================
 */ 
void traverseTrie ( Node* tree, char* input )
{
	// the index of the children of node.
	int traverser = 0;
	while (tree != NULL && input[0] != '\0')
	{
		// if #, looks at child num 0
		if (input[0] == '#')
		{
			traverser = 0;
		}
		// if other, looks at child num input[i]
		else
		{
			traverser = (int) (input[0] - '0');
		}
		if (traverser < 0 || traverser > 9 || traverser == 1)
		{
			printf("Only integers (no 1) or #.\n");
			return;
		}
		else
		{
			tree=(tree->child)[traverser];
			input++;
		}

	}
	// Found word!
	if (tree != NULL && strcmp(tree->word, "") != 0)
	{
		printf("%s\n", tree->word);
	}
	else
	{
		printf("No word found.\n");
	}

}		/* -----  end of function traverseTrie  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addWordToTree
 *  Description:  Helper function to add word to the trie.
 *        Param:  (i) a Node pointer to current trie, (ii) word to put, (iii) sequence of numbers,
 *        		  (iv) size of sequence of the numbers
 * =====================================================================================
 */

Node* addWordToTree ( Node* node, char* word, int* translateInt, int codeCounter )
{
	// if there is no node at first, create node
	if (node == NULL)
	{
		node = newNode();
	}

	// if it's time to create word, at the correct node place
	if (codeCounter == 0)
	{
		if (strlen(node->word) <= 0)
		{
			node->word = (char*) malloc(sizeof(char)*(strlen(word))+1);
			strncpy(node->word, word, strlen(word)+1);
			return node;
		}	 
		// if it's time to add word, but there is already a word
		else
		{
			Node* more = (node->child)[0];
			(node->child)[0]=addWordToTree(more, word, translateInt, codeCounter);
			return node;
		}
	}
	else
	{	//if there are still nodes to traverse.
		int indexOfNode = translateInt[0];
		Node* more = (node->child)[indexOfNode];
		(node->child)[indexOfNode] = addWordToTree(more, word, translateInt + 1, codeCounter - 1);
		return node;
	}
}		/* -----  end of function addWordToTree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  charToImp
 *  Description:  Converts word to its corresponding T9 sequence
 *        Param:  
 * =====================================================================================
 */

int* charToImp ( char* word  )
{

	// saves the length of string
	int strLen = strlen(word);
	// to save the sequence of numbers
	int* translateInt = (int*)malloc(sizeof(int) * strLen);
	int i;
	for (i = 0; i < strLen ; i++)
	{
		if (word[i] == '#')
		{
			translateInt[i] = 0;
		} 
		else
		{ 
			translateInt[i] = CHAR_ARRAY[(int) word[i] - 'a'];
		}
	}
	return translateInt;
}
/* -----  end of function charToImp  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isValidString
 *  Description:  Checks if string is alphanumeric and is not empty.
 *     	  Param:  (i) string to check
 * =====================================================================================
 */

int isValidString (char* tempString )
{
	if (strlen(tempString) > 0)
	{
		int len=strlen(tempString);
		int i=0;
		int validFlag = 1;
		for (; i < len; i++)
		{
			if (!isalpha(tempString[i]))
			{
				validFlag=0;
			}
		}
		return validFlag;
	}
	else
	{
		return 0;
	}
}		
/* -----  end of function isValidString  ----- */