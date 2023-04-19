// Tower of hanoi problem
#include <iostream>
using namespace std;

void hanoi(int n, char pa, char pb, char pc) {
    if (n == 1) {
        cout << "Move from " << pa << " to " << pb << endl;
    } else {
        hanoi(n - 1, pa, pc, pb);
        cout << "Move from " << pa << " to " << pb << endl;
        hanoi(n - 1, pc, pb, pa);
    }
}

int main() {
    hanoi(3, 'A', 'B', 'C');
    return 0;
}