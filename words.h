#ifndef WORDS_H
#define WORDS_H

typedef struct words {
   char * word;
   struct words * next;
   struct words * prev;
} words;
words * new_word(void);
words * last(words * wds);
words * first(words * wds);
words * loadWords(char * path, int q);
#endif
