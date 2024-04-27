#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int status;
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // 자식 프로세스
    printf("Child process: PID = %d\n", getpid());
    sleep(1); // 1초 동안 대기
    printf("Child process: Exiting\n");
    exit(0);
  } else {
    // 부모 프로세스
    printf("Parent process: PID = %d\n", getpid());
    printf("Parent process: Waiting for child to exit...\n");
    wait(&status); // 자식 프로세스가 종료될 때까지 대기
    printf("Parent process: Child exited with status %d\n", status);
  }

  return 0;
}

