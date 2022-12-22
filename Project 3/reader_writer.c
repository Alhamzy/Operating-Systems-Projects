#include "reader_writer.h"

void rwlock_init(rwlock_t *lock) {
  lock->reader = 0;
  sem_init(&lock->wrt, 0 ,1);
  sem_init(&lock->mutex, 0 ,1);
}

void wait_writelock(rwlock_t *lock) {
  sem_wait(&lock->wrt);
}

void post_writelock(rwlock_t *lock) {
  sem_post(&lock->wrt);
  sem_post(&lock->mutex);  
}

void wait_readlock(rwlock_t *lock) {
  sem_wait(&lock->mutex);
  lock->readers++;
  if (lock->reader == 1) {
    sem_wait(&lock->wrt);
  }
  sem_post(&lock->mutex);
}

void wait_readlock(rwlock_t *lock) {
  sem_wait(&lock->mutex);
  lock->readers--;
  if (lock->reader == 0) {
    sem_post(&lock->wrt);
  }
  sem_post(&lock->mutex);
}