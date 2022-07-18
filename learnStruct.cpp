// <<<<<구조체 <struct>, 매우 중요해 >>>>>

#include <iostream>

using namespace std;

int main() {
/*
    // cf. 배열 : 같은 데이터형의 집합
구조체 : 다른 데이터형이 허용되는 데이터의 집합
    // ex : 축구선수 
    string name;     string position;
    float height;    float weight; 
등등 이러한 데이터 모두 하나의 축구선수에 대한 것이므로
이 모두를 아우르려면 구조체를 사용해야 한다.
*/

// ex : 축구선수
// 1. 우리가 입력할 구조체의 변수 이름 지정하기
// 2. 구조체에 담긴 내용(멤버)을 중괄호로 묶어 정의하기

struct learnStruct 
{ 
  // <멤버>
   string name;
   string position;
   float height;    
   float weight; 
};

// 이렇게 구조체로써 learnStruct를 지정해두면 이를 변수처럼 사용할 수 있다.
// <정의하는 방식 1>
learnStruct A; // ' (구조체 이름) (지정할 변수); ' 로 불러오고
A.name = "Son"; // ' (지정할 변수).(지정할 멤버) = (정의); ' 로 개별적으로 정의 가능.
A.position = "Striker";
A.height = 183;
A.weight = 77;

// 구조체란 사용자가 정의한 새로운 데이터형을 만드는 것. 구조체를 선언하면서 값을 대입
// 하는 초기화의 방식을 사용한다.

// <정의하는 방식 2> 이렇게 해도 위와 동일한 출력
learnStruct A = {
    "Son",
    "Striker",
    183, 
    77
};

cout << A.name << endl;
cout << A.position << endl;
cout << A.weight << endl;
cout << A.height << endl;

// <위는 기본적인 원리와 표현방법이고 여기는 조금 다르게 표현하는 방법>
struct MoreStruct
{
    string name;
    string position;
    float weight;
    float height;
} B; // 중괄호 뒤에 변수이름을 미리 지정!

MoreStruct B = {
    // 따로 지정하지 않으면 전부 0으로 저장됨
};

cout << B.height << endl; // 0으로 출력

////////////////////////////////////////////////////////////////////////

// <<<<<구조체를 배열로 선언하기>>>>>
    struct OtherStruct {
        string name;
        string position;
        float weight;
        float height;
    };


    learnStruct A[2]; { // (구조체로 사용할 변수 이름) (지정할 변수)[배열의 크기];

       {"A", "C", 1, 3},
       // 한 번 더 중괄호를 열어서 배열의 첫번째 index에 해당할 원소의 값을 대입

       {"B", "D", 2, 4} 
       // 두번째 index에 해당할 원소 대입
    };

    cout << A[0].height << endl; 
    // [0]은 첫번째 index를 의미, height는 위에서 
    // 4번째에 정의되어 있으므로, 출력값은 3 이 된다.



    return 0;
}

    
