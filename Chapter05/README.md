# Chapter 05

**1번 : fork ()를 호출하는 프로그램을 작성하라. EOrk ()를 호출하기 전에 메인 프로세스 는 변수에 접근하고 (예, x) 변수에 값을 지정하라 (예, 100). 자식 프로세스에서 그 변수의 값은 무엇인가? 부모와 자식이 변수 x를 변경한 후에 변수는 어떻게 변했는가?**

간단해서 소스코드만 작성

**2번 : open () 시스템 콜을 사용하여 파일을 여는 프로그램을 작성하고 새 프로세스를 생성하기 위하여 Eork ()를 호출하라. 자식과 부모가 open ()에 의해 반환된 파일 디스크립터에 접근할 수 있는가? 부모와 자식 프로세스가 동시에 파일에 쓰기 작업을 할 수 있는가?**
<img width="1072" alt="Screenshot 2024-04-27 at 6 19 18 PM" src="https://github.com/SmallzooDev/OSTEP/assets/121675217/f29b2833-b249-4379-b899-3a72e0a3875e">
되긴 한다. 근데 되는게 맞는지 모르겠다

**3번 : fork ()를 사용하는 다른 프로그램을 작성하라. 자식 프로세스는 bello"를 출력하고 부모 프로세스는 "goodbye"를 출력해야 한다. 항상 자식 프로세스가 먼저 출력하게 하라. 부모가 wait ()를 호출하지 않고 할 수 있는가?**
<img width="1072" alt="Screenshot 2024-04-27 at 6 30 50 PM" src="https://github.com/SmallzooDev/OSTEP/assets/121675217/0c906ad3-9111-467d-af52-79f2d6b23ef9">

ㅋㅋㅋㅋㅋㅋㅋ.... 이것밖에 생각안난다

**4번 : fork ()를 호출하고 /bin/ls를 실행하기 위하여 exec() 계열의 함수를 호출 하는 프로그램을 작성하라.exec()의 변형 execl(), execle(), execlP(), execv (), execvp (), execve () 모두를 사용할 수 있는지 시도해 보라. 기본적으 로는 동일한 기능을 수행하는 시스템 콜에 여러 변형이 있는 이유를 생각해 보라.**
<img width="1072" alt="Screenshot 2024-04-27 at 6 41 59 PM" src="https://github.com/SmallzooDev/OSTEP/assets/121675217/134e636d-a43d-4929-b476-dc9d281a817b">

파라미터가 다름, 환경변수 배열 등

**5번 : wait ()를 사용하여 자식 프로세스가 종료되기를 기다리는 프로그램을 작성하라. wait()가 반환하는 것은 무엇인가? 자식 프로세스가 wait ()를 호출하면 어떤 결과가 발생하는가?**
<img width="1072" alt="Screenshot 2024-04-27 at 7 00 37 PM" src="https://github.com/SmallzooDev/OSTEP/assets/121675217/41ff0f19-0e1e-4a77-a4fc-cdad6810d936">

**6번: 위 문제에서 작성한 프로그램을 수정하여 wait () 대신에 1waltp1d()를 사용하라. 어떤 경우에 waitpid()를 사용하는 것이 좋은가?**
waitpid() 함수는 wait()와 비슷하지만, 특정한 자식 프로세스를 대상으로 대기할 수 있습니다. 또한 옵션을 통해 대기 상태에서 빠져나올 조건을 지정할 수 있습니다.
라고 하는데, 함수 명세를 봐도 어떻게 쓸지는 딱히 생각이 안난다.

**7번: 자식 프로세스를 생성하고 자식 프로세스가 표준 출력(SIDOUT_FILENO)을 닫는 프 로그램을 작성하라. 자식이 표준출력을 닫은 후에 출력을 위해 printf ()를 호출하면 무슨 일이 생기는가?**
간단하고 예상한대로!
<img width="1072" alt="Screenshot 2024-04-27 at 7 13 10 PM" src="https://github.com/SmallzooDev/OSTEP/assets/121675217/9ba05fb7-840b-4856-98fe-897e662aee14">

**8번: 두 개의 자식 프로세스를 생성하고 pipe () 시스템 콜을 사용하여 한 자식의 표준 출력을 다른 자식의 입력으로 연결하는 프로그램을 작성하라.**
