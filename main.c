#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cleaner.h"
#include "automaton.h"
#include "words.h"
int main(int argc, char **argv)
{

  if(argc==1){
    printf("Please provide a path to the text file\n");
    exit(EXIT_FAILURE);
  }
  if(argc==2){
    printf("Please provide a path to the dictionary file\n");
    exit(EXIT_FAILURE);
  }
  if(argc==3){
    printf("Please provide the word count for the text provided\n");
    exit(EXIT_FAILURE);
  }

  static int const table_size = 100000;
  row * table = malloc(sizeof(row) * table_size);
  constructTrie(table, argv[1]);

  int q = atoi(argv[3]);
  words * w;
  w = loadWords(argv[2], argv[3]);
  //acceptWords(words);

  while(1){
    printf("%d\n",accept(table,w->word));
    if(w->next->word){
      w=w->next;
    }else{
      break;
    }
  }
  exit(EXIT_SUCCESS);
}
