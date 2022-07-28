#include <iostream>
#include "time.h"
using namespace std;

int main() {
    // << 연산자 오버로딩 : string 추출 연산자라고 불리기도 해
    Time t1(3, 45);

    t1.show(); // 원래 이렇게 show라는 함수를 만들어 사용했었는데 
    // 만약 <<를 오버로딩해서 다음과 같이 만들 수 있다면,
    cout << t1; // 이렇게되어 편리하다. ==> 프렌드 함수를 통해 오버로딩 가능해

    int x = 5;
    int y = 8;

    cout << x << y; // 출력: 58 로 xy가 연속으로 출력
// cout 은 왼쪽에서 오른쪽으로 구문을 읽으며 << 연산자는 x를 출력하고 다시 괄호로 묶여서 y를 출력하게 됨.
    (cout << x) << y; // 이렇게 되어도 58 로 출력돼

    return 0;
}
// 고로 << 연산자는 iostream에 정의된 객체를 좌항에 대해 피연산자로 요구함. 결과값 역시 좌항에 위치 
// 즉, cout x 라는 표현 자체가 iostream에 저장된 객체로 해석될 수 있음. 구현은 다음참조!

// In 파일 'Overload.h' 에서
(...)
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
    friend std::ostream& operator<<(std::ostream&, Time&);             //
(...)

// In 파일 'learnOO.cpp' 에서
(...)

Time::~Time() {}

Time Time::operator*(int n) {             
    Time result;
    long resultMin = hours * n * 60 + mins * n;
    result.hours = resultMin / 60;
    result.mins = resultMin % 60;
    return result;
}

std::ostream& operator<<(std::ostream& os, Time& t) {                  //   
    os << t.hours << "시간 " << t.hours << "분";
    return os;
}
Line 55에서 <<는 좌항의 값으로 ostream의 객체를 요구하고 있기 때문에 return 형이 os의 참조(&)라는 것을 주목
할 필요가 있다. 그래서 이것은 이 함수가 ostream의 객체에 대한 참조를 리턴한다는 것을 의미하므로 프로그램이
처음 시작할 때 그 함수의 객체에 대한 참조를 전달했기 때문에 결과적으로 함수에 대한 리턴값도 함수에 전달된 객체
자기 자신이 되는거지. 그래서 우리가 main에서 t1.show(); 와 같은 기능으로써  cout << t1; 을 정의할 수 있다.
(...)
