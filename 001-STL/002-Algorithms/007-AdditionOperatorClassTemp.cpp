#include <functional> // for std::plus
#include <iostream>

int main() {
    int x = 5;
    int y = 3;

    std::plus<int> add; // Create an object of std::plus<int> class

    int result = add(x, y); // Call the function object with arguments x and y

    std::cout << "Result of addition: " << result << std::endl; // Output: Result of addition: 8

    return 0;
}
