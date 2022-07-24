// 함수 : 하나의 특별한 목적의 작업을 수행하기 위해 독립적으로 설계된 코드의 집합.
// 호출한 함수에게 값을 되돌려주는, return value가 있는 함수와 없는 함수로 분류함.
// 선행 작업 3가지
/*
1. 함수 정의 제공
2. 함수 원형 제공
3. 함수 호출
- iostream 이라는 라이브러리 안에 여러 함수들에 대한 정의와 원형이 포함되어 있어서
지금까지 함수를 호출만으로도 쉽게 사용할 수 있었던 것!

<함수의 구분>, 리턴값 : 자신을 호출한 함수에게 되돌려주는 값, main 함수라면 main 함수에 리턴하는 것!
1. 리턴값이 있는 타입(아래는 기본 형태)
typeName functionName(parameterList) {
    statement(s);
    return value;
}
- 함수의 이름을 명시하기 앞서서 어떤 데이터형을 사용할지(typeName) 선언해야 한다.
또한, value 역시 함수의 데이터형과 일치되어야 한다. typeName이 int였다면 value 역시 int
여야 한다. C++에서는 배열을 제외한 모든 데이터형을 리턴할 수 있다. 물론 배열 역시 
구조체나 객체의 일부로 정의된다면 리턴할 수 있다.

2. 리턴값이 없는 타입 : 되돌려주는 값이 없으므로 어떤 종류의 행동을 수행하는 함수
void functionName(parameterList) {
    statement(s);
    return; // 생략될 수 있음
}
- 함수의 이름 앞에 함수의 타입 이름으로 void를 명시한다. 이는 리턴값이 없는 경우에만
해당되며 이 때, return 뒤에 특정한 value를 삽입하지 않아야 하고 return;도 생략할 수 있
으므로 굳이 쓰지 않고서 해당 함수를 마무리할 수 있다.

- parameterList : 호출하는 함수에게서 함수에 사용될 구문인 {}에 필요한 정보를 넘겨줌
*/
#include <iostream>

using namespace std;
// <<함수의 원형 명시>>
const float PIE = 3.14;
void cheers(int n);
float circle(int x);

// <<main 함수를 구성>>
int main() {
    int a;
    cout << "하나의 수를 입력하십시오." << endl;
    cin >> a;
    cheers(a);
// 4. 하나의 변수를 받아 cheers에 전달하게 되고,
    int b;
    cout << "원의 반지름 길이를 입력하십시오." << endl;
    cin >> b;
// 5. 반지름 길이를 받아 circle 함수에 넘겨준 후,
    float c = circle(b);
    cout << "원의 넓이는 " << c << " 입니다." << endl;
}
// 6. 그 리턴 value를 float c에 저장하여 이를 출력함으로써 main 함수는 끝난다.

// <<함수의 원형에 대한 내용 정의>>
void cheers(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Cheers!" << endl;
    } // 1. return; 을 생략해도 무방! 리턴값이 없는 함수니까
}
// 2. cheers 함수는 호출한 함수로부터 int형 변수를 담고 변수를 반복문에 사용하여 변수의 크기
// 만큼 cheers를 출력하는 함수이다.

float circle(int x) {
    return x * x * PIE;
}

// 3. circle 함수는 호출한 함수로부터 int형 변수 하나를 담고 원의 넓이를 리턴하는 함수이다.
// PIE는 main 함수 위에 3.14로 정의되어 있는데 소수점으로 나올 수 있으므로 float으로 선언함.
// 고로 typeName으로 float, value로는 x * x * PIE이므로 이를 같게 해줌을 알 수 있다. 

/* 출력
하나의 수를 입력하십시오.
(사용자 입력) 3
Cheers!
Cheers!
Cheers!
원의 반지름 길이를 입력하십시오.
(사용자 입력) 5
원의 넓이는 78.5 입니다.
*/
// 함수를 사용하려면 미리 정의되어 있어야 한다.

////////////////////////////////////////////////////////////////////////////////
// 1. 값으로 전달하기 (매개변수<parameter>, 전달인자<argument>)
#include <iostream>
using namespace std;

void helloCPP(int, int); // int, int 가 여기서 parameter로 쓰임
// 매개변수, parameter : 함수를 호출할 때 쓰이는 변수, 1개 이상 다룰 수 있다.
int main() {

    int times, times2; // 실제 호출할 때는 argument다!

    cout << "정수를 입력하십시오.\n";
    cin >> times;

    cout << "정수를 한번 더 입력하십시오.\n";
    cin >> times2;

    helloCPP(times, times2);

    return 0;
}
// 이 함수를 호출한 main 함수에게 어떠한 결과를 돌려주지 않고 단순히 출력만 반복할 것
// 기 때문에 void 형태로 호출한다.
void helloCPP(int n, int m) { 
    // for문에서만 쓰일 변수 n,m을 만들어냈고 이는 times, times2가 일대일로 대응된다.

    for (int i = 0; i < n; i++) 
        cout << "Hello!\n";
    
    for (int i = 0; i < m; i++)
        cout << "C++\n";
}
/*출력
정수를 입력하십시오.
(사용자 입력) 5
Hello C++!
Hello C++!
Hello C++!
Hello C++!
Hello C++!

즉, 여기서 int형으로 쓰인 n과 m을 매개변수, parameter 라 하고,
 실제로 함수를 호출할 때 사용된 변수들인 times, times2와 같은 것을 전달인자, argument라고 한다.
*/

