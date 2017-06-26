#include "strlib6.h"

char *remove_chars(char *s1, char *s2){
  char *s;
  int s1len = 0;
  int s2len = 0;
  int f = 0;
  while (*s1 != '\0'){
    s1++;
    s1len++;
  }
  s1 = s1 - s1len;
  while (*s2 != '\0'){
    s2++;
    s2len++;
  }
  s2 = s2-s2len;
  if((s = (char*)malloc(s1len+1)) == NULL){
    return NULL;
  }
  char *p = s;
  while (*s1 != '\0'){
    while(*s2 != '\0'){
      if (*s1 == *s2){
        f = 1;
      }
      s2++;
    }
    s2 = s2-s2len;
    if (f == 1){
      f = 0;
      s1++;
    }
    else{
      *s = *s1;
      s1++;
      s++;
    }
  }
  *s = '\0';
  return p;
}
