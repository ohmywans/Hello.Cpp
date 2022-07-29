// Public 다형 상속 에서 '다형'과 Virtual 에 대해 알아보자
(...)
class Time
{
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
	void show();           // <수정 전>
//  virtual void show();      <수정 후>
	~Time();           // <수정 전>
//  virtual ~Time();      <수정 후>
//  int getHour() { return hours; } <새롭게 추가된 코드>
//  int getMins() { return mins; } <새롭게 추가된 코드>
	friend Time operator*(int n, Time& t) {
		return t * n;
	}
	friend std::ostream& operator<<(std::ostream&, Time&);
};

class NewTime : public Time {
private:
	int day;
public:
	NewTime();
	NewTime(int, int, int);
	void print(); // <수정 전>
  //void show();     <수정 후>
}; (...)
// <내용이 든 함수에서>
void NewTime::show() { // print -> show로 바꿈
    std::cout << "일 : " << days << std::endl;
//  std::cout << "시간 : " << days << std::endl;
//  std::cout << "분 : " << days << std::endl;
    show(); }
(...)
/*
void show(L16)가 Time 객체에 의해 호출된다면 hours, mins를 출력할 것이고, 
             NewTime 객체에 의해 호출될 때, days, hours, mins를 출력하면 좋을 것이다. 그래서 
이렇게 처해지는 상황에 따라서 다른 동작을 하는 것을 다형이라고 한다. 
public 다형을 위해서는 
1. 기초 클래스 메소드를 파생 클래스에서 다시 정의해야 한다. 
- print 대신 show를 상속받아서 사용할 예정이므로 print를 없애고 show를 재정의할게(L34).
2. 가상 메소드를 사용해야 한다.
- 가상 메소드의 경우는 기초 클래스에서 virtual 키워드를 붙여주는 것으로 선언할 수 있다.(L17)
- 함수의 이름이 바뀌었으니 함수도 바꿔야겠지.(L37, 자세한 설명 추가: 수정한 show()가 L39의 show
로 가면 재귀함수로 빠지게 되겠지. 근데 우리는 "일 : "뿐만 아니라 시간과 분도 출력해야 되는데 L37의
show()는 NewTime에 속해있는 클래스이므로 Time의 private 영역에 접근할 수 없다. 그래서 Time에서
시간과 분을 호출할 수 있도록 public 영역에 함수를 만들어서 호출하는 방법으로 해결한다. )
L19,20,39,40
*/
// <메인 함수 수정하기>
#include <iostream>
#include "Overload.h"

using namespace std;

int main() {
    Time temp1(30, 2);
    NewTime temp2(3, 30, 2);

    temp1.show(); // temp1은 Time 객체이고 (시간, 분)
    temp2.show(); // temp2는 NewTime 객체이다. (일, 시간, 분)

    return 0;
} /* 출력 : 
시간 : 30
분 : 2
일 : 2
시간 : 3
분 : 30
/* 이것이 가능한 이유 : 'virtual void show();' 의 virtual 때문인데 앞에 virtual이 붙으면 
void show()는 가상 메소드가 된다. 가상 메소드는 프로그램에게 독립된 두 개의 메소드 정의가 있음을
알려주게 된다. 그렇게 되면 프로그램은 show라는 함수가 호출될 때 이 것을 호출한 클래스의 객체를
따져서 그에 대응되는 함수를 선택하게 됨. 그래서 show라는 함수가 virtual을 통해 가상 메소드로 정의
되어 있기 때문에 Time 객체 클래스에서 호출하든, NewTime 객체에서 호출하든 그에 상응되는 show()가
사용된 것이다. 가상 메소드를 사용할 때 알아야 할 사안이 있다.
1. 기초 클래스에서 가상 메소드를 선언하면,
그 함수는 기초 클래스 및 파생되는 클래스 모두에서 모두 가상이 된다. 
2. 객체에 대한 참조를 사용하거나, 객체를 지시하는 포인터를 사용하여 가상 메소드가 호출되면 참조나
포인터를 위해 정의된 함수가 사용되지 않고 객체을 위해 정의된 메소드를 사용한다. > 동적 결합 이라 부름
3. 상속을 위해 기초 클래스로 사용할 클래스를 정의할 때, 
파생 클래스에서 다시 정의해야 되는 클래스 함수는 가상 함수로 선언해야 한다.
*/
///////////////////////////////////////////////////////////////////////////////////////////
// <class 배열 선언과 동적 결합>
#include <iostream>
#include "Overload.h"
using namespace std;

