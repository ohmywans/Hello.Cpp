// <공용체, Union>
// 공용체 : 서로 다른 데이터형을 한 번에 한 가지만 보관할 수 있음

#include <iostream>

int main() {

    union MyUnion {

        int intVal;
        long longVal;
        float floatVal;
    };

    MyUnion test;
    test.intVal = 3;
    std::cout << test.intVal << std::endl; // 3 출력
    test.longVal = 33;
    std::cout << test.intVal << std::endl; // 33 출력
    std::cout << test.longVal << std::endl; // 33 출력
    test.floatVal = 3.3;
    std::cout << test.intVal << std::endl; // 알 수 없는 수 출력
    std::cout << test.longVal << std::endl; // 알 수 없는 수 출력
    std::cout << test.floatVal << std::endl; // 3.3 출력
    
    return 0;
}
// 구조체처럼 배열과 달리 공용체는 한 번에 한 가지의 데이터만 보관가능.
// Union은 배열과 달리 여러가지 데이터형을 사용할 수 있지만
// 동시에 사용은 불가함. 장점이라면 메모리 절약이 가능해.
// 구조체만큼의 활용도는 높지 않다.

//////////////////////////////////////////////////////////////////

// <열거체, Enum> : 기호 상수를 만드는 것에 대한 또다른 방법
#include <iostream>

int main() {

    enum spectrum {red, orange, yellow, green, blue, violet,
    indigo, ultreviolet};

    /*
    1. spectrum을 새로운 데이터형 이름으로 만든다.
    2. red, orange, yellow,, 등 0에서부터 7까지 정수 값을 각각
    나타내는 기호 상수로 만든다. (red = 0, ... , indigo = 6, ..)
    */

   spectrum a = orange;
   cout << a << endl; // 1 출력

   // <잘못된 예시>, 열거자끼리의 산술 연산은 불가
   spectrum a = orange + yellow;
   cout << a << endl; // 잘못된 거야.

   int b; 
   b = blue;
   b = blue + 3; // 7이 b에 저장돼.
   cout << b << endl;
// int형 변수에 값을 대입하고자 할 때 열거자들의 값은 int형 정수로
// 계산되어 대입된다.

   enum count {zero = 0, one = 9, two = 51, three, four, five};
// 대입 연산자 '=' 를 사용해서 값을 대입할 수도 있다. 위처럼 값을
// 초기화 하려면 반드시 정수를 가져야 하고,
// 초기화 하지 않은 열거자들은 바로 직전에 초기화한 값보다 1씩 
// 큰 수인 정수를 갖는다. 이를테면, three = 52, four = 53, ...

return 0;

}
   
