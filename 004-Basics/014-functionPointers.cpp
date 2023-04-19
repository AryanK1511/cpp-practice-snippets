#include <iostream>
using namespace std;

void sum(int a, int b) {
    cout <<  a + b << endl;
}

void prod(int a, int b) {
    cout <<  a * b << endl;
}

int main() {
    void (*funcPtr)(int, int);
    funcPtr = sum;
    funcPtr(10, 20);
    funcPtr = prod;
    funcPtr(10, 20);
    return 0;
}