#include "strlib6.h"

char *slice(char *s, int b, int e){
  char *c;
  int len = 0;;
  while (*s != '\0'){
    len++;
    s++;
  }
  s = s-len;
  if (e<b){
    return NULL;
  }
  if((c = (char*)malloc(len+1)) == NULL){
    return NULL;
  }
  char *p = c;
  s = s+b;
  while (b<=e){
    *c = *s;
    c++;
    s++;
    b++;
  }
  *c = '\0';
  return p;
}
