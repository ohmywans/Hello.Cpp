// 추상화와 클래스
// 데이터형이란 무엇인가? : 해당 데이터형을 통해 어떤 연산을 수행할 수 있는가? (아래 예시)

#include <iostream>

using namespace std;

int main() {

    int a = 3; // int형의 경우
    int b = 4; // + - * % / 의 5가지 연산 모두 가능
    cout << sizeof(a) << "byte" << endl; // 출력: 4byte 

    int* a_ = &a; // 포인터의 경우
    int* b_ = &b; // int형과 마찬가지로 4바이트를 지니지만 연산은 불가능
    cout << sizeof(a_) << "byte" << endl; // 출력: 4byte 

    return 0;
}

// 클래스란? : 추상화를 사용자 정의 데이터형으로 변환해주는 수단
// 추상화란? : 어떤 객체를 사실적으로 표현하는게 아니라 공통된 특징을 간결한 방식으로,
//            이해하기 쉽게 표현하는 것.
/* 클래스는 다음과 같이 두 부분으로 나눌 수 있다.
1. 클래스를 선언하는 부분
2. 클래스 메소드를 정의하는 부분           */
// 다음은 예시 <주제 : 주식, Stock> 자세한 설명은 클래스 코드 마무리 후 글 참조
#include <iostream>

using namespace std;

class Stock
{
private: 
    string name; // (데이터형) (클래스의 멤버 이름); 의 형태
    int shares;
    float share_val;
    double total_val; 
    // double형 : float형과 같은 실수를 다루는데 더 넓은 범위를 다룬다고 보자.
    void set_total() {
        total_val = shares * share_val;
    } // total_val은 주식 수 * 가격의 값이니까 자동으로 계산되도록 함수를 만든거야.


public:
void Stock::acquire(string co, int n, float pr) { 
// 주식의 선언(매개변수로 주식명, 개수, 가격을 받아 name, shares, share_val에 각각 매칭) 
    name = co;
    shares = n;
    share_val = pr;
    set_total();
} // Stock 클래스에 귀속되도록 Stock:: 사용
void Stock::buy(int n, float pr) { // 주식의 구매 
    shares -= n;
    share_val = pr;
    set_total();
}
void Stock::sell(int n, float pr) { // 주식의 판매 
    shares -= n;
    share_val = pr;
    set_total();
}
void Stock::update(float pr) { // 주식의 가격 변동 
    share_val = pr;
    set_total();
}
void Stock::show() { // 주식의 내용 출력 
    cout << "회사 명 : " << name << endl;
    cout << "주식 수 : " << shares << endl;
    cout << "주가 : " << share_val << endl;
    cout << "주식 총 가치 : " << total_val << endl;
}
    Stock();
    ~Stock();
};

// <Stock 클래스에서 public 영역의 멤버함수를 선언하는 방법>
// C++에서 기본적으로 제공하는 멤버 함수, 생성자와 파괴자
// 사용 범위 결정 연산자 ' :: ' 를 사용해서 클래스에 귀속되도록 함.
Stock::Stock() // 생성자
{
}

Stock::~Stock() // 파괴자
{
}
/* 설명 / 이렇게 클래스를 만드는거야~
private, public : 이 클래스 멤버에 대한 접근을 제한하는 역할
가령, Stock이라는 클래스는 현재 name, shares, share_val, total_val을 멤버로써
이들은 모두 private의 멤버들이다. Stock 클래스가 가진 private 함수 멤버들의 값을 
변경하려면 반드시 public에 선언되어 있는 함수들을 통해서 값을 변경해줘야 한다.
 예를 들어, float share_val을 변경한다고 할 때 public 함수에 정의되어 있는 update를
사용해야 한다. 그러므로, public에 정의되어 있는 멤버 함수들은 프로그램이 private에 정의된
멤버 변수들의 값을 변경해주거나 변경할 수 있는 다리 역할을 해준다. 프로그램이 private
함수에 직접적으로 접근할 수 없고 public 함수를 통해야만 가능하기 때문에
이렇게 데이터에 직접 접근하지 못하게 차단하는 것을 '데이터 은닉' 이라고 한다. 이것은 
추상화의 여러 예 중 하나이다.
정리.
- public : 공개된 멤버, 클래스로 외부에서도 접근 가능
- private : 비공개 멤버로 클래스 내에서만 접근 가능
* 직접적인 Data는 private으로 선언하여 데이터를 은닉하자.
*/

int main() {

    Stock temp;
    temp.acquire("Wans Company ", 100, 1000);
    temp.show();
    temp.buy(10, 1200);
    temp.show();
    temp.sell(5, 800);
    temp.show();

    return 0;
}
/* 출력:
회사 명 : Wans Company // Line 106 ~ 107
주식 수 : 100
주가 : 1000
주식 총 가치 : 100000
회사 명 : Wans Company // Line 108 ~ 109
주식 수 : 110
주가 : 1200
주식 총 가치 : 132000
회사 명 : Wans Company // Line 110 ~ 111
주식 수 : 105
주가 : 800
주식 총 가치 : 84000


분할 컴파일 해볼게 -> 해도 위와 같은 결과 출력됨
main : learnClassPrac.cpp
header : Stock.h
내용 : StockMem.cpp
*/
