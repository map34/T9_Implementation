/*
 * =====================================================================================
 *
 *       Filename:  Node.h
 *
 *    Description:  Header file for Node.c, contains the definition of a node and the
 *    				prototypes of each function that a node does. 
 *
 *        Version:  1.0
 *        Created:  02/16/2015 02:49:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mochamad Prananda (), 
 *    Information:  CSE 374 Winter 2015 HW5  
 *
 * =====================================================================================
 */


#ifndef NODE_H
#define NODE_H
#define NODE_NUM 10 // Macro for the number of children a node has.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for word and Node
typedef struct eachNode {
	struct eachNode** child;
	char* word;
} Node;

// Prototypes
Node* newNode ( );
void printT (Node*, int );
void freeT (Node* );

#endif
