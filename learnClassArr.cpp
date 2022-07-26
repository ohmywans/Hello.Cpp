#include <iostream>
#include "Stock.h"

using namespace std;

int main() {
// 기본적으로 클래스 객체의 배열은 표준 데이터형의 배열을 선언하는 것과 완전히 동일하다.
// Line 09처럼 !
     //  Stock s[4]; 
/* 각 배열의 원소마다 생성자에 정의되어 있던 값들을 정해주지 않았으므로 디폴트 생성자 Stock
에 대입되어 4개의 배열이 만들어질 것이다. 그러면 각 배열의 원소마다 어떻게 값을 부여할지는 아래 참조*/

    Stock s[4] = { // s라는 이름의 Stock형 배열을 4개 선언한 것이고 각 원소마다
    //Stock 생성자를 호출하여 그 생성자에 할당되어 있는 값마다 각 원소로 대입된 것이다.
        Stock("A", 10, 1000),
        Stock("B", 20, 1200),
        Stock("C", 20, 1200),
        Stock("D", 20, 1200)
    };
   
    s[0].show(); 
    // 그러면 배열을 사용하는 것처럼 그 배열의 인덱스로부터 다시 멤버함수를 호출할 수 있다.
    return 0;
}
출력:
회사 명 : A
주식 수 : 10 
주가 : 1000
주식 총 가치 : 10000
D클래스가 소멸되었습니다.
C클래스가 소멸되었습니다.
B클래스가 소멸되었습니다.
A클래스가 소멸되었습니다.

// 이전 수업에서 만들었던 topval 함수를 이용하여 배열의 원소들 중 어느 것의 주가가 제일 
// 높을지 알아내는 함수를 만들 수 있겠지.
int main() {

    Stock s[4] = {
        Stock("A", 10, 1000),
        Stock("B", 20, 1200),
        Stock("C", 20, 1300),
        Stock("D", 20, 1400)
    };

    Stock first = s[0]; // Stock first를 배열의 첫번째 원소에 할당하고
    for(int i = 1; i < 4; i++) // 카운터 값을 1부터 하여 배열의 끝까지 반복문을 돌도록 한다.
    first = first.topval(s[i]); // first와 반복문을 돌며 수행되는 배열의 원소에 topval
       //의 리턴값을 저장하게 된다면
// 처음 반복 : 저장된 배열의 첫번째 원소와 두번째 원소를 비교해서 그 값은 first에 저장
// 두번째 : 저장된 값과 두번째 원소를 비교해서 first에 저장
// 마지막 : 저장된 값과 세번째 원소를 비교하면서 반복문이 끝나게 됨
    
    first.show(); // 반복문에 의한 출력값을 알 수 있도록!

    return 0;
}
// 잠깐 만들었던 topval 함수를 되짚어보면,
/* topval 함수는 호출한 객체 *this나 매개변수 객체 s에 share_val을 비교하여 리턴하게 되는데
그 리턴형을 보게 되면 두 객체에 대한 참조를 리턴하기 때문에 topval의 참조 연산자(&)를 붙여준다.
그래서 Line 46에서 s[0]을 first에 직접적으로 대입하는 것이 아니라 첫번째 원소에 대한 포인터를
지정하는 방법으로도 코드를 바꿔볼 수 있다.
*/

// <in 내용 파일>
(...)
   Stock &Stock::topval(Stock& s) { // <수정 후>
// Stock Stock::topval(Stock& s) {  <수정 전>
    if (s.share_val > share_val)
    return s;
    else 
    return *this; 
}
(...)

// <in 헤더 파일>
(...)
public:

void buy(int, float); 
void sell(int, float); 
void update(float); 
void show();

   Stock topval(Stock&); // <수정 후>
// Stock topval(Stock&);    <수정 전>
    Stock();
    ~Stock();
(...)

// <in 메인 함수>
(...)
   Stock *first = &s[0]; // <수정 후>
// Stock first = s[0];      <수정 전>
    for(int i = 1; i < 4; i++) 
   first = &first->topval(s[i]); // <수정 후>
// first = first.topval(s[i]);      <수정 전>
(...)

출력 : 
회사 명 : D
주식 수 : 20 
주가 : 1400
주식 총 가치 : 28000
