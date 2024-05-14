#include <stdio.h> // Para utilizar a função printf
#include <stdlib.h> // Para utilizar a função exit
#include <unistd.h> // Para utilizar a função read
#include <fcntl.h> // Para utilizar a constante O_RDONLY

int main(void) {

  char* file_name = "file";

  int fd = open(file_name, O_RDONLY);

  if (fd == -1) {
    printf("\nError opening file!\n");
    exit(1);
  } else {
    printf("\nFile opened successfully!\n", file_name);
  }

  char buffer[1024];

  int bytes_read = read(fd, buffer, sizeof(buffer));

  printf("\n%d bytes read!\n", bytes_read);
  printf("File contents: %s\n", buffer);

  return 0;
}