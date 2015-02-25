T9 Implementation with C
========================

Each number from 2-9 on the keypad represent three or four letters, the number 0 represents a space, and 1 represents a set of symbols such as { , . ! ? } etc. We will only use the numbers 2-9, which represent the following letters:

2 ABC
3 DEF
4 GHI
5 JKL
6 MNO
7 PQRS
8 TUV
9 WXYZ

Since multiple letters map to a single number, many key sequences represent multiple words. For example, the input 2665 represents "book" and "cool", among other possibilities.

If the user then enters '#', the program should print the next word in the trie that has the same numeric value, and so forth. The user can also type a number followed by one or more '#' characters - this should print the same word that would be found by typing the number and individual '#' characters on separate input lines.

Note: It is assumed that the user's machine is running on a UNIX-based operating system that has a Command Line Interface (such as Ubuntu and Mac OSX).


Go
-------------------------------
#### Installation
`make all`

#### Execution
`./bin/userInput [dictionary_name].txt`

#### Clean Up
`make clean`

Example of User Input
-------------------------------
```
> ./bin/userInput "dictionary.txt"

dictionary.txt is successfully loaded. :)
Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: 76257

pocks

Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: #

rocks

Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: #

soaks

Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: #

socks

Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: #

There are no more T9 synonyms.

Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: 748484

No word found.

Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: 76257##

soaks

Enter "exit" to quit, or "#" to see next word.

Enter a T9 sequence: exit
```