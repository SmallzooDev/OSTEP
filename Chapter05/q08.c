#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd[2]; // 파일 디스크립터 배열

  // 파이프 생성
  if (pipe(fd) == -1) {
    perror("pipe failed");
    exit(1);
  }

  // 첫 번째 자식 프로세스 생성
  int rc1 = fork();
  if (rc1 < 0) {
    perror("fork failed");
    exit(1);
  } else if (rc1 == 0) {
    // 자식 프로세스 1
    // 표준 출력을 파이프 입력으로 복제
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]); // 파이프의 읽기 디스크립터 닫기

    // ls 명령어 실행
    execlp("ls", "ls", NULL);
    perror("execlp failed");
    exit(1);
  }

  // 두 번째 자식 프로세스 생성
  int rc2 = fork();
  if (rc2 < 0) {
    perror("fork failed");
    exit(1);
  } else if (rc2 == 0) {
    // 자식 프로세스 2
    // 표준 입력을 파이프 출력으로 복제
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]); // 파이프의 쓰기 디스크립터 닫기

    // wc 명령어 실행
    execlp("wc", "wc", "-l", NULL);
    perror("execlp failed");
    exit(1);
  }

  // 부모 프로세스는 자식 프로세스의 종료를 기다림
  close(fd[0]);
  close(fd[1]);
  wait(NULL);
  wait(NULL);

  return 0;
}
