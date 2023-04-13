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
        return* this;
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
        for (auto& x: m_gems) {
            if (!x.polished) {
                x.polished = true;
                x.shine += 20;
            }
        }
//        auto polish = [](vector<Gem>::iterator beg, vector<Gem>::iterator end) {
//            for (auto x = beg; x != end; x ++) {
//                if (!x->polished) {
//                    x->polished = true;
//                    x->shine += 20;
//                }
//            }
//        };
//
//        auto start = m_gems.begin();
//        auto half = m_gems.size() + (m_gems.size() / 2);
//        auto end = m_gems.end();
//
//        thread t1, t2;
//        t1 = thread(polish, start, half);
//        t2 = thread(polish, half, end);
//        t1.join();
//        t2.join();
    }

    void display() const {
        for (auto& g: m_gems) {
            cout << g.name << endl;
            cout << g.colour << endl;
            cout << g.shine << endl;
            cout << g.polished << endl;
            cout << endl;
        }
    }
};

int main() {
    Box b;
    cout << "\nAdding Gems" << endl;
    b += Gem{"Emerald", "Green", 20, false};
    b += Gem{"Ruby", "Red", 50, true};
    b += Gem{"Sapphire", "Blue", 80, false};
    b += Gem{"Onyx", "Black", 60, false};
    b += Gem{"Opal", "White", 10, false};
    b.display();

    cout << "\nRemoving Gems" << endl;
    try {
        b -= "Ruby";
        b -= "Emerald";
        b -= "Diamond";
        b.display();
    }
    catch (string c) {
        cout << c << endl;
    }

    cout << "\nPolishing Gems" << endl;
    b.process();
    b.display();

    cout << "\nVector of Boxes" << endl;
    vector<Box*> boxes;
    boxes.push_back(new Box());
    boxes.push_back(new Box());
    boxes.push_back(new Box());

    for (auto x : boxes) {
        x->operator+=(Gem{ "Emerald", "Green", 20, false });
        x->operator+=(Gem{ "Ruby", "Red", 90, false });
        x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
    }

    for (auto x : boxes) {
        delete x;
    }

    return 0;
}