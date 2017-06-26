#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define AMPERSAND 1 /*&*/
#define PIPE 2 /*|*/
#define INPUT 3 /*<*/
#define OUTPUT 4 /*>*/
int c = 0; /*int to find &, |, <, and >*/
int i = 0; /*location of c*/

void parse(char *line, char **argv) /*go through the line and put each 'word' into an array*/
{
  while (*line != '\0') { /*go through the entire line*/
    while (*line == ' ' || *line == '\t' || *line == '\n'){ /*check if the char is a space, tab, or a new line*/
      *line++ = '\0'; /*if there is, set it to null*/
    }
    *argv++ = line; /*then add the word into the array*/
    while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n'){ /*else, continue*/
      line++;
    }
  }
  *argv = '\0'; /*set the end of the array to NULL*/
}

void find (char **argv){ /*find if there is an &, |, <, or >*/
  int j = 0;
  while (argv[j] != NULL){
    if (strcmp(argv[j],"&") == 0){ /*find &*/
      c = AMPERSAND;
      argv[j] = NULL;
    }
    else if (strcmp(argv[j],"|") == 0){ /*find |*/
      c = PIPE;
      argv[j] = NULL;
      i = j;
    }
    else if (strcmp(argv[j],"<") == 0){ /*find <*/
      c = INPUT;
      argv[j] = NULL;
      i = j;
    }
    else if (strcmp(argv[j],">") == 0){ /*find >*/
      c = OUTPUT;
      argv[j] = NULL;
      i = j;
    }
    j++;
  }
}

void execute(char **argv) /**/
{
  pid_t pid; /*initialize a process id*/
  int status; /*status of child process*/
  if (c == PIPE){
    int thePipe[2]; /*read and write*/
    pipe (thePipe); /*initialize pipe*/
    if ((pid = fork()) == 0) { /*child process*/
      dup2 (thePipe[1],1); /*duplicate file descriptor*/
      close (thePipe[0]); /*close read end*/
      close (thePipe[1]); /*close write end*/
      if (execvp(argv[i-1], argv+(i-1)) < 0) { /*execute a command*/
	printf("ERROR: exec failed\n");
	exit(1);
      }
    }
    if ((pid = fork()) == 0){ /*another child process*/
      dup2 (thePipe[0],0); /*duplicate file descriptor*/
      close(thePipe[0]); /*close read end*/
      close (thePipe[1]); /*close read end*/
      if (execvp(argv[i+1], argv+(i+1)) < 0) { /*execute a command*/
	printf("ERROR: exec failed\n");
	exit(1);
      }
    }
    else {
      close (thePipe[0]); /*close read end*/
      close (thePipe[1]); /*close write end*/
      wait(&status);
      wait(&status);
    }
  }
  if ((pid = fork()) == 0){
    if (c == INPUT){
      int newstdin = open(argv[i+1],O_RDONLY);
      close(0);
      dup(newstdin);
      close(newstdin);
    }
    if (c == OUTPUT){
      int newstdout = open(argv[i+1],O_WRONLY|O_CREAT,S_IRWXU|S_IRWXG|S_IRWXO);
      close(1);
      dup(newstdout);
      close(newstdout);
    }
    if (execvp(*argv, argv) < 0) { /*execute a command*/
      printf("ERROR: exec failed\n");
      exit(1);
    }
  }
 else {
   if (c != AMPERSAND){
      wait(&status); /*wait for completion*/
   }
 }
}

int main ()
{
  char line[1024]; /*input line*/
  char *argv[100]; /*array to store*/
  while (1) { /*infinite loop*/
    printf("Shell -> "); /*prompt*/
    gets (line); /*user input*/
    printf("\n");
    parse (line, argv); /*parse the input into the array*/
    find (argv); /*check for &,|,<,>*/
    if (strcmp(argv[0], "exit") == 0) { /*if exit is typed, exit the shell*/
      exit(0);
    }
    else {
      execute(argv); /*execute the the command*/
    }
  }
}
