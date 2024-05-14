#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define TRUE 1
#define COMMAND_MAX_LENGTH 256
#define PARAMETERS_MAX_LENGTH 10

int main(void) {

  while (TRUE) {
    // type command
    char input[COMMAND_MAX_LENGTH];
    char* command[PARAMETERS_MAX_LENGTH];
    int status;

    fgets(input, COMMAND_MAX_LENGTH, stdin);

    // removing '\n' from input
    input[strcspn(input, "\n")] = '\0';

    // read_command
    char* token = strtok(input, " ");
    int param_counter = 0;
    while (token != NULL && param_counter < PARAMETERS_MAX_LENGTH - 1) {
      command[param_counter++] = token;
      token = strtok(NULL, " ");
    }
    
    command[param_counter] = NULL;

    // fork process to execute command
    pid_t pid = fork();
    if (pid < 0) {
      fprintf(stderr, "\nFork failed!\n");
      exit(1);
    } else if (pid == 0) {
      if (execvp(command[0], command) < 0) {
        fprintf(stderr, "\nExecution failed!\n");
      }
    } else {
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}