#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Hello World!");
  printf("From (pid:%d)\n", (int)getpid());
  int i = 1117;

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Hello, I am child (pid:%d)\n", (int)getpid());
    i = 121;
    printf("child i: %d\n", i);
  } else {
    i = 122;
    printf("Hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    printf("parent i: %d\n", i);
  }
}
