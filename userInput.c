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
 *
 * =====================================================================================
 */
#include "Node.h"
#include "T9DT.h"
#include <sys/types.h>

void inputHandler(Node *);
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Starts the T9 program.
 * 		  Param:  (i) number of input arguments, (ii) string of arguments
 * =====================================================================================
 */

int main(int argc, char **argv)
{
    // See if there is any error with the input
    if (argc != 2)
    {
        fprintf(stderr, "Please enter just one file.\n");
        return 1;
    }

    // Starts T9 program
    char *fileName = argv[1];
    Node *trie = NULL;
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

void inputHandler(Node *trie)
{
    // To handle with #, use stack memory if possible
    char prevLine[MAX_LEN] = "";
    // Gets each line from user
    char *eachLine = NULL;
    // Maximum length to read.
    size_t len = MAX_LEN;
    // Length of string input.
    ssize_t read = 0;
    // Sees if user inputs Ctrl-d
    int quitStatus = 0;

    do
    {
        printf("Enter \"exit\" to quit, or \"#\" to see next word.\n");
        printf("Enter a T9 sequence: ");
        quitStatus = (read = getline(&eachLine, &len, stdin));
        // getline puts \n at the end of string, replacing this with null terminator.
        if (eachLine[read - 1] == '\n')
        {
            eachLine[read - 1] = '\0';
            read--;
        }
        // To traverse more synonyms
        if (strcmp(eachLine, "#") == 0)
        {
            strcat(prevLine, eachLine);
        }
        else
        {
            strncpy(prevLine, eachLine, MAX_LEN);
        }
        // Not traversing tree if about to exit
        if (quitStatus != -1 && strcmp(eachLine, "exit") != 0)
        {
            traverseTrie(trie, prevLine);
        }

    } while (quitStatus != -1 && strcmp(eachLine, "exit") != 0);
    free(eachLine);
}
/* -----  end of function inputHandler  ----- */
