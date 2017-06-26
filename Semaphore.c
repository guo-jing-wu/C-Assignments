#include <stdio.h> //printf
#include <semaphore.h> //sem_t,sem_wait,sem_post,sem_init
#include <pthread.h> //pthread_t,pthread_create,pthread_join
#include <stdlib.h> //rand,srand
#include <time.h> //time
#include <unistd.h> //sleep
#define SIZE 20 //buffer size
#define P rand()%24+4 //number of producers
#define C rand()%23+3 //number of consumers

sem_t mutexD; //mutual exclusion for producer
sem_t mutexF; //mutual exclusion for consumer
sem_t full; //number of full buffer slots
sem_t empty; //number of empty buffer slots
int front = 0; //front of buffer
int rear = 0; //back of buffer
int prod = 0; //producer thread number
int con = 0; //consumer thread number
int buf[SIZE]; //buffer

void *producer (){
  srand(time(NULL)); //initialize randomization
  prod++; //increment producer thread number
  int pN = prod; //producer thread #
  while (1){ //infinite loop
    int i = rand()%2; //create data to add
    sem_wait(&empty); //decrement empty buffer cells
    sem_wait(&mutexD); //enter critical section
    buf[rear] = i; //end of buffer
    rear = (rear+1)%SIZE; //insert data
    printf("Producer %d: %d\n",pN, i);
    sem_post(&mutexD); //leave critical section
    sem_post(&full); //increment full buffer cells
    if ((i%2) == 1){
      sleep(1); //vary producer thread speed
    }
  }
}

void *consumer (){
  con++; //increment consumer thread number
  int cN = con; ///increment consumer thread number
  while (1){ //infinite loop
    sem_wait(&full); //decrement full buffer cells
    sem_wait(&mutexF); //enter critical section
    int j = rand()%2; //data to be removed
    j = buf[front]; //front of buffer
    front = (front+1)%SIZE;//remove data
    printf("Consumer %d: %d\n",con, j);
    sem_post(&mutexF); //leave critical section
    sem_post(&empty); //increment empty buffer cells
    if ((j%2) == 1){
      sleep(1); //vary consumer thread speed
    }
  }
}

int main (){
  pthread_t p[P]; //initialize producer thread id
  pthread_t c[C]; //initialize consumer thread id
  int index; //initialize number to be created
  sem_init(&full,0,0); //initialize semaphore full
  sem_init(&empty,0,SIZE); //initialize semaphore empty
  sem_init(&mutexD,0,1); //initialize semaphore mutexD
  sem_init(&mutexF,0,1); //initialize semaphore mutexF
  for(index=0; index<P; index++){ //0 to P
    pthread_create(&p[index],NULL,producer,NULL); //create producer thread
  }
  for(index=0; index<C; index++){ //0 to C
    pthread_create(&c[index],NULL,consumer,NULL); //create consumer thread
  }
  for(index=0; index<C; index++){ //0 to C
    pthread_join(c[index],NULL); //join consumer thread
  }
  for(index=0; index<P; index++){ //0 to P
    pthread_join(p[index],NULL); //join producer thread
  }
}
