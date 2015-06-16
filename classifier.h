#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "words.h"
typedef struct stats {
   int words;
   int adjective;
   int noun;
   int verb;

   int verb_adjective_left;
   int verb_noun_left;
   int verb_verb_left;
   int verb_adjective_right;
   int verb_noun_right;
   int verb_verb_right;

   int adjective_adjective_left;
   int adjective_noun_left;
   int adjective_verb_left;
   int adjective_adjective_right;
   int adjective_noun_right;
   int adjective_verb_right;

   int noun_adjective_left;
   int noun_noun_left;
   int noun_verb_left;
   int noun_adjective_right;
   int noun_noun_right;
   int noun_verb_right;

} stats;

words * classify(words * text, words * dict);
stats * make_stats(stats * sts, words * text);
stats * new_stats();
#endif // CLASSIFIER_H

