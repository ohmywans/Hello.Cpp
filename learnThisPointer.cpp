지금까지 만들었던 멤버 함수를 보면 void buy나 sell, update, show 모두 하나의 객체만을 처리
하는 경우가 많았다. 하지만 가끔은 하나의 멤버 함수가 두 개의 객체를 동시에 처리할 상황이 있
을 수 있다. 가령, 두 개의 클래스를 받아서 그 중 share_val이 높은 클래스를 반환하려고 하면
이러한 함수는 어떻게 만들지 다음 코드를 살펴보자. 변경된 사항은 '//' 를 통해 표시해두겠다.

// <헤더 파일> //////////////////////////////////////////////
#ifndef STOCK
#include <iostream>
using namespace std;

class Stock
{
private: 

    string name; 
    int shares;
    float share_val;
    double total_val; 
    
    void set_total() {
        total_val = shares * share_val;
    }


public:

void buy(int, float); 
void sell(int, float); 
void update(float); 
void show();

Stock topval(Stock&); // 
Stock(string, int, float); // 
Stock();
~Stock();
};

#endif // !STOCK

// <내용 파일> //////////////////////////////////////////////
#include "Stock.h"

void Stock::buy(int n, float pr) { 

    shares -= n;
    share_val = pr;
    set_total();

}
void Stock::sell(int n, float pr) {

    shares -= n;
    share_val = pr;
    set_total();

}
void Stock::update(float pr) { 

    share_val = pr;
    set_total();

}

void Stock::show() { 
    cout << "회사 명 : " << name << endl;
    cout << "주식 수 : " << shares << endl;
    cout << "주가 : " << share_val << endl;
    cout << "주식 총 가치 : " << total_val << endl;
}
Stock Stock::topval(Stock& s) {  //
    if (s.share_val > share_val)
    return s;
    else 
    return *this;
} // this 포인터 : 멤버함수를 호출하는데 사용된 객체를 지시
// this는 포인터기 때문에 주소를 나타냄. 그 객체를 리턴하고자 한다면 앞에 * 기호를 붙여줌.
    
Stock::Stock() 
{
}

Stock::~Stock()
{
}
// <메인 함수> //////////////////////////////////////////////
#include <iostream>
#include "Stock.h"

int main() {

	Stock s1("A", 10, 1000);
    Stock s2("B", 20, 1200);

    s1.show();
    s2.show();

    cout << "A와 B중 share_val이 큰 객체는\n";
    s1.topval(s2).show(); // 이렇게 쓰면 L111~115 를 통해 높은 share_val을 가진 객체가 출력됨

	return 0;
}
출력:
회사 명 : A
주식 수 : 10
주가 : 1000
주식 총 가치 : 10000
회사 명 : B
주식 수 : 20
주가 : 1200
주식 총 가치 : 24000
A와 B중 share_val이 큰 객체는
회사 명 : B
주식 수 : 20
주가 : 1200
주식 총 가치 : 24000
B클래스가 소멸되었습니다.
B클래스가 소멸되었습니다.
A클래스가 소멸되었습니다.
// 정리 : C++ 멤버 함수를 호출하는데 사용할 객체를 지시할 수 있는 this 포인터를 배웠어!
