#include <iostream>
#include <climits> 
using namespace std;

// <<<<<정수형 자료형>>>>>

int main() {
    // climits 라이브러리 활용함
    //정수형 : 소수부가 없는 수
    // 음의 정수, 0, 양의 정수
    //short, int, long, long long

    int n_int = INT_MAX; //int형이 저장할 수 있는 최대 크기 
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int는 " << sizeof n_int << "바이트이다." << endl;
    cout << " 이 바이트의 최대값은 " << n_int << " 이다." << endl;

    cout << "short는 " << sizeof n_short << "바이트이다. " << endl;
    cout << "이 바이트의 최대값은 " << n_short << " 이다." << endl;

    cout << "long은 " << sizeof n_long << "바이트이다." << endl;
    cout << " 이 바이트의 최대값은 " << n_long << " 이다." << endl;

    cout << "long long은 " << sizeof n_llong << "바이트이다." << endl;
    cout << " 이 바이트의 최대값은 " << n_llong << " 이다." << endl;

/*short는 2바이트이다. 이 바이트의 최대값은 32767 이다.
이 말은 short 자료형의 경우 -32768~+32767까지의 수를 표현 가능
int, short, long, llong의 경우 음의 정수를 표현할 수 없는 unsigned 변형을 하나씩
가지고 있다.*/

    unsigned int a; 
// unsigned가 자료형 앞에 붙으면 음의 값 저장 불가, 
// so, 변수형이 저장할 수 있는 최대값을 늘릴 수 있게 된다.
    unsigned short b; 
// 0~65535까지 저장 가능하게 되는게 unsigned,
// 음수 저장 못하니까 b=-1이라 정의하면 +65535가 출력됨.
// b=-2라 정의하고 출력하면 +65534가 출력됨.
    unsigned long c; // 
    unsigned long long d;

    return 0;

} 

/////////////////////////////////////////////////////////////////

// <<<<<실수형 자료형>>>>> 
#include <iostream>

using namespace std;

int main() {

//실수형 : 소수부가 있는 수

float a = 3.14; // float에서는 소수점을 다루므로 3.14 모두 출력
int b = 3.14; // 정수형인 int에서는 정수만을 다루므로 3 만 출력하게 됨

cout << a << " " << b << endl;

return 0;

}

/////////////////////////////////////////////////////////////////

// <<<<<문자형 자료형>>>>>

#include <iostream>

using namespace std;

int main() {
//char : 작은 문자형
int a = 77;
char b = a;
cout << b << endl;
return 0;
}
//M 이 출력됨. M에 77이 대응되는 문자기 때문이다.
//char는 아스키 코드에서 한 단어를 의미 

int main() {

    int a = 77;
    char b = 'a'; // a 라는 값이 출력됨(c++에서는 ""로 정의 못해)
   //null 문자 '\0'
    cout << b << endl;
    return 0;
}

int main () {
    char b[] = { 'a', 'b', 'c', '\0' };//abc라고 출력, null문자 '\0'
    //여기서 '\0' 를 추가하지 않았으면 abc하고 알 수 없는 문자가 더 나오게 돼.
    //문자형에서는 반드시<< null문자인 \0를 넣어야 원하는 값 도출 가능!! >>
    //\0을 해줌으로써 '아~ abc까지만 출력하면 되는구나' 하는거야
    //"" >> 명시적으로 null 문자가 포함 : string
    cout << b << endl;
    return 0;
}

/////////////////////////////////////////////////////////////////

// <<<<<bool형 자료형>>>>>
#include <iostream>

using namespace std;

int main () {
//bool : 0 혹은 1( 0이외의 모든 수는 1로 저장), 
//0 = false, 1 = true

bool a = 0;
bool b = 1;
bool c = 10;

cout << a << " " << b << " " << c << endl;
return 0;
//0 1 1 로 출력됨 
}

/////////////////////////////////////////////////////////////////

// C에서 상수를 변수로 정의하는 방법 //

#include <iostream> 
#define PIE 3.1415926535 
// PIE 라는 변수에 3.1415926535라는 상수로 정의

using namespace std;

int main() {
//원의 넓이를 구하는 프로그램
//반지름 * 반지름 * 파이
    
   int r = 3;
    
   float s = r * r * PIE; 

cout << s << endl;
    
return 0;
    
}

/////////////////////////////////////////////////////////////////

// <<<<< const 제한자 >>>>>

#include <iostream>

using namespace std;

