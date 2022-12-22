#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "reader_writer.h"

// delcaring variables
rwlock_t lock;
pthread_t writerThreads[20], readerThreads[20];

void* readerThread(void * arg)
{
  wait_readlock(&lock);
  // critical section
  printf("Reader is reading\n");
  printf("Reader finished reading\n");
  post_readlock(&lock);
  return NULL;
}

void* writerThread(void * arg)
{
  wait_writerlock(&lock);
  // critical section
  printf("Writer is writing\n");
  printf("Writer finished writing\n");
  post_writerlock(&lock);
  return NULL;
}

void reading_writing(){
  int x=0, i, j , T;
  T = rand() % 10000;
  for(i = 0; i < T; i++)
    {
      x = i * j;
    }
}


int main()
{
  FILE *file;
  int error;
  char buf[20];
  int scenarioCount = 0;
  int readCount = 0;
  int writeCount = 0;
  int i = 0;

  rwlock_init(&lock);

  file = fopen("scenarios.txt","r");

  if (file)
  {
    printf("Scenario starting:\n");
    while (fgets(buf, 20, file))
    {
      scenarioCount++;
      while(buf[i] != EOF){
        if(buf[i] == "r")
        {
          error = pthread_create(readerThreads[readCount], NULL, (void *)readerThread, (void *)&lock);
          printf("Creating new reader thread\n");
          readCount++;
          if(error != 0)
          {
            printf("Thread cannot be read");
            return 1;
          }
        }
        else if(buf[i] == "w")
        {
          error = pthread_create(writerThreads[readCount], NULL, (void *)writerThread, (void *)&lock);
          printf("Creating new writer thread\n");
          writeCount++;
          if(error != 0)
          {
            printf("Thread cannot be read");
            return 1;
          }
        }
        i++;
      }
      for(i=0;i<readCount;i++)
        {
          pthread_join(readerThreads[i],NULL)
        }

      for(i=0;i<writeCount;i++)
        {
          pthread_join(writerThreads[i],NULL)
        }
    }  
    }
    else
    {
      printf("Error opening file...\n");
      return 1;
    }
    fclose(file);

    return 0;
}