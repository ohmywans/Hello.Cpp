// 분기 구문 : 컴퓨터에게 여러가지 갈래길을 제시하고 그 중 컴퓨터가 하나의 길을 선택하여 사용할 수 있게 하는 구문
// => if, if else, switch
#include <iostream>
using namespace std;

// if 구문
int main() {

   // if(조건) 코드 의 형태 : 조건이 참이면 코드 실행, 거짓이면 건너뜀
   if (true)
   cout << "조건이 참입니다.";

   if (false)
   cout << "조건이 거짓입니다.";

   cout << "프로그램이 종료되었습니다."
// 출력: 조건이 참입니다. 프로그램이 종료되었습니다. : false이면 코드가 실행되지 않으니까!
// if문 뒤에 이렇게 {}를 안해도 되고 하면 여러 줄의 코드를 실행하도록 할 수 있다.

// if else 구문
   if (false) {
    cout << "조건이 ";
    cout << "거짓입니다." << endl;
   }
   else {
    cout << "조건이 ";
    cout << "참입니다." << endl;
   }
   cout << "프로그램이 종료되었습니다.";
// 출력: 조건이 참입니다.  : if문이 false이므로 실행되지 않고 '그렇지 않으면'의 의미인 else문이 실행됨
// 프로그램이 종료되었습니다.

// if else 구문 속 if else 구문
   if (false) {
    cout << "#1";
   } else if (true) {
    cout << "#2";
   } else {
   cout << "#1";
   } // 출력: #2 : 이렇듯 코드의 확장 가능
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
// 논리 표현식 : 1개 이상의 조건을 검사할 때 사용하는 식

#include <iostream>
using namespace std;

// 논리 표현식
// 논리합(||), 논리곱(&&), 논리부정 연산자(!)

/* 1. 논리합 : OR 논리이고, || (Shift + \ 를 2번)으로 표기
좌항 || 우항 : 둘 중 어느 하나가 true거나, 0이 아니라면 전체 표현식은 true가 되고 
그렇지 않으면 false가 된다. 아래는 예시
5 == 5 || 5 == 9 // 좌항 : 참, 우항 : 거짓, 전체 : 참
5 > 3 || 5 > 10 // 좌항 : 참, 우항 : 거짓, 전체 : 참
5 > 8 || 5 < 10 // 좌항 : 거짓, 우항 : 참, 전체 : 참
5 > 9 || 5 < 2 // 좌항 : 거짓, 우항 : 거짓, 전체 : 거짓
*/

/* 2. 논리곱 : AND 논리이고, && 으로 표기
좌항 && 우항 : 두 식이 모두 true 여야만 전체식이 true가 된다.
5 == 5 && 9 == 9 // 좌항 : 참, 우항 : 참, 전체 : 참
5 == 5 && 9 != 9 // 좌항 : 참, 우항 : 거짓, 전체 : 거짓
10 < 2 && 10 > 2 // 좌항 : 거짓, 우항 : 참, 전체 : 거짓
*/

/* 3. 논리부정 연산자 : 뒤 따르는 표현식의 값을 반대로 한다. !로 표기
!(표현식) : 표현식이 true이면 좌측은 false 반환
!(5 > 3) : false     !(5 < 3) : true
*/
int main() {
    cout << "당신의 나이를 입력하십시오.";
    int age;
    cin >> age;

    if (age < 0 || age > 100) {
        cout << "거짓말 하시면 안됩니다!\n";
    } else if (20 <= age && age <= 29) {
        cout << "당신은 20대 이군요?\n";
    } else {
        cout << : "당신의 나이를 잘 모르겠습니다.\n";
    }

    return 0;
}
