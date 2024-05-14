#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {

  char* file_name = "22";

  int fd = open(file_name, O_RDONLY);

  if (fd == -1) {
    printf("\nError opening file!\n");
    return 1;
  }

  char buffer[1024];

  lseek(fd, 3, SEEK_SET); // Move fd para o byte 3
  read(fd, buffer, 4);

  printf("\nFile contents: %s\n", buffer);
  // Output: 1592
  // A saída é essa porque, lseek moveu fd para o byte 3, que é o quarto byte.
  // E read, lendo os 4 bytes do quarto byte em diante, lê 1592.

  return 0;
}