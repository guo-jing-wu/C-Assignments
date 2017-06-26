#include "strlib6.h"

void lstrip(char *s){
  int len = 0;
  int space = 0;
  while (isspace(*s)){
    space++;
    s++;
  }
  s = s-space;
  while (*s != '\0'){
    s++;
    len++;
  }
  s = s-len;
  while (*(s+space) != '\0'){
    *s = *(s+space);
    s++;
  }
  *s = '\0';
}
