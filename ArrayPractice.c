#include <stdio.h>

#define LEN_A 10

void printArray(int[], int);
void reverse(int[], int);
float average(int[], int);
void insert(int[], int, int, int);
int lessThanAverage(int[], int);
int secondLargest(int[], int);
void rotateRight(int[], int, int);
void arrayCopy(int[], int[], int);
void initialize(int[], int, int);

int main(int argc, char **argv)
{
  int A[] = {9, 21, 321, 117, 27, 64, 13, 9, 12, 208};
  int B[LEN_A+1];
  int newValue=505;

  printf("A[] is:\n");
  printArray(A, LEN_A);

  initialize(B, LEN_A+1, 0);
  printf("B[] is:\n");
  printArray(B, LEN_A+1);

  arrayCopy(B, A, LEN_A);
  printf("but now it's\n");
  printArray(B, LEN_A+1);

  insert(B, newValue, 0, LEN_A);
  printf("and after inserting %d at the beginning it's\n", newValue);
  printArray(B, LEN_A+1);

  printf("The average of A[] is %f\n", average(A,LEN_A));
  printf("There are %d items in A[] less than this.\n", lessThanAverage(A,LEN_A));

  reverse(A, LEN_A);
  printArray(A, LEN_A);

  printf("The second largest item in A[] is %d\n", secondLargest(A, LEN_A));

  rotateRight(A, LEN_A, 3);
  printArray(A, LEN_A);

  return 0;
}

/* prints A[] inside parentheses with each value separated
   by commas to stdout (which will be the screen). */
void printArray(int A[], int length)
{
  int i;
  printf("[");
  for(i=0; i<length; i++){
    int v = A[i];
    if(i == length-1){
      printf(" %d]",v);
    }
    else if (i == 0){
      printf("%d",v);
    }
    else{
      printf(" %d,",v);
    }
  }   
  printf("\n");
}

/* returns the average of the items in A[] or 0.0 if A is empty */
float average(int A[], int length)
{
  int i;
  float sum = 0;
  float average = 0;
  float  numbers = 0;
  for (i=0; i<length; i++){
    int n = A[i];
    sum += n;
    if (n != 0){
      numbers++;
    }
  }
  average = sum/numbers;
  return average;
}

/* returns the number of items in A that are less than the
   average of the items in A */
int lessThanAverage(int A[], int length)
{
  int i;
  int j;
  int sum = 0;
  int less = 0;
  int numbers = 0;
  float average = 0;
  for (i=0; i<length; i++){
    int s = A[i];
    sum += s;
    if (s!=0){
      numbers++;
    }
  }
  average = sum/numbers;
  for(j=0;j<length;j++){
    if(A[j]<average){
      less++;
      }
  }
  return less;
 }

/* Reverses the values in A[].  For example, if before the function,
   A[] contained [1,2,3,4,5], after the function, A[] contains
   [5,4,3,2,1] */
void reverse(int A[], int length)
{
  int i;
  int j;
  int R[length];
  for(i=0; i<length; i++){
    R[i]=A[length-1-i];
  }
  for(j=0; j<length;j++){
    A[j]=R[j];
  }
}

/* returns the second largest item in A[], or -1 if len < 2 */
int secondLargest(int A[], int length)
{
  int i;
  int large = 0;
  int slarge = 0;
  if (length<2){
    return -1;
  }
  for (i=0; i<length; i++){
    if (A[i]> large){
      slarge = large;
      large = A[i];
    }
    else if (A[i]>slarge){
      slarge = A[i];
    }
  }
  return slarge;
}

/* rotates the values in the array numPlaces to the right */
/* for example, if A[] is initially 10,20,30,40,50, and numPlaces=2 */
/* after the function finishes, A[] would be 40,50,10,20,30 */
void rotateRight(int A[], int length, int numPlaces)
{
  int i;
  for(i=0; i<numPlaces; i++){
    int j;
    int p= A[length-1];
    for(j=length-1; j>=0; j--){
      A[j+1]=A[j];
    }
    A[0]=p;
  }
}

/* inserts the value n in A[] at the given index and shifts
   all other values up one position.  A[] contains length items.

   It is up to the caller to make sure that there is enough space
   in A[] to accomodate the new item, and that the index is valid. */
void insert(int A[], int n, int index, int length) {
  int i;
  for(i = length-1; i>index-1; i--){
    A[i+1] = A[i];
  }
  A[index] = n;
}

/* copies the first numItems from S to D. */
void arrayCopy(int D[], int S[], int numItems) {
  int i;
  for(i=0;i<numItems;i++){
    D[i]=S[i];
  }
}
/* sets the first len elements of A to initialValue */
void initialize(int A[], int len, int initialValue) {
  int i;
  for(i=0; i<len; i++){
    A[i]=initialValue;
  }
}
