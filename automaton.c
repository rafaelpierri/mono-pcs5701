#include "automaton.h"
#include "cleaner.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

static int const table_size = 100000;

//Returns alphabet character code. Return -1 if character is unknown.
int characterCode(char * chr){
   char * alphabet = ALPHABET;
   int i;
   for(i = 0; i < strlen(alphabet); i++){
      if(chr[0]==alphabet[i]) return i;
   }
   return -1;
}

char characterMap(int code){
   char * alphabet = ALPHABET;
   return alphabet[code];
}

int newState(row * r){
  int i;
  for(i = 0; i<table_size; i++){
    if(r[i].used==0){
      return i;
    }
  }
}

void constructTrie(row * table, char * path){
  FILE * file;
  char * line = NULL;
  ssize_t read;
  size_t len = 0;
  file = fopen(path, "r");
  //row * table = malloc(sizeof(row) * table_size);
  table[0].used=1;


  while ((read = getline(&line, &len, file)) != -1) {
    char * word = clean(line);
    if(word=="angry"){
        printf("fudeu");
    }
    int state = 0;
    int i;
    int size = strlen(word);
    for(i = 0; i<size; i++){
      int code = characterCode(&word[i]);
      if(table[state].col[code]==0){
        int old = state;
        state = newState(table);
        table[state].used=1;
        table[old].col[code]=state;
      }else{
        state = table[state].col[code];
      }
      if(i==size-1){
        table[state].final=1;
      }
    }

  }

  fclose(file);

}

int accept(row * r, char * word){
  int i;
  int state = 0;
  int size = strlen(word);
  for(i = 0; i<size; i++){
    state = r[state].col[characterCode(&word[i])];
  }
  if(r[state].final){
    return 1;
  }else{
    return 0;
  }
}
