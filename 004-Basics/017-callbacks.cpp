#include <iostream>
using namespace std;

void forEach(int arr[], void (*funcPtr)(int)) {
    for (int i = 0; i < 10; i++) {
        funcPtr(arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    forEach(arr, [](int value) {cout << value << endl;});
    return 0;
}