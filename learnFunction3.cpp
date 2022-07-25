// <인라인 함수와 디폴트 매개변수>

/* 인라인 함수 : 프로그램의 실행속도를 높이기 위해서 C++에서 새로 보완된 함수로써, 의미는 다음과 같다.
일반적으로 함수의 호출은 함수의 주소로 점프하는 과정이며 인라인 함수는 컴파일된 함수 코드가 프로그램의
다른 코드에 삽입된다. 컴파일러의 인라인 함수 호출 = 점프가 아닌 그에 대응하는 함수 코드가 호출되는 것.
대표적으로 함수의 선언 앞에 인라인 키워드를 붙이거나, 함수의 정의 앞에 인라인 키워드를 붙이는데 
아직 배우는 단계이므로 후자의 경우의 예시를 제안한다.
*/

#include <iostream>

using namespace std;

inline float square(float x) { // 1. 함수의 정의 앞에 인라인 키워드를 달고
    return x * x; // 2. 바로 함수의 내용을 코딩
}

int main() {

    int a = 5;
    cout << "한 변의 길이가 " << a << "인 정사각형의 넓이는?" << endl;

    float b = square(a);
    cout << b << endl;

    return 0;
} // 출력: 한 변의 길이가 5인 정사각형의 넓이는? 25

/* 디폴트 매개변수 : 함수를 호출할 때, 실제 매개변수를 생략했을 경우 실제 매개변수 대신 사용되는 디폴트, 
즉, 기본값이다. */ 
#include <iostream>

using namespace std;

const int SIZE = 8;
int sumArr(int*, int n = 1);
//기존: int sumArr(int*, int);

int main() {
    
    int arr[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128}; 
    int sum = sumArr(arr); 
//기존: int sum = sumArr(arr, SIZE); 

    cout << "함수의 총 합은 " << sum << " 입니다.";
    return 0;
}

int sumArr(int* arr, int n) { 

        int total = 0;

    for (int i = 0; i < n; i++) 
    total += arr[i];

    return total; 
}
/*
디폴트란 기존 코드였던 L37을 보면 함수의 원형에서 파라미터의 타입이 정해져 있음을 알 수 있음. 그런데
기존의 L43 코드에서처럼 사용자가 argument로 그 값을 정해주지 않았을 때 L37->L49 로 기본적으로 함수에게
전달되는 값이다.

여기서 L36처럼 파라미터의 값을 정해주게 된다면 사용자가 sumArr라는 함수를 호출하는데 있어서 
만약 n에 해당하는 argument의 값(SIZE, L43)이 있다면 해당 값이 L49의 n으로 전달되고 (L43->L49)
argument의 값이 없다면 L36의 n = 1값이 디폴트로 L49의 n값으로 전달되게 된다. (L36->L49)

출력: 함수의 총 합은 1 입니다.

디폴트 매개변수는 L36 기준으로 항상 오른쪽에서 왼쪽의 방향으로 정의해주어야 한다. 선언하려는 디폴트 매개변수
의 위치를 가장 오른쪽으로 두거나 그 매개변수보다 오른쪽에 위치한 매개변수를 디폴트 매개변수의 값으로 지정해야 한다.
*/

////////////////////////////////////////////////////////////////////////////////////////////////
// <참조로 전달하기*****매우 중요>
/* 참조(reference) : 미리 정의된 변수의 실제 이름 대신 사용할 수 있는 대용 이름
함수의 매개변수를 사용하는데 이를 사용하는 목적이 있다. 참조를 매개변수로 사용하게 된다면 그 함수는 복사본이
아니라 원본의 데이터를 가지고 작업하게 된다. 그래서 만약 구조체의 볼륨이 크다면 함수에서 포인터 대신 참조를
사용하는 것이 실행 속도 측면에서 유리하게 코딩하는 방법이다. 참조 연산자로는 &를 사용한다.(주소 연산자와 동일)
*/
#include <iostream>

using namespace std;

void swap(int, int);

int main() {
/*  int a;
    int& b = a; // int형 변수 a에 대한 참조 변수 선언, 이와 같은 방식을 '참조로 전달' 이라 한다.
*/
  int wallet1 = 100;
  int wallet2 = 200;

  cout << "최초 상태" << endl;
  cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

  cout << "참조를 이용한 값의 교환\n";
  swapA(&wallet1, &wallet2);
  cout << "참조 교환 이후 상태\n";
  cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

  cout << "포인터를 이용한 값의 교환\n";
  swapB(&wallet1, &wallet2);
  cout << "포인터를 이용한 교환 이후 상태\n";
  cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

  cout << "값을 이용한 값의 교환\n";
  swapC(&wallet1, &wallet2);
  cout << "값을 이용한 교환 이후 상태\n";
  cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

  return 0;
}
   
// 참조로 전달하는 방식
void swapA(int& a, int& b) { // parameter의 값이 참조(&)
    int temp;

    temp = a;
    a = b;
    b = temp; // 참조로 전달하는 방식에서는 temp를 통해 a와 b의 값이 바뀜
}
// 포인터로 전달하는 방식
void swapB(int* a, int* b){ // parameter의 값이 포인터(*)
    int temp;

    temp = *a;
    *a = *b;
    *b = temp; // 참조로 전달한 방식으로부터 a와 b의 값이 또 바뀜
}
// 값으로 전달하는 방식
void swapC(int a, int b) { // parameter의 값이 값
    int temp;

    temp = a;
    a = b;
    b = temp; // 값으로 전달하는 방식에서는 (포인터 -> 값으로의 )값의 변화가 없다.
}
/* 출력:
최초 상태
wallet1 = 100, wallet2 = 200
참조를 이용한 값의 교환
참조 교환 이후 상태
wallet1 = 200, wallet2 = 100
포인터를 이용한 값의 교환
포인터를 이용한 교환 이후 상태
wallet1 = 100, wallet2 = 200
값 이용한 값의 교환
값을 이용한 교환 이후 상태
wallet1 = 100, wallet2 = 200
*/
