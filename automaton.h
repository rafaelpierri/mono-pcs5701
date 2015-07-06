#ifndef AUTOMATON_H
#define AUTOMATON_H

#define ALPHABET "abcdefghijklmnopqrstuvxwyzABCDEFGHIJKLMNOPQRSTUVXWYZ -"

//The transition table row contains the state and the next states for a given input.
//There are 54 elements in the alphabet.
typedef struct row {
   int used;
   int final;
   int col[54];
} row;

//Returns alphabet character code. Return -1 if character is unknown.
int characterCode(char * chr);

char characterMap(int code);

void constructTrie(row * table, char * path);

int newState(row * r);

int accept(row * r, char * word);

#endif // AUTOMATON_H
