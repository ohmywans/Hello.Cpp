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

//////////////////////////

// <<<<<실수형 자료형>>>>> 

int main() {

//실수형 : 소수부가 있는 수

float a = 3.14; // float에서는 소수점을 다루므로 3.14 모두 출력
int b = 3.14; // 정수형인 int에서는 정수만을 다루므로 3 만 출력하게 됨

cout << a << " " << b << endl;

return 0;

}

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

// <<<<<bool형 자료형>>>>>

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
