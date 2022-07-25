// 함수 오버로딩(=함수의 다형 : 다양한 형태를 지닌 함수)
// 오버로딩 : 여러 개의 함수를 같은 이름으로 연결한다.

#include <iostream>

using namespace std;

// 함수의 오버로딩 예시
void print(char, int); // 매개변수로써 char형 한 개, int형 한 개를 지니고
void print(int, int); // int형 두 개,
void print(char); // char형 한 개를 지님
// 위에 정의된 매개변수를 읽고 그에 알맞은 함수로 하나하나 매칭을 해줌

int main() {

    print('a', 3); // Line 9에 매칭
    print(3, 2); // Line 10에 매칭
    print('a'); // Line 11에 매칭
    
    return 0;
}

// 같은 동작을 수행하지만 데이터형이 다를 때를 위해 함수의 오버로딩을 구현하는 예시
int sum(int, int);
float sum(float, float);

int main(){
  cout << "두 정수를 입력하십시오. \n";
  int a, b;
  cin >> a >> b;
  cout << "두 정수의 합은 " << sum(a, b) << "입니다.\n";
  cout << "두 실수를 입력하십시오. \n";
  float c, d;
  cin >> c >> d;
  cout << "두 실수의 합은 " << sum(c, d) << "입니다.\n";

  return 0;
}

int sum(int a, int b){
  return a + b;
}

float sum(float a, float b){
  return a + b;
}
/* 출력:
두 정수를 입력하십시오.
(사용자 입력) 2 8
두 정수의 합은 10입니다.
두 실수를 입력하십시오.
(사용자 입력) 1.1 2.4
두 실수의 합은 3.5입니다.
*/

// (잘못된 예시) 1. 함수의 리턴형만 다를 경우 2. 함수 사용 시, 두 개 이상의 함수에 대응되는 경우

int sum(int, int);
float sum(int, int);
// (1번 예시) 두 함수는 같은 파라미터인 int형 변수 2개를 받는데 리턴형만 int형과 float형으로 다르다. 
// (2번 예시) 만약, sum이 L58에도 대응되고 L59에도 대응된다면 컴파일러가 결정하지 못하므로 에러 발생.
// 이 두 가지 에러를 고려해서 학습
int main() {
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// <일반화 프로그래밍, 템플릿*****과 오버로딩>

// 함수 템플릿은 함수의 일반화에 대한 서술로써, 일반화란 객체 지향 프로그래밍의 목표인데 
// 함수 템플릿이란 구체적인 데이터형을 포괄할 수 있는 일반형으로 함수를 정의하는 것이다. 예시는 아래.

#include <iostream>

using namespace std;

// class 혹은 typeName으로 써도 된다.
template <class Any>
// 여기서의 template에서 Any는 데이터형의 일반화에 해당, 사용자가 어떤 데이터형을 사용할지 정해지지 X
Any sum(Any, Any);

Any sum(int, Any); // L93을 실행하기 위해 템플릿 구성(a : int형, c : float형 대응)

int main(){
    int a = 3;
    int b = 4;
    cout << sum(a, b) << endl; // L85에 의하여 L78의 Any는 int형으로 매칭됨, 출력: 7

    float c = 3.14;
    float d = 1.592;
    cout << sum(c, d) << endl; // L89에 의하여 L78의 Any는 float형으로 매칭됨, 출력: 4.732

/* cout << sum(a, c) << endl; // 출력 : 6.14
    // 오류 : 인수 목록이 일치하는 함수 템플릿 'sum'의 인스턴스가 없습니다. (L82가 없는 경우 오류발생)
    // sum(a, c)는 int형과 float형을 파라미터로 가진다. 첫번째 파라미터 a의 데이터형이 int형이기 때문에
        L78의 Any는 int형으로 매칭된다. 그런데 float형 변수인 c에게 전달하고 있으므로 에러 발생
*/
    return 0;
}

template <class Any>
Any sum(Any a, Any b){
    return a + b;
}
///////////////////////////////////////////////////////////////////////////////////////////////
// <템플릿과 오버로딩>

template <class Any>
Any sum(Any, Any);
template <class Any>
Any sum(int, Any);

int main(){
    int a = 3;
    int b = 4;
    // cout << sum(a, b) << endl; 
    // int형 변수 2개를 파라미터로 취하고 있는데 L109, 111의 sum에 모두 매칭되어 오류 발생

    float c = 3.14;
    float d = 1.592;
    cout << sum(c, d) << endl; // 출력 : 4.732

    cout << sum(a, c) << endl; // 출력 : 6.14

    return 0;
}

template <class Any>
Any sum(Any a, Any b){
    return a + b;
}

template <class Any>
Any sum(int a, Any b){
    return a + b;
}
