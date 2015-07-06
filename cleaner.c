#include "cleaner.h"
#include <stdbool.h>

//Check whether the given character is present in the list below.
int acceptable(char * chr){
  char * pallete = "abcdefghijklmnopqrstuvxwyzABCDEFGHIJKLMNOPQRSTUVXWYZ -";
  int i = 0;
  while(i<strlen(pallete)){
    if(chr==pallete[i])
      return 1;
    i++;
  }
  return 0;
}

//Removes all characters not allowed.
char * clean(char * str){
  int i = 0;
  while(i < strlen(str)){
    if(!acceptable(str[i])||(str[i]==' '&&(str[i+1]==' '||str[i+1]=='\n'))){
      memmove(&str[i], &str[i + 1], strlen(str) - i);
      i--;
    }else{
    i++;
    }
  }
  return str;
}
