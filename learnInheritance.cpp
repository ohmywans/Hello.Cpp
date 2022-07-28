/* 
 객체 지향 프로그래밍에서 가장 중요한 목적 중 하나는 재사용이 가능한 코드를 제공하는 것. 함수로써 
함수이름을 호출하는 것만으로 재사용할 수 있게 되는데 C++에서는 좀 더 높은 차원에서 이를 제공한다.
그것은 바로 상속. 다음은 상속의 기능이다.

1. 기존의 클래스에 새로운 기능을 추가할 수 있다.
2. 클래스가 나타내고 있는 데이터에 다른 데이터를 더 추가할 수 있다. 
3. 클래스 메소드가 동작하는 방식을 변경할 수 있다. 
*/
// 상속 설명을 위해 저번 시간에 배운 Time 클래스의 헤더파일을 가져와봤어.

#ifndef OVERLOADH
#define OVERLOADH
#include <iostream>

class Time // Time 클래스를 다른 클래스로부터 상속할 때 오리지널 클래스는 기초 클래스라 하고
{          // 상속받는 클래스는 파생 클래스라고 한다. 즉, Time : 기초 클래스이고, 파생 클래스는 만들거야!
private: 
    int hours; 
    int mins;

public:
    Time();
    Time(int, int); 
    void addHours(int);
    void addMins(int);
    Time operator+(Time&); 
    Time operator*(int);
    void show();
    ~Time();
    friend Time operator*(int n, Time& t) {
        return t * n;
    }
    friend std::ostream& operator<<(std::ostream&, Time&);
};
class NewTime : public Time { // class (파생 클래스 이름) : public (기초 클래스 이름) 의 형태!!

private:
    int days; // private 멤버 변수로 int형 변수 days를 지정했다.

public:
    NewTime(), // NewTime의 매개변수를 아무것도 지정하지 않았을 때와
    NewTime(int, int, int); // int형 변수 3개로 지정했을 때로 구성했다.
} /* 규칙
1. 파생 클래스형의 객체 안에는 기초 클래스형의 데이터 멤버들이 저장된다. (따로 정의하지 않아도!)
2. 파생 클래스형의 객체는 기초 클래스형의 메소드들을 사용할 수 있다.
3. 파생 클래스는 자기 자신의 생성자를 필요로 한다.
4. 파생 클래스는 부가적인 데이터 멤버들과 멤버 함수들을 임의로 추가할 수 있다.
*/
#endif // !OVERLOADH

// NewTime 생성자를 정의해보자. (L41~43을 바탕으로!)
// In 파일 'learnOO.cpp' + 'learnShiftOperator.cpp' 에서
(...)
Time::~Time() {}

Time Time::operator*(int n) {             
    Time result;
    long resultMin = hours * n * 60 + mins * n;
    result.hours = resultMin / 60;
    result.mins = resultMin % 60;
    return result;
}

std::ostream& operator<<(std::ostream& os, Time& t) {               
    os << t.hours << "시간 " << t.hours << "분";
    return os;
}
/*
NewTime::NewTime() { // private 변수로 days를 가지고, 원형 클래스인 Time은 private 변수로 hours, mins를
// 가지고 있다. 그래서 아무런 파라미터 리스트를 주지 않은 NewTime 에서는 days, hours, mins를 모두 0으로 초기화 해야 한다.
<수정 전>
}

NewTime::NewTime(int, int, int) { // 파라미터 변수에 지정되도록 days, hours, mins에 int가 하나씩 할당되어야 한다.
<수정 전>
}
 파생 클래스는 원형 클래스의 public 멤버 함수에 접근할 수 있지만 private 멤버 함수에는 접근할 수 없다. 가령,
addHours, addMins는 호출이 자유로운 반면, hours, mins는 private 멤버 함수기 때문에 접근이 자유롭지 않다는 것이다.
이러한 문제를 해결하기 위해서 어떤 방법을 사용해야 할까? 
프로그램이 파생 클래스의 객체를 생성할 때 먼저 기초 클래스의 객체를 생성하고, 그 이후 기초 클래스의 객체에 
덧붙이는 방법으로 파생 클래스의 객체를 생성한다. 즉 개념적으로 되짚어보면, 
프로그램이 파생 클래스의 생성자 몸체 안으로 들어가기 이전에 기초 클래스에 객체가 먼저 생성되어야 한다는 것이다.
C++ 이를 위해 '멤버 초기자 리스트 문법' 을 사용한다. 다음과 같다.
*/
NewTime::NewTime() : Time() { // ': Time()' 이 멤버 초기자 문법이고 
    days = 0;
} // <수정 후> 
// 간단 원리: 'NewTime()'을 프로그램에서 호출한다면 먼저 멤버 초기자 리스트에 의해 'Time()' 객체가 
// 생성되고 다시 이것을 매개변수의 자격으로 'NewTime()' 객체에 전달하게 되는 것이다.
// 'learnOO.cpp' 에서 Time::Time() {hours = mins = 0;} 로 정의되어 있으므로 days만 0으로 초기화하자.

NewTime::NewTime(int h, int m, int d) : Time(h, m) { // 'Time(h,m)' 이 멤버 초기자 문법이다.
    day = d;
} // <수정 후>
// 파생 클래스의 생성자가 기초 클래스의 생성자에게 매개변수를 전달하게 된다. 
// 여기선, int h와 int m 이 되겠지. 그래서 'Time(h, m)' 은 각각 hours와 mins로 설정하게 되는거야.
// 그리고 남은 매개변수인 int d의 값을 days 저장하면 될거야.(Line 94)
(...)

// 이렇게 되서야 main()에서 NewTime을 선언할 수 있게 돼.
// main()인 'learnOverloading.cpp' 참조하면

#include <iostream>
#include "Overload.h"

using namespace std;

int main() {
    NewTime temp1(); // temp1에서는 days, hours, mins가 0으로 초기화되어 있을거고
    NewTime temp2(3, 30, 2); // temp2에서는 hours = 3, mins = 30, days = 2 로 초기화됨.

    return 0;
}

// Time 클래스의 헤더 파일을 다시 가져와서
(...)
class NewTime : public Time { 

private:
    int days; 

public:
    NewTime(), 
    NewTime(int, int, int); 
    void print();                    // 
};
#endif // !OVERLOADH

// 그리고 내용이 들어있는 함수에서 
(...)

NewTime::NewTime() : Time() {
    days = 0;
} 

NewTime::NewTime(int h, int m, int d) : Time(h, m) {
    day = d;
}

void NewTime::print() {
    std::cout << "일 : " << days << std::endl;
    show();
}
(...)

// 메인에서
(...)
#include <iostream>
#include "Overload.h"

using namespace std;

int main() {
    NewTime temp1(); 
    NewTime temp2(3, 30, 2); 
    temp2.print();

    return 0;
}
(...)
/* 출력:
일 : 2
시간 : 3
분 : 30
*/
