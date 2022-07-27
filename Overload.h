#ifndef OVERLOADH
#define OVERLOADH
#include <iostream>

class Time
{
private: // hours와 mins를 멤버로 가지고 있음
    int hours; 
    int mins;

public:
    Time(); // 비어있는 매개변수에 대한 Time 과
    Time(int, int); // 매개변수가 있을 때에 대한 Time을 오버로딩한다.
    void addHours(int);
    void addMins(int);
    Time operator+(Time&); // 덧셈이니까! <수정 후>
 // Time sum(Time&); <수정 전>
    void show();
    ~Time();
};

#endif // !OVERLOADH
