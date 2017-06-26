#include "strlib6.h"

void strip(char *s){
  int llen = 0;
  int rlen = 0;
  int space = 0;
  while (isspace(*s)){
    space++;
    s++;
  }
  s = s-space;
  while (*s != '\0'){
    s++;
    llen++;
  }
  s = s-llen;
  while (*(s+space) != '\0'){
    *s = *(s+space);
    s++;
  }
  *s = '\0';
  while (*s != '\0'){
    s++;
    rlen++;
  }
  s = s--;
  while(isspace(*s)){
    s--;
  }
  s++;
  *s = '\0';
}
