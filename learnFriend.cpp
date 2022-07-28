/* 지금까지의 클래스는 private 부분의 접근할 수 있는 유일한 통로가 public 클래스에 정의된 메소드들
이었어. 그런데 C++에서는 public 부분이외에도 private 부분에 멤버 변수로 접근할 수 있는 통로가 하나
더 있다. 바로 이번 시간의 C++에서의 friend 이다. 함수를 어떤 클래스에 대해 프렌드로 만들게되면
그 프렌드 함수는 클래스에 멤버 함수들이 갖는 것도 동일한 접근 권한을 갖는다. 즉, public 영역에 정의된
멤버 함수들 처럼 프렌드 함수는 private 함수에 접근할 수 있게 되는거야. 왜 이 프렌드라는 함수가 필요할
까. 그것은 어떤 클래스에 이항 연산자를 오버로딩하면 프렌드를 만들 필요성이 생긴다.
이항 연산자 : 두 개의 피연산자를 요구하는 연산자
저번 시간의 배운 learnOverloading.cpp 파일의 operator+ 에 대해 살펴보자. operator+는 새로운 Time
객체를 만드는데 그 객체가 가지고 있는 private 멤버에 mins와 hours의 값은 '+로 묶어준 두 객체가 가진
mins와 hour의 합(sum)' 이었다. 만약, operator* 를 만든다 가정하자. 어떻게 표현할 수 있을까*/
// operator*
Time a, b; //객체를 만들고
a = b * 3; // 표현하기 
여기서 발생하는 차이 >> operator+는 Time 클래스 객체 간의 합을 Time 클래스 객체 안에 저장하는 식이었는데, 
operator*는 Time 클래스 객체와 int형 변수의 연산을 통해 Time 클래스 객체에 값을 저장하는 식인거지.
정리하면,
operator+ >>> 'Time 클래스 객체 = Time 클래스 객체 + Time 클래스 객체' 
operator* >>> 'Time 클래스 객체 = Time 클래스 객체 * int형 변수' 인데, 이를 함수를 통해 쓰면
a = b.operator*(3); 이렇게 쓰일 수 있을텐데 () 안에 매개변수가 Time 클래스의 객체가 아니라 int형 변수기 때문에
저번 시간에 배운 연산자 오버로딩의 방법을 사용할 수 없다. 그래서 함수의 멤버는 아니지만 private 멤버에 접근할
수 있는 프렌드 함수를 사용해서 이를 해결할 수 있는거야.
/////////////////////////////
// 프렌드 함수
// 만드는 가장 기본적인 규칙
1. 함수 선언 시 프렌드라는 키워드를 앞에 붙이기.

// In 파일 'Overload.h' 에서
(...)
public:
    Time(); 
    Time(int, int); 
    void addHours(int);
    void addMins(int);
    Time operator+(Time&); 
    void show();
    ~Time();
    friend Time operator*(int, Time&); //
    // 1. operator*는 클래스 안에 선언되었지만 멤버 함수가 아니다. 그러므로 지금까지 멤버 연산자의 호출을
    // 위해 사용한 '.'이나 '->' 를 호출할 수 없다.
    // 2. operator 함수는 멤버 함수는 아니지만 동등한 접근권한을 가진다. private에 접근 가능. 
    // 그러니 이제 friend 함수를 정의해보자.
(...)

// In 파일 'learnOO.cpp' 에서
// 우선 멤버 함수가 아니기에 사용 범위 결정 연산자 ::를 사용하지 않고 friend 라는 키워드도 사용하지 않는다.
(...)
void show(); {
    std::cout << "시간 : " << hours << std::endl;
    std::cout << "분 : " << mins << std::endl;
}

Time::~Time() {}

Time operator*(int n, Time& t) {
    Time result;
    long resultMin = t.hours * n * 60 + t.mins * n;
    result.hours = resultMin / 60;
    result.mins = resultMin % 60;
    return result;
} // 이렇게 operator* 를 정의한 후,
(...)

// In 파일 'learnOverloading.cpp' 에서
(...)
int main() {
    Time t1(1, 20);
    Time t2;

    t2 = 3 * t1; // 이는 
//  t2 = operator*(3, t1);  로 해석된다.
    t2.show();
}
(...)
// 출력: 1시간 20분에서 3 곱해져서 3시간 + 60분 = 4시간으로 계산됨
시간 : 4
분 : 0

만약, Line 68에서 
t2 = t1 * 3; 으로 쓰면

Line 36에서 
friend Time operator*(int, Time&); 에서의 
int와 Time&의 순서가 다르므로 출력되지 않음을 알 수 있다.
꼭! 헤더파일에서 정의한 내용과 메인함수의 내용이 일치해야 실행되는 거야.

//////////////////////////

// 그러면 L82의 문제를 어떻게 해결할 수 있을까. 매개변수의 값을 달리 하면서 프렌드 키워드로 operator*를
// 다시 오버로딩하는 방법도 있겠지만 지금은 다른 방법을 쓸거야. 
우선 operator+ 처럼 operator*도 Time의 멤버 함수로써 만들어 줄게.

// In 파일 'Overload.h' 에서
(...)
public:
    Time(); 
    Time(int, int); 
    void addHours(int);
    void addMins(int);
    Time operator+(Time&); 
    Time operator*(int);          //
    // Time 객체가 이 멤버함수를 호출하고 있다고 가정하는 것이므로 매개변수로 int형 변수 하나만 받는다. 
    // 그리고 이것의 구현은 이전에 구현했던 프렌드 함수 구현과 동일할거야.
    void show();
    ~Time();
    friend Time operator*(int, Time&);
(...)

// In 파일 'learnOO.cpp' 에서
(...)

Time::~Time() {}

Time Time::operator*(int n) {              //
    Time result;
    long resultMin = hours * n * 60 + mins * n;
    result.hours = resultMin / 60;
    result.mins = resultMin % 60;
    return result;
}

Time operator*(int n, Time& t) {
    Time result;
    long resultMin = t.hours * n * 60 + t.mins * n;
    result.hours = resultMin / 60;
    result.mins = resultMin % 60;
    return result;
} 
(...)

// 다시 In 파일 'Overload.h' 에서
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
    friend Time operator*(int n, Time& t) { // 또, 프렌드 멤버함수로 정의했던 operator* 를 헤더파일에서
        return t * n; // 인라인 함수로 't * n' 로 정의하게 되면
// friend operator* 가 선언됐을때 t * n 으로 형태가 변환된다. 그리고 t * n 은 Line 138를 통해 연산된다.
    }
    그러면 우리가 
    t2 = 3 * t1; 를 하든
    t2 = t1 * 3; 을 하든 어떠한 경우든 우리가 정의한 프렌드와 오버로딩으로 곱셈 연산이 출력됨을 알 수 있다.
(...)
////////////////////
우리가 처음 정의했던 
friend Time operator*(int n, Time& t) 는 private 변수로 접근이 가능하기에 무조건 앞에 friend 키워드
여야 했지만 지금의 경우에는 private 변수에 직접적인 접근을 하고 있지 않기 때문에 friend로 선언하지 않아도
동일한 결과를 얻을 수 있다. 그럼에도 friend 로 정의하는 것이 바람직한 습관이다. 
그 이유는 L141~144 가 가장 공식적인 인터페이스 이기 때문이다. 
// 인터페이스(Interface) : 특정 기능을 구현할 것을 약속한 추상 형식
// 좁게는 순수 가상 함수만을 갖는 클래스로 정의하며 넓게는 앞으로 프로그램을 어떻게 짤 것인가의 약속으로 정의함.
