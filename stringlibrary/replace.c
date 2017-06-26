#include "strlib6.h"

char *replace(char *s, char *pat, char *rep){
  char *c;
  char *r = s;
  char *pt = pat;
  int plen = 0;
  int rlen = 0;
  int slen = 0;
  int p = 0;
  int j = 0;
  int e = 0;
  int i = 0;
  while(*r != '\0'){
    if(*r == *pt){
      e = 1;
      i = 0;
      while((*pt!='\0') && (e==1)){
	if(*r == *pt){
	  r++;
	  pt++;
	  i++;
	}        
	else{
	  e=0;
	}
      }
      pt = pt-i;
      if(e == 1){
	p++;
      }
    }
    else{
      r++;
    }
  }
  while(*pat != '\0'){
    plen++;
    pat++;
  }
  pat = pat-plen;
  while(*rep != '\0'){
    rlen++;
    rep++;
  }
  rep = rep-rlen;
  while (*s != '\0'){
    s++;
    slen++;
  }
  s = s-slen;
  if((c=(char*)malloc(slen+1+(p*rlen))) == NULL){
    return NULL;
  }
  char *q = c;
  while(*s != '\0'){
    if(*s == *pat){
      e = 1;
      i = 0;
      while((*pat!='\0') && (e==1)){
        if(*s == *pat){
	  *c = *s;
	  pat++;
	  s++;
	  i++;
	  c++;
	}
	else{
	  *c = *s;
	  e = 0;
	  s++;
	  c++;
	}
      }
      pat = pat-i;
      if(e = 1){
	c = c-i;
	for(j=0; j<rlen; j++){
	  *c = *rep;
	  rep++;
	  c++;
	}
        rep = rep-rlen;
      }
    }
    else{
      *c = *s;
      c++;
      s++;
    }
  }
  return q;
}
