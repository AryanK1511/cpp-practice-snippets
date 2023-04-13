#include <iostream>
#include <vector>

int main() {
    /*
    ==================== ITERATORS ====================
     1. Object that points to an element in a sequence
     2. std::vector<double>::iterator iter;
     3. Container classes that do not implement contiguous storage of elements require iterators to access their elements.
     4. We use iterators to insert elements into a sequence or to remove them from a sequence.
        - iterator insert(iterator p, const T& t); inserts t at p
        - void insert(iterator p, size_t n, const T& t); inserts t, n times at p
        - void insert(iterator p, InIter f, InIter l); inserts [f, l) at p
        - iterator erase(iterator p); removed from p
        - iterator erase(iterator f, iterator l); removes [f, l). Returns iterator to next element
    5. The .end() always gets you the element after the last one. It is 0 if there was nothing popped.
    ================================================
    */

    // Creating a vector
    std::vector<double> marks;
    marks.push_back(98.72);
    marks.push_back(87.25);
    marks.push_back(95.23);
    marks.push_back(56.48);
    marks.push_back(94.32);
    marks.push_back(12.56);
    marks.pop_back();
    marks.back() = 23;

    marks.insert(marks.begin(), 21.34);
    marks.erase(marks.begin());

    // Getting the first element
    std::cout << "==========" << std::endl;
    std::cout << "First Element (using .front()): " << marks.front() << std::endl;
    std::cout << "First Element (using .begin()): " << *marks.begin() << std::endl;
    std::cout << "==========\n" << std::endl;

    // Getting the last element
    std::cout << "==========" << std::endl;
    std::cout << "last Element (using .back()): " << marks.back() << std::endl;
    std::cout << "last Element: (using .end()): " << *marks.end() << std::endl;
    std::cout << "==========\n" << std::endl;

    // Looping over the vector and printing each element to the console using a for loop
    for (double mark : marks) {
        std::cout << mark << std::endl;
    }

    // Looping over the vector and printing each element to the console using an iterator
    std::cout << "---------" << std::endl;
    std::vector<double>::iterator iter;
    for (iter = marks.begin(); iter != marks.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    // Looping over the vector and printing each element to the console using an iterator without declaration
    std::cout << "---------" << std::endl;
    for (auto it = marks.begin(); it != marks.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}
