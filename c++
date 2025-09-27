#include <iostream>
using namespace std;

class Parents {
public:
    void print() {
        cout << "상속" << endl;
    }
};

class Son : public Parents {}; // 상속의 기본형태
                               // 부모 클래스로 부터 모든 멤버를 public으로 상속받음

int main() {
    Son s1;
    s1.print(); // 자식 클래스에서 상속 받은 print함수 호출
    
    return 0;
}
