/*
 * =====================================================================================
 *
 *       Filename:  T9DT.h
 *
 *    Description:  Header files that contain hold what a trie can do, and the
 *    			    alphabet-sequence translator array.
 *
 *        Version:  1.0
 *        Created:  02/21/2015 15:14:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mochamad Pranand (),
 *
 * =====================================================================================
 */
#ifndef T9DT_H_
#define T9DT_H_
// Maximum length an input buffer can handle.
#define MAX_LEN 256
// definition of the alphabet-sequence array.
extern const int CHAR_ARRAY[26];

// Prototypes
Node *addWord(Node *, char *);
void traverseTrie(Node *, char *);
Node *buildTrie(char *);
#endif
