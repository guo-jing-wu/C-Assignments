#include "strlib6.h"

char **chop(char *s, char c){
  char **cp;
  int i = 0;
  int len = 0;
  while(*s != '\0'){
    s++;
    len++;
  }
  s = s-len;
  while(*s != '\0'){
    if(*s == c){
      i++;
      *s = '\0';
    }
    s++;
  }
  s = s-len;
  if((cp=(char**)malloc((i+2)*sizeof(char*))) == NULL){
    return NULL;
  }
  char **p = cp;
  int j;
  if(*s == '\0'){
    s++;
  }
  cp[0] = s;
  for(j=1; j<i+1; j++){
    while(*s != '\0'){
      s++;
    }
    while(*s == '\0'){
      s++;
    }
    cp[j] = s;
  }            
  cp[j] = '\0';
  return p;
}
