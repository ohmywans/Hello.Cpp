// 생성자(Constructor)와 파괴자(Destructor)

// learnAbstractClass.cpp의 코드 일부를 가져와본다면,
public:

void acquire(string, int, float); 
void buy(int, float); 
void sell(int, float); 
void update(float); 
void show();

Stock::Stock() {}  // 생성자
Stock::~Stock() {} // 파괴자
// L6 의 acquire 함수에서 요구하고 있는 파라미터와 함수의 동작처럼 생성자를 꾸며줄 수 있다. 
// 아래 코드처럼!
public:

// 생성자에 acquire에 관한 정보를 담으면서 이 자리에 있던 acquire는 없앤다!
void buy(int, float); 
void sell(int, float); 
void update(float); 
void show();

Stock::Stock(string co, int n, float pr) // 생성자
{
    name = co;
    shares = n;
    share_val = pr;
    set_total();
}

Stock::~Stock() // 파괴자
{
}
// 그러면 Stock이라는 데이터형을 선언할 때 다음과 같은 두 가지 방법으로 선언할 수 있다.
// 선언하기 전 원본 main 함수
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
// 선언 후 2가지 방법 제안 
int main() {

    Stock temp = Stock("Wans Company", 100, 1000); // 첫번째 방법
    Stock temp2("Wans Company", 100, 1000); // 두번째 방법
   
    temp.show();
    temp.buy(10, 1200);
    temp.show();
    temp.sell(5, 800);
    temp.show();

    return 0;
}
//////////////
// 생성자의 매개변수를 취하는 생성자를 만들었으니 새로운 디폴트 생성자를 만들어주어야 하는데
// 이것을 함수의 오버로딩을 이용해서 만들겠다.
// <<<헤더 함수>>> ///////////////////////////////////////
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
// 이 자리 acquire 없앴고
void buy(int, float); 
void sell(int, float); 
void update(float); 
void show();
Stock(string, int, float); // L6 처럼!

    Stock();
    ~Stock();
};

#endif // !STOCK

// <<<내용이 들어간 함수>>> ///////////////////////////////////////
#include "Stock.h"

// acquire 없앴고
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
Stock::Stock(string co, int n, float pr)
{
    name = co;
    shares = n;
    share_val = pr;
    set_total();
}
    
Stock::Stock() { // 아무런 매개변수가 없을 때는 비어 있는 값으로 만들 수 있겠지
    name = "";
    shares = 0;
    share_val = 0;
    set_total();
} // this is 디폴트 매개변수

Stock::~Stock() {}


// <파괴자> 
객체를 생성하기 위해 생성자를 사용할 때 프로그램은 객체의 수명이 다할 때까지 그 객체를 
추적하는 책임을 맡게 된다. 객체의 수명이 끝나는 시점에서 프로그램은 파괴자라는 특별한 멤버
함수를 자동으로 호출한다. 

Stock::~Stock() {} // ~ 는 틸테 라고 하는데 문장 앞에 ~가 붙으면 파괴자로 명시된다.
생성자와 마찬가지로 파괴자도 리턴값을 가질 수 없고 선행 데이터형을 가지지 않는다. 그리고 
생성자와 더불어 파괴자는 매개변수를 가지지 않는다. 파괴자는 파괴하는 일 외에 아무것도 
하는 일이 없으므로 그저 {} 그 자체의 비어 있는 값으로 코딩될 수 있다. 또, 사용자가 명시적으로
코드 내부에서 파괴자를 호출할 수 없다. 하지만 우리는 배우는 입장이니 파괴자가 어떻게 활동하는지
알아보기 위해서 간단하게 출력문을 넣어볼게
Stock::~Stock() {
    cout << name << "클래스가 소멸되었습니다\n";
} 
// 이렇게 되는데 전체적인 함수의 모양은 아래의 메인함수, 내용, 헤더함수 참고!

//<<<메인 함수>>> ///////////////////////////////////////
#include <iostream>
#include "Stock.h"

int main() {

	cout << "생성자를 이용해 객체 생성\n";
	Stock temp("Panda", 100, 1000); // 생성자를 이용, temp라는 이름의 객체 생성

	cout << "디폴트 생성자를 이용하여 객체 생성\n";
	Stock temp2; // 디폴트 생성자를 이용, temp2라는 객체 생성

	cout << "temp와 temp2 대입\n";
	temp2 = temp; // temp2에 temp를 대입하고

    cout << "temp와 temp2 출력\n"; // 이를 출력해보니 L194, 198처럼 string형으로 출력
    temp.show(); 
    temp2.show();

	cout << "생성자를 이용하여 temp 내용 재설정\n";
	temp = Stock("Coding", 200, 1000); 
    // L169의 내용을 무시하고 이 내용을 쓰며 이전 클래스 소멸 구문 출력

	cout << "재설정된 temp 출력\n";
	temp.show();

	return 0;
}
출력 :
생성자를 이용해 객체 생성
디폴트 생성자를 이용하여 객체 생성
temp와 temp2 대입
temp와 temp2 출력
회사 명 : Panda
주식 수 : 100
주가 : 1000
주식 총 가치 : 100000
회사 명 : Panda
주식 수 : 100
주가 : 1000
주식 총 가치 : 100000
생성자를 이용하여 temp 내용 재설정
Coding클래스가 소멸되었습니다.
재설정된 temp 출력
회사 명 : Coding
주식 수 : 200
주가 : 1000
주식 총 가치 : 200000
Panda클래스가 소멸되었습니다.
Coding클래스가 소멸되었습니다.
// 이처럼 프로그램이 종료되면서 클래스의 소멸 구문이 출력됨.
//파괴자를 직접 호출하지는 않았지만 자동으로 호출된거지!

// <<<내용>>> ///////////////////////////////////////
#include "Stock.h"

void Stock::buy(int n, float pr) {
	shares += n;
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

Stock::Stock(string co, int n, float pr) {
	name = co;
	shares = n;
	share_val = pr;
	set_total();
}

Stock::Stock() {
	name = "";
	shares = 0;
	share_val = 0;
	set_total();
}


Stock::~Stock()
{
	cout << name << "클래스가 소멸되었습니다. \n";
}
// <<<헤더함수>>> ///////////////////////////////////////
#ifndef STOCK
#define STOCK
#include <iostream>


using namespace std;

class Stock
{
private:
	string name;
	int shares;
	float share_val;
	double total_val;
	void set_total() { total_val = shares * share_val; }

public: 
	void buy(int, float);
	void sell(int, float);
	void update(float);
	void show();
	Stock(string, int, float);
	Stock();
	~Stock();
};
#endif // !STOCK
