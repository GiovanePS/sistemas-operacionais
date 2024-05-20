#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 1024
static int contador_global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* p) {
  for (int x = 0; x < 100; x++) {
    pthread_mutex_lock(&mutex);
    contador_global++;
    pthread_mutex_unlock(&mutex);
  }
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

  printf("%d\n", contador_global);
  
  return 0;
}