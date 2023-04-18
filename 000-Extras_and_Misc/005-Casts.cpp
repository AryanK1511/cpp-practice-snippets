// Casting
#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void foo() override {
        cout << "Derived class" << endl;
    }
};

int main() {
    cout << "STATIC CAST" << endl;
    int num1 = 10;
    double num2 = static_cast<double>(num1); // Implicit conversion from int to double
    cout << num2 << endl;

    cout << "Dynamic Cast" << endl;
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    basePtr->foo();
    derivedPtr->foo();

    cout << "CONST CAST" << endl;
//    const int n = 10;
//    int n2 = const_cast<int>(n);

    cout << "REINTERPRET CAST" << endl;
    int n = 10;
    void* voidPtr = reinterpret_cast<void*>(&n); // Converting int pointer to void pointer
    cout << voidPtr << endl;

    cout << "C-STYLE CAST" << endl;
    int num11 = 10;
    double num22 = (double) num11;
    cout << num22 << endl;

    return 0;
}