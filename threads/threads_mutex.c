#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N_THREADS 128

int g = 0; // Variável global
pthread_mutex_t lock; // Mutex para evitar race condition

void *my_thread(void *vargp) {
  int *my_id = (int *)vargp;

  pthread_mutex_lock(&lock);
  static int s = 0; // Variável estática dentro do contexto da thread.

  ++s; // Incrementando variável global da thread.
  ++g; // Incrementando variável global.

  printf("Thread ID: %d, Static: %d, Global: %d\n", *my_id, ++s, ++g);
  pthread_mutex_unlock(&lock);
}

int main(void) {

  pthread_t thread_id[N_THREADS];
  int thread_ids[N_THREADS];

  pthread_mutex_init(&lock, NULL);

  for (int i = 0; i < N_THREADS; i++) {
    thread_ids[i] = i;
    pthread_create(&thread_id[i], NULL, my_thread, (void *)&thread_ids[i]);
  }

  for (int i = 0; i < N_THREADS; i++) {
    pthread_join(thread_id[i], NULL);
  }

  pthread_mutex_destroy(&lock);

  pthread_exit(NULL);

  return 0;
}