#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    auto sampleFunc = [&](int c) -> int {
        return a + b + c;
    };
    cout << sampleFunc(30) << endl;
    return 0;
}