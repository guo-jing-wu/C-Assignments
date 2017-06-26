#include <stdio.h>


unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
unsigned int getByte(unsigned int, unsigned int);
unsigned int reverse(unsigned int);
unsigned int evens(unsigned int);
int is_negative(int);

int main(int argc, char **argv)
{
  unsigned int i, j;
  int x;

  printf("Enter an integer ");
  scanf("%u", &i);
  printf("\nEnter another integer ");
  scanf("%u", &j);
  printf("\nOne more integer, please ");
  scanf("%d", &x);
  if (is_negative(x)){
    printf("%d is negative\n", x);
  }
  else{
    printf("%d isn't negative\n", x);
  }
  printf("\ni + j = %u\n", add(i,j));
  printf("\ni - j = %u\n", sub(i,j));
  printf("\ni * j = %u\n", mul(i,j));
  printf("jth byte of i = %x\n", getByte(i,j));
  printf("%x in reverse is %x\n", i, reverse(i));
  if (evens(i)){
    printf("There are an even number of 1s in %d\n", i);
  }
  else{
    printf("There are an odd number of 1s in %d\n", i);
  }
    return 0;
  }

  unsigned int add(unsigned int i, unsigned int j)
  {
    /* can be done in a total of 7 lines, including one to declare an unsigned int, */
    /* two for a while loop, and one for the return       */
    unsigned int sum;
    unsigned int carry;
    if (j == 0){
      return i;
    }
    else{
      sum = i ^ j;
      carry = (i & j) << 1;
      return add(sum,carry);
    }
  }

  unsigned int sub(unsigned int i, unsigned int j)
  {
    /* Similar 7 lines, although there is a shorter way */
    /*j = add(~j,i);
      return add(i,j)*/
    unsigned int sum;
    unsigned int l = ~j;
    unsigned int carry;
    if (l == 0){
      return i;
    }
    else{
      sum = i ^ l;
      carry = (i & l) << 1;
      return add(sum, carry);
    }
  }

  unsigned int mul(unsigned int i, unsigned int j)
  {
    /* can be done in a total of 8 lines including one to declare unsigned ints */
    /* two for a for loop, and one for the return      MISSING*/
    unsigned int sum = 0;
    while(j != 0){
      if(j & 0x01){
	sum = add(sum, i);
      }
      i <<= 1;
      j >>= 1;
    }
    return sum;
  }

  /* returns the jth byte of i MISSING*/
  unsigned int getByte(unsigned int i, unsigned int j)
  {
    while ((j = sub(j,1)) > 0){
      }
  }

  /* returns the integer whose binary representation is the
     same as that of i in reverse. */
  unsigned int reverse(unsigned int i)
  {
    unsigned sum = 0;
    unsigned int k;
    int j;
    for (j = 1; j != 0x80000000; j <<= 1){
      sum = add(sum, i & 0x01);
      i >>= 1;
      sum <<= 1;
    }
    sum = add(sum,i & 0x01);
    return sum;
  }

  /* returns 1 if x < 0
     returns 0 otherwise MISSING*/
  int is_negative(int x) {
    x = x >> 31;
    if (x & 0x01){
      return 1;
    }
    else{
      return 0;
    }
  }

  /* returns 1 if there are an even number of 1's in
     x's binary representation or 0 otherwise MISSING*/
  unsigned int evens(unsigned int x) {
    unsigned int total = 0;
    unsigned int j;
    for (j = 1; j; j <<= 1){
      if((x & j) == j){
	total = add(total,1);
      }
    }
    return 0;
  }
