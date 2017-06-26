#include "strlib6.h"

void rstrip(char *s){
  int len = 0;
  int space = 0;
  while (*s != '\0'){
    s++;
    len++;
  }
  s = s--;
  while(isspace(*s)){
    s--;
  }
  s++;
  *s = '\0';
}
