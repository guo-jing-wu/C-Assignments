#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 13

struct problem {
  char *q;			/* question */
  char *a;			/* answer */
};

void winner();
void loser(int);
int playGame(struct problem *);
int getRandomChoice();
void printWelcome();
void beSuperficiallyFriendly();

struct problem problems[] = {{"Who was the first president?",
			      "Washington"},
			     {"What is the capital of Pennsylvania?",
			      "Harrisburg"},
			     {"Who was the last president of the Soviet Union?",
			      "Gorbachev"},
			     {"What is the largest ocean?",
			      "Pacific"},
			     {"Who was the Wizard of Menlo Park?",
			      "Edison"},
			     {"What sort of figure has 12 sides?",
			      "dodecagon"},
			     {"In what country will the 2014 World Cup be held?", 
			      "Brazil"},
			     {"In what country will the 2016 Summer Olympics be held?", 
			      "Brazil"},
			     {"Who lives in a pineapple under the sea?",
			      "Spongebob"},
			     {"Where does Grunkle Stan live?",
			      "Gravity Falls"},
			     {"Which US state borders exactly one other US state?",
			      "Maine"},
			     {"Who sang It's Not Easy Being Green?",
			      "Kermit"},
			     {"In what city did Laverne and Shirley live?",
			      "Milwaukee"}};

int main(void)
{
  int rchoice;

  rchoice = getRandomChoice();
  printWelcome();
  beSuperficiallyFriendly();
  if (playGame(&problems[rchoice]))
    winner();
  else
    loser(rchoice);

  return 0;
}

void beSuperficiallyFriendly() {
  char name[16];

  printf("What's your name ? "); 
  gets(name); 
  printf("Hi, %s.  Get ready to play.\n", name);
}

void winner()
{
  printf("You've won a million dollars.\n");
  exit(0);
}

void loser(int p)
{
  printf("\nYou've lost.  The right answer was '%s'.  Thanks for playing.\n",
	 problems[p].a);
  exit(1);
}

int playGame(struct problem *p)
{
  char guess[16];

  printf("The next question is:\n");
  printf("%s ", p->q);
  gets(guess);
  return !strcasecmp(p->a,guess);
}

int getRandomChoice()
{
  int r;
  srand((unsigned int)time((time_t *)NULL));
  r = rand();
  return r%NUM_QUESTIONS;
}

void printWelcome()
{
  printf("|----------------------------------------------------------|\n");
  printf("| Welcome to 2107 Trivia.                                  |\n");
  printf("| Please do not give your answer in the form of a question |\n");
  printf("|----------------------------------------------------------|\n");
}
