#include "classifier.h"
#include <string.h>


words * classify(words * text, words * dict){
  words * t = text;
  words * d = dict;
  while(!t->next==0){
    while(!d->next==0){
      if(strcmp(t->word,d->word) == 0){
        t->type=d->type;
        break;
      }
      d=d->next;
    }
    d=dict;
    t=t->next;
  }
  return text;
}

stats * make_stats(stats * sts, words * text){
  words * w = text;
  sts->words=-3;
  while(!w->next==0){
    if(w->prev!=0&&w->next!=0){
      if(w->prev->type!=0&&w->next->type!=0){
        if(w->type!=0&&w->word!=0){
          sts->words++;
          if(strcmp(w->type,"A")==0){sts->adjective++;}
          if(strcmp(w->type,"N")==0){sts->noun++;}
          if(strcmp(w->type,"V")==0){sts->verb++;}

          if(strcmp(w->type,"V")==0&&strcmp(w->prev->type,"A")==0){sts->verb_adjective_left++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->prev->type,"N")==0){sts->verb_noun_left++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->prev->type,"V")==0){sts->verb_verb_left++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->next->type,"A")==0){sts->verb_adjective_right++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->next->type,"N")==0){sts->verb_noun_right++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->next->type,"V")==0){sts->verb_verb_right++;}

          if(strcmp(w->type,"A")==0&&strcmp(w->prev->type,"A")==0){sts->adjective_adjective_left++;}
          if(strcmp(w->type,"A")==0&&strcmp(w->prev->type,"N")==0){sts->adjective_noun_left++;}
          if(strcmp(w->type,"A")==0&&strcmp(w->prev->type,"V")==0){sts->adjective_verb_left++;}
          if(strcmp(w->type,"A")==0&&strcmp(w->next->type,"A")==0){sts->adjective_adjective_right++;}
          if(strcmp(w->type,"A")==0&&strcmp(w->next->type,"N")==0){sts->adjective_noun_right++;}
          if(strcmp(w->type,"A")==0&&strcmp(w->next->type,"V")==0){sts->adjective_verb_right++;}

          if(strcmp(w->type,"V")==0&&strcmp(w->prev->type,"A")==0){sts->noun_adjective_left++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->prev->type,"N")==0){sts->noun_noun_left++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->prev->type,"V")==0){sts->noun_verb_left++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->next->type,"A")==0){sts->noun_adjective_right++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->next->type,"N")==0){sts->noun_noun_right++;}
          if(strcmp(w->type,"V")==0&&strcmp(w->next->type,"V")==0){sts->noun_verb_right++;}

        }
      }
    }
  w=w->next;
  }
}

stats * new_stats(){
  return (struct stats*)malloc(sizeof(struct stats));
}
