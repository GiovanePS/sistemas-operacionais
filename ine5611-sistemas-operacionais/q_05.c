#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESS 3

int main(void) {
  pid_t pid;
  for (int i = 0; i < MAX_PROCESS; i++) {
    if (pid = fork()) {
      pid = fork();
    }
    printf("PID: %d\n", getpid());
  }

  for (int i = 0; i < MAX_PROCESS; i++) {
    wait(NULL);
  }

  return 0;
}