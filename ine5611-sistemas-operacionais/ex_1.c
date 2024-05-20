#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

void* worker(void* p) {
  pthread_t tid = pthread_self();
  printf("Nova thread criada. TID = %lu!\n", pthread_self());
  pthread_exit(NULL);
}

int main(void) {
  pthread_t id;
  int v;

  v = pthread_create(&id, NULL, worker, NULL);
  pthread_join(id, NULL);
  
  return 0;
}