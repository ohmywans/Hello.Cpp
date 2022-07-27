#include "Overload.h"

Time::Time() {

    hours = mins = 0;
}

Time::Time(int h, int m) {

    hours = h;
    mins = m;
}

void Time::addHours(int h) {
    hours += h; // hours은 단순히 더하고
};

void Time::addMins(int m) {
    mins += m; // mins도 단순히 더해주되 
    hours += mins / 60; // mins의 60만큼 나눈 몫을 
    mins %= 60;
};

Time Time::operator+(Time& t); { // sum을 operator+로 바꿈
  // Time Time::sum(Time& t); { // sum은 호출한 객체 Time과 t의 합
    Time sum;
    sum.mins = mins + t.mins;
    sum.hours = hours + t.hours;
    sum.hours += sum.mins /60;
    sum.mins %= 60;

    return sum;
};

void show(); {
    std::cout << "시간 : " << hours << std::endl;
    std::cout << "분 : " << mins << std::endl;
}

Time::~Time() {}
