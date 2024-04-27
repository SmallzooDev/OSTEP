#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  const char *file_path = "test.txt";

  int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    perror("Failed to open file");
    exit(EXIT_FAILURE);
  }

  int rc = fork();
  if (rc == -1) {
    perror("Failed to fork process");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    if (dprintf(fd, "Child process writes to file.\n") < 0) {
      perror("Failed to write to file");
      exit(EXIT_FAILURE);
    }
  } else {
    if (dprintf(fd, "Parent process writes to file.\n") < 0) {
      perror("Failed to write to file");
      exit(EXIT_FAILURE);
    }
  }

  close(fd);
  return 0;
}
