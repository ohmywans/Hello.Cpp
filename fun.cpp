#include "struct.h"
 // 해당 파일에서의 내용을 같이 쓰고 있으니까 include로 불러와야 한다.
 
void display(MyStruct& temp) { 
    cout << "이름 : " << temp.name << endl;
    cout << "나이 : " << temp.age << endl;
}
