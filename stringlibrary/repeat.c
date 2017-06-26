#include "strlib6.h"

char *repeat(char *s, int x){
  char *r;
  int len =0;
  int i = 0;
  if (s == NULL){
    return NULL;
  }
  while (*s != '\0'){
    s++;
    len++;
  }
  s = s-len;
  if((r = (char*)malloc((len+1)*x)) == NULL){
    return NULL;
  }
  char *p = r;
  for (i=0; i<x; i++){
    while (*s != '\0'){
      *r = *s;
      s++;
      r++;
    }
    s = s-len;
  }
  *r = '\0';
  return p;
}
