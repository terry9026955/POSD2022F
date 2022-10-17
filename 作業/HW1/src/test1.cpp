// 練習用
#include <iostream>
using namespace std;

class P {
public:
    virtual void print(){
        cout << "gg" << endl;
    }
    ~P(){}
};

class A : public P{
public:
    A(){}
    ~A(){}
    void print() override {
        cout << "aaaaa" << endl;
    };
};

class B : public P {
public:
    B(){}
    ~B(){}
    void print() override {
        cout << "bbbbb" << endl;
    }
};

int main() {
    P* classA = new A;
    P* classB = new B;
    classA->print();    // aaaaa
    classB->print();    // bbbbb
}