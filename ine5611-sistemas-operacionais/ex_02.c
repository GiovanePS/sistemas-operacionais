#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5

void* worker(void* p) {
  pthread_t tid = pthread_self();
  printf("Nova thread criada. TID = %lu\n", pthread_self());
  pthread_exit(NULL);
}

int main(void) {
  pthread_t ids[MAX_THREADS];
  int v;

  for (int i = 0; i < MAX_THREADS; i++) {
    v = pthread_create(&ids[i], NULL, worker, NULL);
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(ids[i], NULL);
  }
  
  return 0;
}