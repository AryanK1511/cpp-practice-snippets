#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct Gem {
    std::string name;
    std::string colour;
    int shine;
    bool polished;
};

int main() {
    std::vector<Gem> gems;
    for (size_t i = 0; i < 10; i++) {
        gems.push_back(Gem{"Gem", "Red",(int) (i + 1) * (std::rand() % 10 + 1), true});
    }
    for (auto& gem: gems) {
        cout << gem.shine << endl;
    }
    cout << "****************" << endl;

    // ==================== Numeric ====================

    // => ACCUMULATE
    auto sumOfShine = accumulate(gems.begin(), gems.end(), 1, [](size_t sum, const Gem& gem) {
        return sum += gem.shine;
    });

    // => INNER PRODUCT
    
    // => PARTIAL SUM

    return 0;
}