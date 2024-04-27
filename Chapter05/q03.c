#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Start Number 03 on (pid:%d)\n", (int)getpid());

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Hello");
  } else {
    // 이것 밖에 생각이 안난다 ㅋㅋ
    sleep(1);
    printf("Goodbye\n");
  }
}
