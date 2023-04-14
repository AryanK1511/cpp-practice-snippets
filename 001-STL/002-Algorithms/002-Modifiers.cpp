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

    // ==================== MODIFIERS ====================

    // => COPY
    std::vector<int> numsCpy(nums.size()); std::copy_if(nums.begin(), nums.end(), numsCpy.begin(), [](const int& num) {return num > 7;}); auto newSize = std::count_if(numsCpy.begin(), numsCpy.end(), [](const int& num) {return num != 0;}); numsCpy.resize(newSize);

//    std::vector<int> numsCpy; std::copy_if(nums.begin(), nums.end(), back_inserter(numsCpy), [](const int& num) {return num > 7;});

    // => TRANSFORM
    vector<int> numSquares;
    transform(nums.begin(), nums.end(), back_inserter(numSquares), [](const int& num) {
        return num * num;
    });

    // => FILL
    vector<int> fillerArr(10);
    fill(fillerArr.begin(), fillerArr.end(), 4);
    fill_n(fillerArr.begin(), 3, 3);

    // => REPLACE
    replace(fillerArr.begin(), fillerArr.end(), 3, 2);
    replace_if(fillerArr.begin(), fillerArr.end(), [](const int& num) {
        return num % 2 == 0;
    }, 0);
    for (auto& n: fillerArr) {
        cout << n << endl;
    }

    return 0;
}