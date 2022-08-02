// 분할 컴파일 (복습 전, 맨 밑 줄 잠깐 참조!!!)
/* : learnDivCompilePrac.cpp 와 fun.cpp 그리고 struct.h 파일 같이 참조!!!
 C++는 프로그램을 구성하는 함수들을 별개의 파일에 두기를 권장한다. 파일들을 개별적으로 분할하여 컴
파일한 후, 하나의 최종 실행 프로그램으로 링크할 수 있는 것이다. 이를 효율적으로 처리하기 위해서 
전처리 지시자인 'include'를 사용한다. 
*/

#include <iostream>

using namespace std;

// Line 13 ~ 19 : 구조체를 정의하고 함수의 원형을 선언하는 파트
struct MyStruct // 1. MyStruct라는 구조체를 만들어서 
{
    string name; // string형의 name과 int형의 age라는 멤버 변수를 만들었다.
    int age;
};

void display(MyStruct&); // 2. void display라는 함수의 원형을 선언했고
// 
// Line 22 ~ 29 : 정의된 구조체와 함수를 사용하는 main() 함수
int main() {
    MyStruct WansCoding = { // 5. main함수에서는 WansCoding이라는 이름의 구조체 변수를 만들었고
        "Wans", // "Wans"와 26을 각각 name과 age로 할당되도록 초기화함
        26,
    };
    display(WansCoding); // 6. display함수에 WansCoding을 매개변수로 호출하면서
    return 0; // 7. 종료
}
//
// Line 32 ~ 35 : 함수의 몸체를 정의
void display(MyStruct& temp) { // 3. 그 함수는 구조체 변수를 받아서
    cout << "이름 : " << temp.name << endl; // 4. 구조체 멤버 변수를 출력하는 역할
    cout << "나이 : " << temp.age << endl;
} // 출력 : 
/* 이름 : Wans
   나이 : 26    */ 

/* 
 위의 코드를 Line 13~19, 32~35, 22~29 로 나누어 분할 컴파일을 실시한다. 구조체 선언이나 함수들의
원형이 들어있는 부분(13~19)은 헤더파일로써 분류할 수 있다. 헤더파일은 주로 다음과 같이 구성된다.
1. 함수의 원형 2. #define이나 const를 사용하는 기호 상수 
3. 구조체 선언 4. 클래스 선언 
5. 템플릿 선언 6. 인라인 함수 로 주로 구성된다. 이에 대한 예시는 아래와 같다.

#include <iostream>

using namespace std;

struct MyStruct
{
    string name;
    int age;
};

void display(MyStruct&);
*/
분할 컴파일의 장점
1. 코드를 획기적으로 재사용할 수 있다.
2. 수정 사항이 생겨도 문제가 생긴 파일에서만 수정하면 되므로 볼륨이 커질수록 수월하게 관리 가능

여기서 규칙!!! 
헤더 파일을 여러 파일에 포함시킬 때, 반드시 단 한 번만 포함시켜야 한다.
#include "struct.h"
// #include "new.h" // new.h는 가상의 헤더파일
위처럼 두번 불러오게 되면 'struct.h' 를 포함시키고 'new.h'를 포함할 때 다시 'struct.h'를 포함하게 되는
불상사가 생기기 때문에 이러한 경우를 막기 위해
- C++에서는 표준기법 ifndef 구문을 적용한다. 예를 들면 다음과 같다.
#ifndef STRUCT // if not define 구문을 사용했다면 여기서부터 
#include <iostream>

using namespace std;

struct MyStruct
{
    string name;
    int age;
};

void display(MyStruct&);

#endif 
// !STRUCT // 여기까지를 STRUCT 라는 이름으로 묶임
// 이는 STRUCT 라는 이름이 #define에 의해서 정의되어 있지 않은 경우에만 이 구문을 처리하게 된다.
 먼저, 위에서 STRUCT 라는 이름의 내용들이 메인함수에 포함되기 위해 '#define STRUCT' 로 STRUCT를 
기호상수로서 정의해줘야 해. 이 후, new.h 를 include하고 다시 
struct.h를 include하려 할때 이미 메인함수에서는 STRUCT 라는 이름으로 묶인 구문이 정의되어 있기 때문에
해당 구문이 무시된 채 실행돼. 정리하자면 #ifndef 부터 #endif 의 구문을 기호상수화 시키는 거야. 
그렇게 되면, 컴파일러가 한 파일을 여러번 포함하는 과정을 막진 못하지만 처음으로 포함시킨 것을 제외한 나머지를
컴파일러가 무시하게 만들게 되는 것이다. 그래서 동일한 내용을 여러번 include 한다해도 처음에 호출되었을 때만
동작하고 이 후에 2차적, 3차적으로 호출된 경우는 무시하기 때문에 안전하게 코딩이 가능하다.

///////참조
수업을 위해 learnClass 파일이 함수 자체에 대한 설명을 담았고, 다음은 실습을 위해 만들어진 것.
learnDivCompilePrac.cpp : main 함수만을 담았음
struct.h : 헤더파일로써, 구조체를 정의하고 함수의 원형을 선언하는 파트가 담김
fun.cpp : 함수의 몸체로써, 출력함수만을 담음

//이해를 위해서 위의 파일 모두 눈으로 확인하면서 체크하자.

분할 컴파일에 대한 방법
1. 헤더파일에 담기는 코드를 '파일이름1.h' 의 파일 형태로 만들어 규칙에 맞게 내용을 담는다.
- #include "파일이름1.h" 으로 연관된 다른 함수에서 불러올 수 있다.
2. 함수의 몸체에 해당하는 출력함수의 내용을 '파일이름2.cpp' 의 형태로 만들고
 맨 위에는 #include "파일이름1.h"으로 관련 헤더파일을 불러온다.
3. main함수만 따로 만들어 두는게 배운 내용에 대한 정리
- 맨 위에 #include "파일이름1.h" 으로 불러오고 메인함수를 실행하면 간결한 모양의 코드 완성

