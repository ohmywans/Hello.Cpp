// 연산자 오버로딩
/* 함수 오버로딩을 배우면서 이름이 같은 여러 함수 정의 가능을 배움. 그래서 함수 오버로딩의 목적은 매개변수의
데이터형이 서로 다르다 할지라도 그 파라미터로 선언된 데이터형의 값에 따라서 동일한 함수이름으로 동일한 연산을
수행하도록 하자는 거임. 연산자 오버로딩은 이러한 오버로딩의 개념을 연산자까지 확장해서 C++에서 연산자들에게
다중적인 의미를 부여하자는 거야.
실제로, 지금까지 배운 C++프로그램도 연산자 오버로딩이 이미 되어있어.
 예를 들어,
*를 주소에 적용하면 그 주소에 저장된 값을 추출하고 
두 값 사이에 *를 적용하면 그 값들의 곱을 산출한다. 
이번 시간에는 연산자 오버로딩을 사용자 정의 데이터형에 확장하는 것을 배울거야.


// <Time 클래스 만들기>
// 설명 : private 멤버로서 시간과 분을 가지고 있고, 이에 대한 함수로 시간을 더하거나 분을 더하는 기능 수행
// 헤더파일 : Overload.h, 내용 : learnOO.cpp, 메인함수 : learnOverloading.cpp

*/
#include <iostream>
#include "Overload.h"

using namespace std;

int main() {
    Time day1(1, 40);
    Time day2(2, 30);

    day1.show();
    day2.show();

    Time total; // total이라는 객체를 만들어 여기에
    total = day1.operator+(day2); // <수정 후>
//  total = day1.sum(day2); // day1과 day2를 합쳐 대입하니 <수정 전>

    Time total2; // <수정 후 추가 코드>
    total2 = day1 + day2;

    total.show(); // 4시간 10분으로 출력 ㅇㅋ
    total2.show();

    return 0;
}
/* 출력 : 이상하게 내가 실행하면 오류뜸 <수정 전>
시간 : 1
분 : 40
시간 : 2
분 : 30
시간 : 4
분 : 10

Line 14: total = day1 + day2; 로 정의될 수 있어야하는데 여기서는 sum으로 대체하고 있다.
그래서 우리가 정의한 Overload 클래스에서 오버로딩된 덧셈 연산자를 사용하는 버전으로 변환하는 것은 쉽다.
바로 sum이라는 함수의 이름을 바꿔주면 된다. sum을 operator로 바꾸고 어떤 산술 연산자를 쓸지
정의해주면 돼. <Overload.h 파일의 Line 16, learnOO.cpp의 Line 24, learnOverloading.cpp의 Line 31>
덧셈이니까 +를 붙인거야

 출력 : <수정 후>
시간 : 1
분 : 40
시간 : 2
분 : 30
시간 : 4
분 : 10
시간 : 4
분 : 10

*/
