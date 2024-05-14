#include <stdio.h> // Para utilizar a função printf.
#include <sys/types.h> // Para utilizar o tipo pid_t.
#include <unistd.h> // Para utilizar a função fork.
#include <stdlib.h> // Para utilizar a função exit.

int main(void) {

  pid_t p = fork();

  if (p < 0) {
    perror("fork fail\n");
    exit(1);
  }

  printf("Hello world!, process_id(pid) = %d\n", getpid());

  return 0;
}