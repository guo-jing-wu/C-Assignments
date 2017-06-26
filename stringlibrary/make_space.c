#include "strlib6.h"

char *make_space(int width){
  char *space;
  int i = 0;
  if((space = (char*)malloc(width+1)) == NULL){
    return NULL;
  }
  while (i < width){
    space[i] = ' ';
    i++;
  }
  space[i] = '\0';
  return space;
}
