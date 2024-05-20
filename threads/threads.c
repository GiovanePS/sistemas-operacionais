#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // Para utilizar threads

void *my_thread(void *vargp) {
  sleep(1); // Para visualizar o pthread_join acontecendo
  printf("My thread is printing!\n");
  return NULL;
}

int main(void) {
  pthread_t thread_id;
  printf("Before thread.\n");
  pthread_create(&thread_id, NULL, my_thread, NULL);
  pthread_join(thread_id, NULL);
  printf("After thread.\n");
  exit(0);
}