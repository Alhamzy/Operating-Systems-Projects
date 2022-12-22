#include <pthread.h>
#include <semaphore.h>

typedef struct _rwlock_t {
  int readers;
  sem_t wrt;
  sem_t mutex;
  sem_t mutex2;
} rwlock_t;

void rwlock_init(rwlock_t *lock);
void wait_writelock(rwlock_t *lock);
void post_writelock(rwlock_t *lock);
void wait_readlock(rwlock_t *lock);
void post_readlock(rwlock_t *lock);
