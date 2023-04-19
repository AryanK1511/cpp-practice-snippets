#include <iostream>

class A {
    char a;
    double x1;
    double x2;
};

class B {
    double x2;
    int x1;
    char a;
};

int main() {
    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;

    return 0;
}