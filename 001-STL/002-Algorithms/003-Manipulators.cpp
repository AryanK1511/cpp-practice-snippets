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

    // ==================== MANIPULATORS ====================

    // SORT
    sort(gems.begin(), gems.end(), [](const Gem& gem1, const Gem& gem2) {
        return gem1.shine < gem2.shine;
    });

    // => MERGE
    std::vector<Gem> gems2;
    for (size_t i = 10; i <= 20; i++) {
        gems2.push_back(Gem{"Gem", "Red",(int) (i + 1) * (std::rand() % 10 + 1), true});
    }
    for (auto& gem: gems2) {
        cout << gem.shine << endl;
    }
    cout << "****************" << endl;
    sort(gems2.begin(), gems2.end(), [](const Gem& gem1, const Gem& gem2) {
        return gem1.shine < gem2.shine;
    });

    std::vector<Gem> merged(gems.size() + gems2.size());
    std::merge(gems.begin(), gems.end(), gems2.begin(), gems2.end(), merged.begin(), [](const Gem& gem1, const Gem& gem2) {
       return gem1.shine < gem2.shine;
    });
    for (auto& gem: merged) {
        cout << gem.shine << endl;
    }

    return 0;
}