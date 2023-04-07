#include <iostream>
#include <vector>

int main() {
    /*
    ==================== VECTOR ====================
     1. Can change in size but have elements ordered in sequence.
     2. Store elements in free store and can adjust size.
    ================================================
    */

    // Creating a vector
    std::vector<double> marks;
    marks.push_back(98.72);
    marks.push_back(87.25);
    marks.push_back(95.23);
    marks.push_back(56.48);
    marks.push_back(94.32);
    marks.pop_back();

    // Getting the first element
    std::cout << "==========" << std::endl;
    std::cout << "First Element: " << marks.front() << std::endl;
    std::cout << "==========\n" << std::endl;

    // Getting the last element
    std::cout << "==========" << std::endl;
    std::cout << "last Element: " << marks.back() << std::endl;
    std::cout << "==========\n" << std::endl;

    // Looping over the vector and printing each element to the console
    for (double mark : marks) {
        std::cout << mark << std::endl;
    }


    return 0;
}