int main() {
//원의 넓이를 구하는 프로그램
//반지름 * 반지름 * 파이


const float PIE = 3.1415926535; //C++에서는 이렇게 해~~~!!!!!
//const라는 이름의 제한자 + 변수 + 상수의 이름과 값 >> 변수형이 동반
// 상수는 값이 바뀌면 안되기 때문에 값을 같이 대입해줘야 한다.

int r = 3;
//float s = r * r * 3.1415926535;
float s = r * r * PIE; 

//1. 바뀔 필요가 없는 수
//2. 바뀌면 안되는 수 
//>> 그러므로 나중에 PIE = 임의의 수로 정의하면 오류가 난다.
// This is 상수

cout << s << endl;
return 0;
}

/////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main() {

// <<<<<데이터형 변환>>>>>

/*

C++은 데이터형이 풍부해서 사용자가 원하는 데이터형을 골라서 쓸 수 있어
근데 그러면 컴퓨터가 그만큼 처리해야할 일이 많아지겠지. C++은 그래서 다음과 같은
상황에서 자동으로 데이터형을 바꿔주는 '데이터형 변환'을 실시한다.

1. 특정 데이터형의 변수에 다른 데이터형의 값을 대입했을 때 
2. 수식에 데이터형을 혼합하여 사용했을 때 // 산술연산자 강의에서 다루겠음
3. 함수에 매개변수를 전달할 때 // 함수 파트에서 더 자세히 다루겠음

*/

int a = 3.141592; //정수형이니까 3 으로 출력돼. 정수형인 int에 의해 자동으로 변환
cout << a << endl;

//강제적으로 데이터형 변환하려면
//typeName(a) 이렇게 쓰거나 (typeName)a 이렇게 쓰면 된다. : 자료형(변수) = (자료형)변수
char ch = 'M';
cout << (int)ch << " " << int(ch) << endl;
//77 77 로 출력된다. 아스키코드에서는 'M' 이 char로 인해 77을 의미하기 때문.

//C++
//static_cast<typeName>(a) 도 같은 의미로 기능함. 추후 더 설명 : static_cast<자료형>(변수)
cout << static_cast<int>(ch) << endl; // 77이 출력돼.
    
return 0;

}

/////////////////////////////////////////////////////////////////

// <<<<< c++ 산술 연산자 >>>>>

#include <iostream>

using namespace std;

int main() {

    //  + - * %
    // int a = 3 + 2; // 3,2는 피연산자, +는 산술 연산자

    /*
   + : 두 개의 피연산자의 합을 계산한다.
   - : 첫 번째 피연산자와 두 번째 피연산자의 차를 계산한다.
   * : 두 개의 피연산자의 곱을 계산한다.
   / : 첫 번째 피연산자에서 두 번째 피연산자를 나눈다.
   >> 두 개의 피연산자가 모두 정수이면 결과값을 몫이다.
   % : 첫 번째 피연산자를 두 번째 피연산자로 나누어 나머지를 구한다.
   ex = 19 % 6 : 1 
   여기서 부동 소수점(실수)은 사용할 수 없다. 예시는 아래 참조

   int a = 10;
   int b = 2;

   int c = a + b;
   int d = a - b;
   int e = a * b;
   int f = a / b;
   int g = a % b;

    cout << "c : " << c << endl;
    cout << "d : " << d << endl;
    cout << "e : " << e << endl;
    cout << "f : " << f << endl;
    cout << "g : " << g << endl;
    
    */
    int a = 10;
    int b = 3;
    int c = 5;

    int multiple = a + b * c; // 일반적인 사칙연산의 규칙을 따름
    int multiple = a / b * c; // 나눗셈인 /는 좌측에서 우측으로의 연산 방향을 가지므로
     // 10 / 3 의 몫은 3, 그 3 * 5는 15이다. 15가 출력됨.
     // 만약 /에서 a나 b 둘 중에 하나라도 부동 소수점(=실수)이 있다면 그 결과도 실수가 됨.

    cout << multiple;

    return 0;
}

/////////////////////////////////////////////////////////////////

// <<<<< auto >>>>>

#include <iostream>

using namespace std;

int main() {
    /*
auto : C++의 데이터형, 변수를 선언하고 값을 대입하는 것이 아닌,
선언할 때 값을 대입하는 초기화의 방식을 이용하면 데이터형을 auto로 명시하게 되어 
c++가 자동으로 데이터형을 결정하게 됨.
*/
  auto n = 100; // n은 int형
  auto x = 1.5; // x는 float형
  auto y = 1.3e12L; // y는 long long형 
  // C++로 하여금 데이터형을 자동으로 결정하도록 하는 것은 썩 좋을 습관이 아님.
  
  auto x = 0.0; // x는 float형이 되고
  float y = 0;
  auto z = 0; // z는 int형이 됨
  // 생각지도 못하는 오류가 발생할 수 도 있기 때문에 auto형 맹신 금지

}
