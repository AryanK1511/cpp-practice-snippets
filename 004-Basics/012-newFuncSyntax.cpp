#include <iostream>
using namespace std;

template <typename A, typename B>
auto add(A x, B y) -> decltype(x + y) {
    return x + y;
}

int main() {
    double c = add(2, 3.45);
    cout << c << endl;
    return 0;
}