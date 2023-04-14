#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <string>
using namespace std;

struct Gem {
    std::string name;
    std::string colour;
    int shine;
    bool polished;
};

class Box {
private:
    std::vector<Gem> m_gems {};
public:
    Box() = default;

    Box& operator+=(const Gem& gem) {
        m_gems.push_back(gem);
        return *this;
    };

    Box& operator-=(const string& name) {
        size_t curSize = m_gems.size();
        auto itr = std::remove_if(m_gems.begin(), m_gems.end(), [=](const Gem& g) {
            return g.name == name;
        });
        m_gems.resize(itr - m_gems.begin());

        if (m_gems.size() == curSize) {
            throw std::string("No such gem found");
        }

        return *this;
    }

    void process() {
        transform(m_gems.begin(), m_gems.end(), back_inserter(m_gems), [](Gem& gem) {
            if (!gem.polished) {
                gem.polished = true;
                gem.shine += 20;
            }
            return gem;
        });
    }

    void display() const {
        for (auto& g: m_gems) {
            cout << g.name << " | " << g.colour << " | " << g.shine << " | " << g.polished << endl;
        }
    }
};

int main() {
    Box b;
    cout << "========== Adding Gems ==========" << endl;
    b += Gem{"Emerald", "Green", 20, false};
    b += Gem{"Ruby", "Red", 50, true};
    b += Gem{"Sapphire", "Blue", 80, false};
    b += Gem{"Onyx", "Black", 60, false};
    b += Gem{"Opal", "White", 10, false};
    b.display();
    cout << "=================================\n" << endl;

    cout << "========== Removing Gems ==========" << endl;
    try {
        b -= "Ruby";
        b -= "Emerald";
        b -= "Diamond";
        b.display();
    }
    catch (string c) {
        cout << c << endl;
    }
    cout << "===================================\n" << endl;

    cout << "========== Polishing Gems ==========" << endl;
    b.process();
    b.display();
    cout << "====================================\n" << endl;

    cout << "========== Vector of Boxes ==========" << endl;
    vector<Box*> boxes;
    boxes.push_back(new Box());
    boxes.push_back(new Box());
    boxes.push_back(new Box());

    for (auto x : boxes) {
        x->operator+=(Gem{ "Emerald", "Green", 20, false });
        x->operator+=(Gem{ "Ruby", "Red", 90, false });
        x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
    }

    for (auto& x: boxes) {
        x->display();
    }
    cout << "=====================================" << endl;

    for (auto x : boxes) {
        delete x;
    }

    return 0;
}