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

-----------------------------------------------------------------------------------------------------
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
    s1.three = 3; // s1은 pulic으로 상속받지만 부모 클래스의 three의 접근 지정자가
                  // protected기 때문에 더 높은 접근 수준을 가진 protected로 상속 받음
    
    return 0;
}

-----------------------------------------------------------------------------------------------------
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
-----------------------------------------------------------------------------------------------------
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
-----------------------------------------------------------------------------------------------------
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

class Daughter : public Parents, public Son {}; // 다중 상속

int main() {
    Daughter d1;
    d1.print(); // 두개의 클래스로 부터 같은 멤버 함수를 상속받아 무엇을 접근 해야할지 몰라 컴파일 오류 발생
    d1.Parents::print(); // 스코프를 통해 어떤 클래스에 접근할지 지정
    d1.Son::print();

    return 0;
}
-----------------------------------------------------------------------------------------------------
#과제 외 프로그램, 사전학습
#include <iostream>
using namespace std;

class Parents {
public:
    void print() {
        cout << "상속" << endl;
    }
};

class Son {
    void print1() {
        cout << "상속1" << endl;
    }
};  
                               
int main() {
    Parents p1;
    Son s1 = p1; // Son의 객체에 Parents의 객체를 복사하려 했으나 자료형이 맞지 않아 오류 발생
    Son s2 = (Son)p1; // 명시적 형변환을 통해 자료형을 Son으로 변경하려 했으나 변환 불가
    return 0;
}
-----------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Parents {

};

class Son : public Parents {
    void print1() {
        cout << "상속1" << endl;
    }
};  
                               
int main() {
    Son s1;
    Son s2;
    Parents p2;

    Parents p1 = s1; // 상속을 통해 부모 클래스 p1객체에 자식 클래스 s1객체를 복사
    Son s2 = p2; // 자식 클래스 s2객체에 부모 클래스 p2객체 복사는 오류 발생

    p1.print1(); // 복사를 했지만 p1에서 자식클래스의 print1 함수를 이용 불가능 
    
    return 0;
}

-----------------------------------------------------------------------------------------------------
#상속과 생성자,소멸자 관계
#include <iostream>
using namespace std;

class Parents {
public:
    Parents() { cout << "Parents 생성자" << endl; }
    ~Parents() { cout << "Parents 소멸자" << endl; }
};

class Son : public Parents {
public:
    Son() { cout << "Son 생성자" << endl; }
    ~Son() { cout << "Son 소멸자" << endl; }
};  
class Test : public Son {
public:
    Test() { cout << "Test 생성자" << endl; }
    ~Test() { cout << "Test 소멸자" << endl; }
};

int main() {
    Parents p1;
    Son s1;
    Test t1;
    return 0;
}

-----------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Parents {
public:
    Parents(int x) { cout << "Parents 생성자" << endl; }
    ~Parents() { cout << "Parents 소멸자" << endl; }
};

class Son : public Parents {
public:
    Son() : Parents(0) { cout << "Son 생성자" << endl; } // 부모 생성자 명시적 호출 : Parents(값)을 통해 부모 생성자를 먼저 호출
    ~Son() { cout << "Son 소멸자" << endl; }
};  

int main() {
    Son s1;
    return 0;
}

-----------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Parents {
public:
    Parents(int x) { cout << "Parents 생성자" << endl; }
    ~Parents() { cout << "Parents 소멸자" << endl; }
};

class Son : public Parents {
public:
    Son(int x, int y) : Parents(x) { cout << "Son 생성자" << endl; } 
    ~Son() { cout << "Son 소멸자" << endl; }
};  

int main() {
    Son s1(0,0); // 객체 생성시 부모 클래스 생성자에 x값 전달
    return 0;
}
-----------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Parents {
public:
    Parents(int x = 0) { cout << "Parents 생성자" << endl; } // 디폴트 파라미터로 값을 미리 전달하여 호출가능
    ~Parents() { cout << "Parents 소멸자" << endl; }
};

class Son : public Parents {
public:
    Son() : Parents() { cout << "Son 생성자" << endl; } 
    ~Son() { cout << "Son 소멸자" << endl; }
};  

int main() {
    Son s1; 
    return 0;
}
-----------------------------------------------------------------------------------------------------
#동적 다형성, 오버라이딩
#include <iostream>
using namespace std;

class Parents {
public:
    virtual void print() {
        cout << "상속" << endl;
    }
};

class Son : public Parents {
public:
     void print() override {
        cout << "오버라이딩" << endl;
    }
};  

int main() {
    Son s1;
    Parents& p1 = s1;
    p1.print();
    return 0;
}
