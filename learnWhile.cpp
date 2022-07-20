// <<<<<while문, do while문>>>>>

#include <iostream>
using namespace std;

int main() {

// while문, do while문
// 하기 전에, for문을 잠깐 보자면~
for(int i = 0; i < 3; i++) { } // for문에 조건 제시
    
int i = 0;
for(i; i < 3; i++) { } // 미리 정의한 i를 사용해서 반복문 실행

// <while 문>
int a = 0;
while(a < 3) {a++;} //증감 연산자는 {} 안에 넣기
/*
관계연산자의 연산값이 true, false로 반환된다고 했었는데 데이터형 중에서도 
true, false로만 이루어진 형태가 바로 bool형이다. bool형은 출력값 0에서 
false, 0을 제외한 모든 수에서는 true를 반환한다.

while문은 for문과 다르게 bool형의 조건식만으로 소괄호 내를 정의할 수 있다.
물론, 몸체에 bool형 데이터의 값을 변화해줄만한 요소가 필요하겠지.
*/

// <while문 예제>
string str = "Panda", // "" 로 만들어진 문자열은 개행문자를 포함하고 있음(줄바꿈)
int i = 0;
while (str[i] != '\0') {
    cout << str[i] << endl;
    i++;
} /*
str을 배열처럼 선언할 수 있으니까 0부터 1씩 증가하며 읽다가 str의 문자열이 
끝나면 개행문자 '\0'를 만나게 될 것이다. 그 때, while문은 끝나게 된다. 
여기서 사용한 != 은 같지 않다의 의미기 때문에 str[i]이 \0과
같지 않다면 while문이 사용될 것이고, 
같게 된다면 while문이 끝나는 형식이다.

출력 : 
P
A
N
D
A 가 된다.
*/
// while문은 소괄호 안에 bool형의 조건식만으로도 정의할 수 있다고 했었음. 
// bool형으로 이를 살펴보면 다음과 같다.

string str = "Panda";
bool a = true;
bool b = false;
while (a) {
    cout << "hello\n"; // true이면 while문이 실행됨. 근데 조건이 없으므로
}                      // 출력은 hello가 무한대로 출력된다.

while (b) {
    cout << "hello\n"; // false이면 while문이 실행되지 않으므로 출력은 없다.
}
/* 
기본적으로 for문과 while문은 소괄호 내부에 어떤 내용이 정의되어야 하는지만 다르고
완벽하게 같은 방식으로 돌아간다. for문을 while문으로도, while문을 for문으로도
만들 수 있다.
for문 vs while문의 차이점 : 
1. while문 내부에는 boolean 데이터 하나만으로 정의할 수 있다. 즉, 관계 표현식 없이도
while문을 구성할 수 있다. 
2. 카운터 값을 반복문 내에서 초기화할 수 있냐, 없냐의 차이(예시는 아래 코드 참조)
*/
for (int x = 0; x < 3; x++) {
    cout << "for문 입니다.\n";
 }  // i가 소괄호 내에서 처음 정의되어도 된다. 그리고 i는 for문 내에서 정의되었기
    // 때문에 for문 밖에서 i를 사용할 수 없다.

int j = 0;
while (j < 3) {
    cout << "while문 입니다.\n";
    j++; }
    // j가 정의될 수 있는 공간이 while문의 소괄호 내에 없으므로
    // while문 이전에 이미 선언이 되어있어야 된다.
    // 또, while문 밖에 j가 정의되었으니 while문 밖에서도 j를 사용할 수 있다.

    cout << x << endl; // for문 밖에서 x를 쓰려니 오류 발생
    cout << j << endl;
   
   // <do while 문>
   // : 반복을 실행하고 조건을 검사한다. (while문은 반대야.)
   int j = 0;
   do {
    cout << "do while문 입니다.\n";
    j++;
   } while (j < 3);
   // do while문은 먼저 반복을 1회 실행하고, 조건을 검사한 후 참이면 다시 한번
   // 반복을 수행한다. 고로, while문이 false라서 수행되지 않을 것이라 하더라도
   // 최초 1회는 반드시 수행되도록 되어있다.

   // <boolean으로 표현하면 다음과 같다.>

   bool j = false;
   do {
    cout << "while문 입니다.\n";
    j++;
   } while (j);     // 출력 : while문 입니다.

    return 0;
}
