#include "my_malloc.h"

int main(int argc, char** argv) 
{       
  my_malloc(HEAP_SIZE);
  int i = 0;
  char *sentence = "You're a goofy goober, yeah! "
    "We're all goofy goobers, yeah! "
    "Goofy, goofy, goober, goober, YEAH! "
    "I'm a goofy goober, yeah! "
    "You're a goofy goober, yeah! "
    "We're all goofy goobers, yeah! "
    "Goofy, goofy, goober, goober, YEAH! "
    "Oh, I'm a goofy goober, yeah! "
    "You're a goofy goober, yeah! "
    "We're all goofy goobers, yeah! "
    "Goofy, goofy, goober, goober, YEAH! "
    "I'm a goofy goober, yeah! "
    "You're a goofy goober, yeah!";
   printf("Sentence: %s", sentence);
   char *p = (char*)my_malloc(500);
   char *q = (char*)my_malloc(500);
   for(i=0; i<strlen(sentence); i++){
     p[i] = sentence[i];
   }
   printf("\n\np is : %s\n", p);
   printf("\n\nLocation of p %x\n",p);
   printf("Location of q %x\n",q);
   my_free((void*)p);
   p = my_malloc(0);
   if(p == NULL){
     printf("Zero Input\n");
   }
   p = my_malloc(1000000);
   if(p == NULL){
     if(errno == ENOMEM){
       printf("Error Condition\n");
     }
   }
   my_free((void*)q);
   p = (char*)my_malloc(600);
   q = (char*)my_malloc(500);
   printf("Location of p %x\n",p );
   printf("Location of q %x\n",q );
   my_free((void*)q);
   my_free((void*)p);
   return 0;
}
