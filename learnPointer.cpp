#include <iostream>

using namespace std;

int main() {

    //변수 선언 과정

    int val = 3;

    cout << &val << endl; // 변수 val에 대한 주소 값이 출력됨.

    /* C++ : 객체 지향 프로그래밍
    컴파일 시간이 아닌 실행 시간에 어떠한 결정을 내릴 수 있다.
    예를 들어, 배열 생성할 때,

    - 재래적 절차적 프로그래밍 : 배열의 크기가 미리 결정. 

ex) 7일 동안 배열의 크기가 20개인 배열을 사용하다가, 주 1번씩 200개의 배열이 필요
하다면, 200개의 크기를 갖는 배열을 항상 사용해야 하며 동시에 200개를 사용하지 않을
때는 180개의 메모리가 낭비되는 것. : 재래적, 절차적 프로그래밍

BUT,
    - 객체지향 프로그래밍 : 배열의 크기를 실행 시간에 결정.

ex) 20개의 크기를 갖는 배열이 필요하면 [20]을 선언하고, 200개가 간헐적으로 필요
하다면 [200]을 선언할 수 있다. : 객체지향 프로그래밍

    // 변수 선언 과정에서 Pointer의 요지 
    : 기존의 변수 선언 과정에서는 사용할 변수의 이름을 통해 그 변수를 관리했었지만,
    이제는 저장할 데이터를 다루는 주소에 이름을 붙인다고 이해하자.
    => 포인터 : 사용할 주소에 이름을 붙인다. 
    즉, 포인터는 포인터의 이름이 주소를 나타낸다. 
    // 간접값 연산자, 간접 참조 연산자 * 를 이용해 이를 나타낼 수 있다.
    */

   int *a; // C 스타일
   int* b; // C++ 스타일
   int* c, d; // c는 포인터 변수, d는 int형 변수로 사용된다.

   // 예제 

   int a = 6; // a를 변수로 지정하고 그 값을 6으로 초기화 (a는 수이고,)
   int* b; // int형에 포인터 변수 b를 선언, b는 그 자체로 주소를 나타냄. (b는 위치임)

   b = &a; // 주소 연산자 &를 사용해서 a의 주소값을 b에 삽입

   cout << "a의 값 " << a << endl; // 출력: a의 값 6
   cout << "*b의 값 " << *b << endl; // 출력: *b의 값 6, 
   // 포인터로 선언된 변수 *b는 값을 출력할 때, *b 로 출력하지만,

   cout << "a의 주소 " << &a << endl; // 출력: a의 주소값
   cout << "*b의 주소" << b << endl; // 출력: *b의 주소값
   // 주소로써 출력할 때는 그냥 b로 출력한다.

   *b = *b + 1;

   cout << "이제 a의 값은 " << a << endl; // 출력: 이제 a의 값은 7

    return 0;
}

/////////////////////////////////////////////////////////////////

// <new 연산자>

#include <iostream>

using namespace std;

int main() {

    /* new 연산자
1. 어떤 데이터형을 원하는지 new 연산자에게 알려주면 
2. new 연산자는 그에 알맞는 크기의 메모리 블록을 찾아내고,
3. 그 블록의 주소를 리턴합니다. 
*/

int* pointer = new int; 
/* 
new int는 int형 데이터를 지정할 수 있는 새로운 메모리가 필요하다고 알려주는 것
그러면 new연산자는 뒤따라오는 'int'를 보며 데이터형을
확인하고, 몇 byte가 필요한지 계산한다. 그러면 Window 10 기준, int형은 4 byte
이므로 4바이트가 계산될 것이다. 이제 4바이트를 저장할 수 있는 메모리 블록을 찾아
 그 주소를 포인터에게 리턴해서 초기화 해주게 되는 것이다.
*/
// (이전 수업 코드와 비교)
int a;
int* b = &a; // 포인터 변수 b에 a의 주소값을 대입하는 방식


/*
1) int* pointer = new int; 의 경우 'pointer'만 int형 변수에 접근할 수 있으나,
2) int a;  int* b = &a; 의 경우 b와 a의 주소를 통해서 접근할 수 있다. 

그렇다면, 1)에서 pointer는 지시하는 메모리의 이름이 없는데 어떻게 메모리에 접근할
수 있을까? 여기서 pointer가 '데이터의 객체'를 지시하고 있다 라고 표현한다. (객체 지향의 객체가 아님)
이러한 방식은 메모리 제어권을 사용자에게 줄 수 있다는 장점이 있다. 

이렇듯, 필요할 때 new를 사용해서 메모리를 대입하는 것은 C++의 강력한 장점 중 절반.
장점의 다른 절반은 사용한 메모리를 다시 메모리 폴의 영역으로 환수하는 delete 연산자이다.
*/

    // delete 연산자
    /*
    사용한 메모리를 다시 메모리 폴로 환수하는 것. 환수된 메모리는 프로그램의 다른 
    부분이 다시 사용할 수 있다. 
    */

   int* ps = new int; // new를 이용해서 포인터 변수 ps를 선언했고
   //메모리 사용       // 중간에 어떠한 코드를 사용하여 메모리를 사용한 후,
   delete ps; // ps에 할당된 메모리를 다시 프로그램에 다른 부분이 이 메모리를
   //사용할 수 있도록 프로그램에 반환해준다.
/*
 특징 : new를 사용한 후에는 반드시 delete를 사용해야 한다. 그렇지 않으면, 대입은
되었지만 나중에 사용되지 않은 메모리에 대해 누수가 발생할 수 있고 메모리 누수의 
규모가 너무 커지게 되면 프로그램이 먹통이 될 수 있다.

<delete를 사용하는 4가지 규칙>
1. new로 대입하지 않은 메모리는 delete로 해제할 수 없다. 
2. 같은 메모리 블록을 연달아 두 번 연속 delete로 해제할 수 없다.
3. new[]로 메모리를 대입할 경우 delete[]로 해제한다. 
4. 대괄호를 사용하지 않았다면 delete도 대괄호를 사용하지 않아야 한다.
*/

        return 0;

}

