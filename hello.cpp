// <<<<<변수의 선언과 규칙>>>>>

#include <iostream>

using namespace std;

int main()
{
   //1. 변수란? 변할 수 있는 수
   //cf) 상수 : 변할 수 없는 수

   /*
   1. 변수의 자료형(*)
   2. 변수의 이름(*)
   3. 변수가 어디에 저장되는가?(메모리 영역) 컴파일러가 알아서 지정해줌
   */

  int a; // 선언
  a = 7; // 대입

  int b = 3; // 초기화(선언과 동시에 대입)

  a = 5;
  b = 10;

// 변수는 사용되기 이전에 정의되어야 한다.

  cout << "a = " << "b = " << endl; // a = 5 b = 10 으로 출력

  /* 
  <규칙>
  1. 숫자로 시작할 수 없다.
  2. c++에서 사용하고 있는 키워드는 사용할 수 없다.
  3. white space(여백)를 사용할 수 없다.
    int 77aaa;
    int return;
    int aa aa;
  */
    return 0;
}

/////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int c = 0;
int d = 100;

int main()
{
    int a = 2;
    int b = 2;
    int c = a + b;

    cout << a << " + " << b << " = " << c << endl;

    return 0;
}