///////////////////////////////////////////////////////////////////////////////////
// 2. 함수로 배열 관리하기(시작주소와 크기 전달, 시작주소와 끝주소를 전달)

// - 시작주소와 크기 전달
#include <iostream>
// <배열에 저장되어 있는 값을 모두 출력하는 함수를 만들어볼게>
using namespace std;

const int SIZE = 8; // 1. 배열의 크기를 8로 정의하고,

int sumArr(int[], int);

int main() {
    
    int arr[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128}; // 2. 8에 대한 배열을 선언한 뒤
    int sum = sumArr(arr, SIZE); // 3. 이 배열과 배열의 크기를 알려주어 int형 변수를 반환하는 sumArr라는 함수

    cout << "함수의 총 합은 " << sum << " 입니다.";
    return 0;
}

int sumArr(int arr[], int n) { // 4. sumArr라는 함수는 배열과 그 배열의 사이즈를 받아서
    
    int total = 0;

    for (int i = 0; i < n; i++) // 5. for문을 통해 배열의 인덱스를 0부터 사이즈보다 작을 때까지 순회하고
    total += arr[i]; // 6. total 이라는 변수에 저장하고 (total = total + arr[i]라는 뜻)

    return total; // 7. return을 통해 이 변수를 main함수에 리턴
}
// 출력: 함수의 총 합은 255 입니다.
/* arr는 배열이 아니라 사실 "포인터" 라는 점을 주목해야 한다. 그럼에도 이 코드가 제대로 동작할 수 있었던
이유는 C++에서 배열이름을 그 배열에 첫번째 원소의 주소로 인식한다는 점 때문임.
Line 144 : arr == &arr[0] : arr의 첫번째 원소의 주소로 인식
따라서 Line 151의 sumArr는 주소로 인식된다는 것

고로, 해당 코드를 더 원론적으로 수정하면 다음과 같다.
*/

int sumArr(int*, int);

int main() {
    
    int arr[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128}; 
    // arr ==&arr[0] : 배열의 이름이 배열의 첫번째 원소의 주소를 가리킨다는 것이 헷갈리면
    // 다음과 같이 변수가 차지하고 있는 공간을 출력하는 것으로 이해해도 된다. (L176,186)
    cout << "size of arr " << sizeof arr << endl;
// 출력 : size of arr 32 <{1, 2, 4, 8, 16, 32, 64, 128}인 배열 전체의 크기를 의미>
    int sum = sumArr(arr, SIZE); 

    cout << "함수의 총 합은 " << sum << " 입니다.";
    return 0;
}

int sumArr(int* arr, int n) { 

    cout << "size of arr " << sizeof arr << endl;
// 출력 : size of arr 4 <'int* arr'인 배열의 첫번째 원소의 크기를 의미>
    int total = 0;

    for (int i = 0; i < n; i++) 
    total += arr[i];
// C++에서 배열의 원소에 접근하는 대괄호[]는 배열이든 포인터든 전부 사용가능 하므로
// 이렇게 변경해도 아무 문제 X


/* SIZE 대신 8보다 작은 값을 sumArr에 전달하게 된다면 그 값만큼 for문에서 반복하고 결과를 리턴함
함수를 통해서 배열을 관리할 때 그 배열의 첫번째 원소의 주소와 배열의 크기를 전달해주는 방법도 있지만
배열을 시작하고자 하는 주소와 끝내고자 하는 주소를 알려주는 방법으로도 코딩할 수 있다.
*/

    return total; 
}
// - 시작주소와 끝주소를 전달하는 방법

#include <iostream>

using namespace std;

const int SIZE = 8;

int main() {

    int arr[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sumArr(arr, arr+SIZE);
    cout << "함수의 " << SIZE << "까지의 합은 "<< sum << " 입니다.\n";

    sum = sumArr(arr, arr + 3);
    cout << "함수의 " << "세번째 인덱스까지의 합은 " << sum << " 입니다.\n";

    return 0;
}

int sumArr(int* begin, int* end) { 
// 배열의 시작주소와 끝주소를 알려주는 방법으로도 이전과 동일한 기능을 하는 함수를 만들 수 있다.

    int total = 0;
    int* pt;

    for (pt = begin; pt != end; pt++) 
// 1. 포인터에는 시작주소를 두고 1씩 증가시키는데 끝주소와 같아지면 반복이 멈추도록 함
    total += *pt;
// 2. total에는 포인터가 가진 수를 누적하여 저장하도록 하고  

    return total;
// 3. return total; 을 하게되면 L225에서 명시한 시작주소부터 끝주소까지의 배열의 값을 리턴
}
/* 출력:
함수의 8까지의 합은 255입니다.
함수의 세번째 인덱스까지의 합은 7 입니다.
*/
