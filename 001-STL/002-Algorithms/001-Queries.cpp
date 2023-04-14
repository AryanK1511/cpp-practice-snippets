#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    std::vector<int> nums;
    for (size_t i = 0; i < 10; i++) {
        nums.push_back((int) i + 1);
    }
    for (auto& num: nums) {
        cout << num << endl;
    }
    cout << "****************" << endl;

    // ==================== Queries ====================

    // => all_of (any_of, none_of)
    bool greaterThan5 = all_of(nums.begin(), nums.end(), [](const int& num) {return num > 5;}); if (!greaterThan5) { cout << "All elements are not greater than 5" << endl; }

    // => for_each
    for_each(nums.begin(), nums.end(), [](const int& num) {cout << num << endl;});

    // => FIND / FIND IF: finds first element
    auto foundElem = std::find_if(nums.begin(), nums.end(), [](const int& n) { return n % 2 == 0;});cout << "First Even Number: " << *foundElem << std::endl;

    // => COPY
    std::vector<int> numsCpy(nums.size());
    std::copy_if(nums.begin(), nums.end(), numsCpy.begin(), [](const int& num) {return num > 7;});
    auto newSize = std::count_if(numsCpy.begin(), numsCpy.end(), [](const int& num) {
        return num != 0;
    });
    numsCpy.resize(newSize);

    for (auto& num: numsCpy) {cout << num << endl;}

    return 0;
}