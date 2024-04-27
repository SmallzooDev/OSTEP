#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int rc;

  rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Child process: Closing standard output\n");
    close(STDOUT_FILENO); // 표준 출력을 닫음
    // 표준 출력이 닫혔으므로 printf()로 출력이 불가능
    printf("This message will not be printed\n");
    exit(0);
  } else {
    // 부모 프로세스
    wait(NULL);
    printf("Parent process: Child process completed\n");
  }

  return 0;
}
