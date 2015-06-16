#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cleaner.h"
#include "classifier.h"
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
  FILE * file;
  char * line = NULL;
  ssize_t read;
  size_t len = 0;

  file = fopen(argv[1], "r");

  if (file == NULL){
    printf("File not found.\n");
    exit(EXIT_FAILURE);
  }

  words * wds = new_word();
  words * dic = new_word();
  while ((read = getline(&line, &len, file)) != -1) {
    //printf("Retrieved line of length %zu :\n", read);
    //printf("%s", clean(line));
    load_text(wds, clean(line));
  }

  fclose(file);
  file = fopen(argv[2], "r");

  if (file == NULL){
    //printf("File not found.\n");
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &len, file)) != -1) {
    //printf("Retrieved line of length %zu :\n", read);
    //printf("%s", clean(line));
    load_dict(dic, clean(line));
  }

  classify(wds, dic);

  stats * sts = new_stats();
  make_stats(sts, wds);

  fclose(file);
  if (line)
    free(line);
  exit(EXIT_SUCCESS);
}

