// 첫번째 주석 : struct.h 로 분할함. 
/*
#include <iostream>

using namespace std;

struct MyStruct 
{
    string name;
    int age;
};

void display(MyStruct&); 
*/

#include "struct.h"
// Line 16 : Line 03 ~ 13의 내용을 잘라내고 struct.h 라는 헤더 파일에 붙여 넣은 후 
// 16번 줄과 같이 #include로 불러오면 원본 파일에 그 내용이 없더라도 실행 시 있었을 때처럼 실행시킬 수 있다.

int main() {
    MyStruct WansCoding = { 
        "Wans",
        26,
    };
    display(WansCoding); 
    return 0;
}
// 두번째 주석 : fun.cpp 로 분할함. 
/*
void display(MyStruct& temp) { 
    cout << "이름 : " << temp.name << endl;
    cout << "나이 : " << temp.age << endl;
}
*/
