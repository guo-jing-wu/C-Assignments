#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 1000

char shift(char,int);
char *string(char*,int);
int real(char *,char **);
int count(FILE *,int);

char shift (char c, int k){
  int i = 0;
  if (isalpha(c)){
    while (i < k){
      if (c == 'z'){
	c = 'a';
      }
      else if (c == 'Z'){
	c = 'A';
      }
      else {
	c++;
      }
      i++;
    }
  }
  return c;
}

char *string (char *s, int k){
  char *c = s;
  while (*s != '\0'){
    if(!isalpha(*s)){
      s++;
    }
    else{
      char p = *s;
      *s = shift(p,k);
      s++;
    }
  }
  return c;
}

int real (char *word, char **dict){
  char **d = dict;
  while(*d != NULL){
    if(strcasecmp(word,*d) == 0){
      return 1;
    }
    if(strcasecmp(word,*d) != 0){
	d++;
    }
  }
  return 0;
}

int count(FILE *d, int j){
  char s;
  int state = 0;
  int w = 0;
  int c = 0;
  while ((s=fgetc(d)) != EOF){
    if (isspace(s) && state == 1){
      w++;
      state = 0;
    }
    if (isspace(s)){
      state = 0;
    }
    else{
      state = 1;
    }
    c++;
  }
  if (j == 0){
    return w;
  }
  if (j == 1){
    return c;
  }
}

int main(int argc, char **argv) {
  FILE *cipher;
  FILE *dict;
  char **fword;
  char *file;
  char *word;
  char *shift;
  char *dl = " \n";
  char chr;
  char line[LEN];
  int wcount;
  int ccount;
  int icount = 1;
  int jcount = 1;
  int same = 0;
  int large = 0;
  int cshift = 0;
  if (argc < 2) {
    printf("No command-line argument.\n");
    return 1;
  }
  if ((cipher=fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error opening %s\n", argv[1]);
    return 2;
  }
  if(argv[2] == NULL){
    argv[2] = "/usr/share/dict/words";
  }
  if ((dict=fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "Error opening %s.\n", argv[2]);
    return 1;
  }
  ccount=count(dict,1);
  rewind(dict);
  wcount=count(dict,0);
  rewind(dict);
  if((file=(char*)malloc(ccount+1)) == NULL){
    return 1;
  }
  char *p = file;
  while ((chr=fgetc(dict)) != EOF){
    if (isspace(chr)){
      *p = '\0';
    }
    else{
      *p = chr;
    }
    p++;
  }
  *p = '\0';
  rewind(dict);
  p = file;
  if((fword=(char**)malloc((wcount+1)*sizeof(char*))) == NULL){
    return 1;
  }
  char **q = fword;
  if (*p == '\0'){
    p++;
  }
  q[0] = p;
  for (icount=1; icount<wcount; icount++){
    while(*p != '\0'){
      p++;
    }
    while(*p == '\0'){
      p++;
    }
    q[icount] = p;
  }
  q[icount] = '\0';
  q = fword;
  for (jcount=1; jcount<=26; jcount++){
    while ((fgets(line,LEN,cipher)) != NULL){
      word = strtok(line,dl);
      shift = string(word,jcount);
      if(real(shift,q) == 1){
	same++;
      }
      while (word != NULL){
	word = strtok(NULL,dl);
	if(word != NULL){
	  shift = string(word,jcount);
	  if(real(shift,q) == 1){
	    same++;
	  }
	}
      }
    }
    if (large < same){
      large = same;
      cshift = jcount;
    }
    rewind(cipher);
    same = 0;
  }
  jcount = cshift;
  while ((fgets(line,LEN,cipher)) != NULL){
    word = strtok(line,dl);
    shift = string(word,jcount);
    printf("%s ",shift);
    while(word != NULL){
      word = strtok(NULL,dl);
      if(word == NULL){
	printf("\n");
      }
      else{
	shift = string(word,jcount);
	printf("%s ",shift);
      }
    }
  }
  fclose(cipher);
  fclose(dict);
  free(file);
  free(fword);
  return 0;
}
