// <switch, break, continue>

// <Switch 구문>
#include <iostream>
using namespace std;

int main() {
// <예시: 5개의 구문 중 하나를 선택해야 할 때>
    // 1. if else 구문으로 표현           
    if() {                               
    
    } if else() {
    
    } if else() {

    } if else() {

    }
    else {

    }
    // 2. switch 구문으로 표현
    switch (integer-expression) { 
        // switch에 도달하면 표현식의 값을 확인 후 case로 이동   
        // integer-expression에 label4라고 써있으면 label4로 이동하는 방식 
        case label1:
        code#1      break;
        case label2:
        code#2      break;
        case label3:
        code#3      break;
        case label4:
        code#4      break;
        case label5:
        code#5      break;
        default:
        code#6      break;
    }
    // <switch 구문 예시>
    int a;
    cin >> a;
    swtich (a) {
        case 1:
        cout << "입력하신 값은 1입니다.\n";
        break;

        case 2:
        cout << "입력하신 값은 2입니다.\n";
        break;

        case 3:
        cout << "입력하신 값은 3입니다.\n";
        break;

        default:
        cout << "입력하신 값은 1, 2, 3 이외의 다른 값입니다.\n";
        break;
    }
    cout << "switch 구문이 끝났습니다.\n";
// 출력: (사용자 입력, 2) -> 입력하신 값은 2입니다. -> switch 구문이 끝났습니다.
// (사용자 입력, 5) -> 입력하신 값은 1, 2, 3 이외의 다른 값입니다. -> switch 구문이 끝났습니다.

/* 만약 위에 코드에서 break;를 모두 지우고 실행시키면 출력은 다음과 같다.
출력: (사용자 입력, 3) -> 입력하신 값은 3입니다. -> 입력하신 값은 1, 2, 3 이외의 다른 값입니다.
-> switch 구문이 끝났습니다.
즉, break; 를 걸어주지 않으면 switch는 종료하지 않게 되고 끝날때까지 작성된 모든
코드가 출력됨을 알 수 있다. break; 는 모든 반복문에서 사용 가능하다. 아래는 예시
*/
    int i = 0;
    while (true) { // 항상 반복되도록 true를 대입함.
        cout << "i의 값은 " << i << " 입니다." << endl;
        if (i > 10) {
            break;
        } i++;
    }
    cout << "while문이 끝났습니다.\n";
// 출력: i의 값은 0 입니다. , ... , i의 값은 11 입니다. while문이 끝났습니다.
  return 0;
}
///////////////////////////////////////////////////////////////////////////
// <continue 구문: continue 구문을 만났을때 뒤에 나오는 모든 구문이 무시되고 반복이 새로 시작될 수 있도록 하는 구문>
// break 구문: 반복문이나 switch에 사용 가능, continue 구문: only 반복문에서 사용 가능
#include <iostream>
using namespace std;
const int SIZE = 30; // 1. 배열의 크기 30 지정

int main() {
    cout << "문장을 입력하십시오.\n"; // 
    char line[SIZE]; // 2. line이라는 배열 정의
    cin.get(line, SIZE); // 3. 문자열 입력 받기

    cout << "입력하신 문장은\n";
    int spaces = 0;
    for (int i = 0; line[i] != '\0'; i++) { 
        // 4. 개행문자 \0을 만나기 전까지, 즉, 문장의 끝까지
        cout << line[i]; // 5. 그 문장을 출력할 것인데
        
        if (line[i] != ' ') // 7. 그런데 입력받은 배열에 공백이 있다면 
        // continue 구문에 의하여 spaces가 증가하지 않고 for문을 반복하겠다.
        continue;

        spaces++; // 6. 그 문장을 출력할 때마다 spaces를 1씩 증가하겠다.
    }
    cout << "입니다.\n";
    cout << "입력하신 문장에서 공백을 제외한 문자 수는 " << spaces << "개 입니다.\n";
    // 8. 반복이 끝나면 공백을 제외한 문자 수를 spaces에 담아 출력함
    cout << "for문이 끝났습니다.\n";
/* 출력: 문장을 입력하십시오.
입력: p a n d a c o d i n g
입력하신 문장은
p a n d a c o d i n g입니다.
입력하신 문장에서 공백을 제외한 문자 수는 10개 입니다.
for문이 끝났습니다.
*/

}

    
