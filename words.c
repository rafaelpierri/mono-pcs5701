#include "words.h"
#include <string.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

words * new_word(){
  return (struct words*)malloc(sizeof(struct words));
}

words * last(words * wds){
  words * w = wds;
  while(w->next){
    w = w->next;
  }
  return w;
}

words * first(words * wds){
  words * w;
  while(w->prev){
    w = w->prev;
  }
  return w;
}

words * loadWords(char * path, int q){
  FILE * file;
  char * line = NULL;
  ssize_t read;
  size_t len = 0;
  file = fopen(path, "r");
  //const char * wordsa[97];
  words * w = new_word();
  words * r = w;
 int i = 0;
  while ((read = getline(&line, &len, file)) != -1) {
    char * word = clean(line);
    char * sub = (char*)malloc(sizeof(char)*(strlen(word)));
    memcpy(sub, word, strlen(word));
    w->word=sub;
    if(!(i<q)){
      w->next=new_word();
      w->next->prev=w;
      w=w->next;
    }
    i++;
  }
  fclose(file);
  return r;
}