int main() {
    Time t1;
    NewTime t2;

    return 0;
}
 /* 여러 개의 Time 객체와 NewTime 객체를 혼합해서 관리하고자 할 때, 하나의 배열로써 관리하면
 효과적이겠지만 원론적으로 불가능하다. 하지만, Time을 지시하는 포인터들은 만들 수 있다. 왜냐하면,
 Time과 NewTime은 public 상속 모델이 적용되어 있고 Time을 지시하는 포인터가 Time 객체와 NewTime
 객체 모두 지시할 수도 있기 때문이다. 그래서 Time을 지시하는 포인터들의 배열을 만든다면 같은 데이터형
 으로 이루어진 원소로써 Time 객체와 NewTime 객체가 혼합된 배열을 만들 수 있다. 다음 코드 참조
 */
#include <iostream>
#include "Overload.h"
using namespace std;

const int MAX = 3;

int main() {
    Time* times[MAX]; // times에 대한 포인터로 배열을 만듬.
    int days;
    int hours;
    int mins;

for (int i = 0; i < MAX; i++) {
		cout << i + 1 << "번째 원소를 정의합니다." << endl;
		cout << "시간을 입력하십시오." << endl;
		cin >> hours;
		cout << "분을 입력하십시오." << endl;
		cin >> mins;
		char check;
		cout << "일 정보가 있다면 1, 없다면 0을 입력하십시오." << endl;
		cin >> check;
		if (check == '0')
			times[i] = new Time(hours, mins);
		else {
			cout << "일을 입력하십시오." << endl;
			cin >> day;
			times[i] = new NewTime(hours, mins, day);
		}
	}

	for (int i = 0; i < MAX; i++) {
		cout << i + 1 << "번째 정보입니다." << endl;
		times[i]->show(); 
/* times에 저장된 show가 아니라 times[i]에 NewTime 객체가 저장되어 있다면 NewTime 객체에
대응되는 show가 동작한 것을 확인할 수 있다. 그래서 virtual 함수를 사용할 때 메소드가 객체에 의해 호출되지 않고 참조나 포인터에 의해
호출되었을 때 어느 메소드를 사용할지 결정하는 것을 확인할 수 있다. 지금도 times[i]는 Time*에 해당
하는 포인터 배열이지만 배열의 원소에 NewTime이 저장되어 있는 경우에는 NewTime에 대응되는 show()가
동작한 것을 확인할 수 있다.  

*/
	}
    /* 여기까지 출력:
    1번째 원소를 정의합니다.
    시간을 입력하십시오.
    (사용자 입력) 1
    분을 입력하십시오.
    (사용자 입력) 20
    일 정보가 있다면 1, 없다면 0을 입력하십시오.
    (사용자 입력) 0
    2번째 원소를 정의합니다.
    시간을 입력하십시오.
    (사용자 입력) 1
    분을 입력하십시오.
    (사용자 입력) 10
    일 정보가 있다면 1, 없다면 0을 입력하십시오.
    (사용자 입력) 1
    일을 입력하십시오.
    (사용자 입력) 2
    3번째 원소를 정의합니다.
    시간을 입력하십시오.
    (사용자 입력) 2
    분을 입력하십시오.
    (사용자 입력) 40
    일 정보가 있다면 1, 없다면 0을 입력하십시오.
    (사용자 입력) 0
    1번째 정보입니다.
    시간 : 1
    분 : 20
    2번째 정보입니다.
    일 : 2
    시간 : 1
    분 : 10
    3번째 정보입니다.
    시간 : 2
    분 : 40
    */
// Line 131, 135에서 new 를 사용했으니 당연히 delete도 사용해야겠지.
	for (int i = 0; i < MAX; i++) {
		delete times[i];
    }  
/* delete를 통해 메모리를 해제할때 times[i]에 해당하는 파괴자가 호출될 것이다. 그런데 여기서의 
문제는, Line 187는 항상 Time 객체에 대한 파괴자만 호출이 될 것이라는 거야. 만약, times[i]에 
NewTime 객체가 저장되어 있다면 Time 파괴자가 호출되었으므로 적당한 효력을 발휘하지 못하겠지. 이를
위해 Time에 저장되어 있는 파괴자 역시 Virtual로 선언할 필요가 있겠다. (Line 18,19처럼!)
(...)
line 18 ~Time();            <수정 전>
line 19 virtual ~Time();    <수정 후> (...)
이 ~ 를 가지고 있는 파괴자는 기본 함수기 때문에 NewTime에서 굳이 정의하지 않아도 동작할 것이고 
virtual로 선언하게 된다면 ~Time 파괴자가 호출될 때 비록 Time 객체에 대한 파괴자라 할지라도
만약 거기에 저장된 정보가 NewTime 객체라면 이 객체에 대한 파괴자가 호출되어 동작할 것이다.
*/

    return 0;
}

/*
이렇게 delete까지 마무리하면 원형 클래스 Time의 포인터 Time*로써 배열인 times[MAX]를 만들고
파생 클래스의 원소까지 저장하는 것을 확인할 수 있다. 그리고 그 저장된 원소들은 각각 원형 클래스의
포인터의 배열이라 할지라도 그 배열에 담긴 객체에 따라서 가상함수가 잘 동작하는지 까지 확인했다.
*/
