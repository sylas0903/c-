#상속의 기본형태
#include <iostream>
using namespace std;

class Parents {
public:
    void print() {
        cout << "상속" << endl;
    }
};

class Son : public Parents {}; // 상속의 기본형태 :(상속 접근 지정자) (부모 클래스 이름)
                               // 부모 클래스로 부터 모든 멤버를 public으로 상속받음

int main() {
    Son s1;
    s1.print(); // 자식 클래스에서 상속 받은 print함수 호출
    
    return 0;
}


#상속 접근지정자에 따른 상속
#include <iostream>
using namespace std;

class Parents {
public:
    int one;
private:
    int two;
protected:
    int three;
public:
    void print() {
        cout << "상속" << endl;
    }
private:
    void print1() {
        cout << "상속" << endl;
    }
protected:
    void print2() {
        cout << "상속" << endl;
    }
};

class Son : public Parents { // 부모 클래스의 멤버를 public으로 받음
public:
    void check() { 
        one = 1; // 부모 클래스의 접근 지정자가 public, 접근 가능
        two = 2; // 부모 클래스의 접근 지정자가 private, private는 같은 클래스 내부에서의 접근만 허용하기 때문에 접근 불가
        three = 3; // 부모 클래스의 접근 지정자가 protected, 자식 클래스와 자식클래스를 상속받는 클래스까지 접근 가능
    }
}; 
                               
class Daughter : private Parents {
public:
    void check() {
        one = 1; 
        two = 2;
        three = 3;
    }
};

class Brother : protected Parents {
public:
    void check() {
        one = 1;
        two = 2;
        three = 3;
    }
};

class Sister : public Son {
public:
    void check() {
        three = 3; // Parents의 자식 클래스 Son을 상속받아서 Parents의
                   // protected 멤버 변수 three에 간접 접근 가능
    }
};

int main() {
    Son s1;
    Daughter d1;
    Brother b1;
    Parents p1;
    
    // 상속 접근 지정자
    s1.three = 3; // s1은 pulic으로 상속받음, 하지만 부모 클래스의 three의 접근 지정자가
                  // protected기 때문에 더 높은 접근 수준을 가진 protected로 상속 받음
    
    return 0;
}


#다중 상속
#include <iostream>
using namespace std;

class Parents {
public:
    void print() {
        cout << "상속" << endl;
    }
};

class Son { 
public:
    void print() { 
        cout << "상속1" << endl;
    }
};  
                               
class Daughter : public Parents , public Son{ }; // 다중 상속

int main() {
    Daughter d1;
    d1.Parents::print(); // Parents, Son 두개의 클래스를 상속받아 Parents, Son의 멤버를 둘다 사용가능
    d1.Son::print();

    return 0;
}

#다단계 상속
#include <iostream>
using namespace std;

class Parents {
public:
    void print() {
        cout << "상속" << endl;
    }
};

class Son : public Parents{ 
public:
    void print() { 
        cout << "상속1" << endl;
    }
};  
                               
class Daughter : public Son{ }; // Parents를 상속받은 Son을 Daughter에 상속하여 Parents,Son의 멤버 모두 사용가능

int main() {
    Daughter d1;
    d1.Parents::print(); 
    d1.Son::print();

    return 0;
}
