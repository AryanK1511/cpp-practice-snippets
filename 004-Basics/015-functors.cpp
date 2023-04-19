#include <iostream>
using namespace std;

class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Add a;
    int sum = a(2, 3);
    cout << sum << endl;
    return 0;
}