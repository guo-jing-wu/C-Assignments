#include "strlib6.h"

char *ellipsize(char *s, int nw){
  char *e;
  char *r = s;
  int len = 0;
  int c = 0;
  int i = 0;
  int w = 0;
  int k = 0;
  while (*r != '\0'){
    if((isspace(*r)) && (k == 1)){
      k = 0;
      c++;
    }
    if (isspace(*r)){
      k = 0;
    }
    else{
      k = 1;
    }
    r++;
  }
  c++;
  while (*s != '\0'){
    s++;
    len++;
  }
  s = s-len;
  if((e = (char*)malloc(len+1)) == NULL){
    return NULL;
  }
  char *p = e;
  if(c <= nw){
    nw = c;
  }
  while(w < nw){
    if(((isspace(*s)) || (*s == '\0')) && (k == 1)){
      w++;
      if(w == nw){
      }
      else{
	*e = *s;
	e++;
	s++;
      }
      k = 0;
    }
    else if(isspace(*s)){
      *e = *s;
      k = 0;
      e++;
      s++;
    }
    else{
      *e = *s;
      k = 1;
      e++;
      s++;
    }
  }
  if(c <= nw){
    *e = '\0';
    return p;
  }
  for(i=0; i<3; i++){
    *e = '.';
    e++;
  }
  *e = '\0';
  return p;
}