// 예제
#include <iostream>

int main() {

    using namespace std;

    double* p3 = new double[3]; // double형 데이터 3개를 저장할 수 있는 공간을 대입한다.
    p3[0] = 0.2;                // p3를 배열 이름처럼 취급한다. 이미 '공간'을 대입했기 때문에
    p3[1] = 0.5;                // p3[숫자] 로써 초기화할 수 있다.
    p3[2] = 0.8;
        
    cout << "p3[1] is " << p3[1] << ".\n"; 
    // 출력: p3[1] is 0.5

    p3 = p3 + 1; // 포인터를 증가시킨다. 포인터는 변수처럼 사용할 수 있기에 값을
    // 더하거나 뺄 수 있다. 만일, p3가 배열의 이름이었다면 틀린 문법이 되는거야.
    // +1 은 double형 데이터 공간 1개로 이해할 수 있다.

    cout << "Now p3[0] is " << p3[0] << " and "; 
    cout << "p3[1] is " << p3[1] << ".\n";
    // 출력: Now p3[0] is 0.5 and p3[1] is 0.8.

    p3 = p3 - 1; // 다시 시작 위치를 지시한다.
    delete[] p3; // p3의 배열 메모리를 해제한다. line 137에서 이미 []를 사용했으니,
                 // 여기서도 delete[]를 사용해야 한다.
    //cin.get();

    return 0;

    }
    
/////////////////////////////////////////////////////////////
// <문자열에서의 포인터 예제>
#include <iostream>
using namespace std;
#define SIZE 20

int main() {

    char animal[SIZE]; // 2-1. 입력받은 animal은 미리 정의한 [20]에 의해서 크기가 정해진다.
    char* ps; // 2-2. char형의 포인터인 ps에 animal의 값을 복사하려고 해

    cout << "동물 이름을 입력하십시오\n"; // 1-1. 사용자로부터 동물 이름을 입력받아
    cin >> animal; // 1-2. 그 입력받은 이름은 animal로 저장

    ps = new char[strlen(animal) + 1]; // 3-1. 그러기 위해서 strlen과 strcpy를 사용할거야.
    // strlen(): strlen(변수)의 형태로 변수의 크기를 반환하는 함수, 
    strcpy(ps, animal); // strcpy(): animal의 값을 ps에 복사하는 함수
    // 3-2. 포인터 변수 ps를 new 연산자를 통해서 사용자가 몇 글자를 입력하든지 그 보다 한 칸 더 넉넉한 공간을 지정하고
    // 3-3. 그리고 strcpy를 통해 그 값을 복사하게 되는 것이다.

    cout << "입력하신 동물 이름을 복사하였습니다." << endl;
    cout << "입력하신 동물 이름은 " << animal << "이고, 그 주소는 " << (int*)animal << " 입니다." << endl;
    cout << "복사된 동물 이름은 " << ps << "이고, 그 주소는 " << (int*)ps << " 입니다." << endl;
    /* 출력: 동물 이름을 입력하십시오
    [사용자 입력: Panda]
    입력하신 동물 이름을 복사하였습니다
    입력하신 동물 이름은 Panda이고, 그 주소는 [주소값1] 입니다.
    복사된 동물 이름은 Panda이고, 그 주소는 [주소값2] 입니다.
    
    <위의 코드 부연설명 및 키포인트>
Line 170: char형의 배열로 문자열을 정의하고자 할 때는 문자열의 크기를 컴파일러에게
미리 알려주어야 한다. 사용자가 몇 글자를 입력할지 모르는 상황에서 new 연산자를 통해 
사용자가 몇 글자를 입력하든지 문자를 복사하기 충분한 공간을 ps에게 부여해줄 수 있다.

Line 183,184: 그래서 우리는 서로 다른 별개의 주소값을 가진 (int*)animal과 (int*)ps로
입력값 animal과 복사된 값 ps를 얻을 수 있었다.

이렇듯, 컴파일 시간에 배열의 크기를 결정하는 것보다 실행시간에 배열의 크기를 결정하는 것이
메모리적 차원에서 훨씬 유리함을 알 수 있다.
이러한 유리함을 저번 시간의 배운 '구조체'에서도 사용할 수 있다. this is 동적 구조체
    */

    delete[] ps;
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// <동적 구조체>의 정의와 예제

#include <iostream>
#define SIZE 20
using namespace std;

struct MyStruct{
    char name[20];
    int age;
}; // 1. 구조체인 MyStruct에는 char형의 name이란 멤버와 int형의 age라는 멤버가 있음.

int main() {

    /* '동적 구조체'의 생성과 기본 원칙
    형태: temp* ps = new temp; // 우리가 배웠던 멤버 연산자는 .(온점)이지만
    동적 구조체에서는 '->' 를 사용한다. */

    MyStruct* temp = new MyStruct; // 2. new 연산자를 이용하여 동적(temp)으로 선언함

    cout << "당신의 이름을 입력하십시오.\n";
    cin >> temp->name; // '.' 대신 '->' 를 이용하여 동적 구조체의 멤버에 접근

    cout << "당신의 나이를 입력하십시오.\n";
    cin >> (*temp).age; // '->' 를 써도 되고 '(*temp).변수' 로 써도 된다.

    cout << "안녕하세요! " << temp->name << "씨!\n";
    cout << "당신은 " << temp->age << "살 이군요!\n";
    
    delete temp;

    return 0;
}
 


    
    
