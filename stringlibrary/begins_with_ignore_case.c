#include "strlib6.h"

int begins_with_ignore_case(char *s, char *pre){
  int i;
  for (i = 0; pre[i] != '\0'; i++){
    if (toupper(pre[i])!= toupper(s[i])){
      return 0;
    }
  }
  return 1;
}
