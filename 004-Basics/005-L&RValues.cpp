#include <iostream>
using namespace std;

double tax = 0.7;

int value() {
    return 10;
}

double& taxValue() {
    return tax;
}

void foo(int& a) {
    a = 234;
}

void display(int& a) {
    cout << "lvalue: " << a << endl;
}

void display(int&& a) {
    cout << "rvalue: " << a << endl;
}

int main() {
    int i;
    int* p;
    i = 6;
    double t;
    p = &i;

//    p = &76; // Requires an lvalue
//    value() = 20;
//    taxValue() = .234;
    double* ptr = &taxValue();
    foo(i);
//    foo(123); // Requires an lvalue

    display(i);
    display(123);
    return 0;
}