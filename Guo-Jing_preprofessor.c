#include<stdio.h>
#define NS 0 /*NS = No State*/
#define FS 1 /*FS = First State*/
#define SS 2 /*SS = Second Star*/

int main(int argc, char **argv){
  int c;
  int quote = NS;
  int slash = NS;
  int star = NS;
  int state = NS;

  while ((c = getchar())!= (EOF)){
    if ((c == '"') || (c == '\'')){
      if (quote == NS){
	putchar(c);
	quote = FS;
      }
      else if (quote == FS){
	putchar(c);
	quote = NS;
      }
    }
    else if ((quote == FS) && (state == NS)){
	putchar(c);
      }
    else if(c == '/'){
      if(state == NS){
	slash = FS;
      }
      else if (star = FS){
	state = NS;
	slash = NS;
	star = NS;
	putchar(' ');
      }
      else if((slash == FS) && (star == FS)){
	state = FS;
	putchar(' ');
      }
      else if((state == FS) && (star == SS)){
	state = NS;
      }
      else{
	putchar(c);
      }
    }
    else if(c == '*'){
      if(slash == FS){
	state = FS;
      }
      else if(state == FS){
        star = SS;
	slash = NS;
      }
      else{
	putchar(c);
      }
    }
    else if (state == NS){
      if (slash == FS){
	putchar('/');
      }
      else{
	putchar(c);
	slash = NS;
	star = NS;
      }
    }
  }
  if (quote == FS){
    printf("Error: Unterminated quote\n");
  }
  if(state == FS){
    printf("Error: Missing star and/or slash\n");
  }
  if((state == FS) && (star == SS)){
    printf("Error: Missing slash\n");
  }
  return 0;
}
