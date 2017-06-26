#include "strlib6.h"

/*test each function, then after finishing the code:
  gcc -o name test.c -L. -lstrlib6*/
int main(void){
  char s[] = "hello";
  char pre[] = "in";
  char suf[] = "ing";
  char rm[] = "tween";
  char ch[] = "inbetweening";
  char lst[] = "  s ";
  char rst[] = "  s ";
  char st[] = "  s ";
  char cc[] = "o";
  char c = 'l';
  int w = 3;
  int x = 7;
  printf("%d\n",is_blank(s));
  printf("%d\n",find_idx(s,c));
  printf("%s\n",find_ptr(s,c));
  printf("%s\n",make_space(w));
  printf("%s\n",center(s,w));
  printf("%d\n",begins_with_ignore_case(ch,pre));
  printf("%d\n",ends_with_ignore_case(ch,suf));
  printf("%s\n",remove_chars(ch,rm));
  printf("%d\n",index_of_first_difference(s,ch));
  lstrip(lst);
  rstrip(rst);
  strip(st);
  printf("%s\n",lst);
  printf("%s\n",rst);
  printf("%s\n",st);
  printf("%s\n",repeat(s,w));
  printf("%s\n",slice(ch,w,x));
  printf("%d\n",strcmp_ign_case(s,ch));
  printf("%s\n",ellipsize(ch,x));
  printf("%s\n",replace(s,cc,ch));
  char **cp = chop(ch,'e');
  printf("%s\n",cp[0]);
  printf("%s\n",cp[1]);
  printf("%s\n",cp[2]);
  return 0;
}
