#include "strlib6.h"

int find_idx(char *s, char c){
  int index = 0;
  while (*s != '/0'){
    if (*s == c){
      return index;
    }
    else {
      index++;
      s++;
    }
  }
  return -1;
}
