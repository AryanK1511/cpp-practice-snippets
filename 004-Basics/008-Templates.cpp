#include <iostream>
#include "Array.h"
using namespace std;
using namespace sdds;

// Class templates
template <typename T, int numberOfElements>
class Array {
private:
    T m_arr[numberOfElements];
public:
    Array() = default;
    Array(T arr[]) {
        for (int i = 0; i < numberOfElements; i++) {
            m_arr[i] = arr[i];
        }
    }
    void display() const {
        for (int i = 0 ; i < numberOfElements; i++) {
            std::cout << m_arr[i] << " ";
        }
    }
};

// Function templates
template <typename T>
void swapElements(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

int main() {
    int x, y;
    cout << "Enter the first number (x): ";
    cin >> x;
    cout << "Enter the second number (y): ";
    cin >> y;

    cout << "Numbers: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    swapElements<int>(x, y);

    cout << "Numbers: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Array<int, 10> arr1(arr);
    arr1.display();

    return 0;
}