/*
Given the following struct that describes a Gem,

1.  struct Gem {
2.    string name;
3.    string colour;
4.    int shine;
5.    bool polished;
6.  };
 

Create a Box class has the following properties:

An STL container of Gems as a data member
A += operator that adds Gems to the box
A -= operator that removes Gems from the Box based on a given string (name) to search for. If the string is found then remove any Gems that match. If there isn’t a match at all then throw an exception of string type with a relevant error message
A function called process that doesn’t receive any parameters nor returns any value. This function will iterate through the Gems in the Box and polish them if they aren’t yet polished. Polishing a Gem will cause its shine value to increase by 20. For this functionality incorporate the use of threads to divide the work.
A display function that displays the contents of the box
The following main will use the Box class:

1.  int main() {
2.    Box b;
3.   
4.    cout << "\nAdding Gems" << endl;
5.    b += Gem{"Emerald", "Green", 20, false};
6.    b += Gem{"Ruby", "Red", 50, true};
7.    b += Gem{"Sapphire", "Blue", 80, false};
8.    b += Gem{"Onyx", "Black", 60, false};
9.    b += Gem{"Opal", "White", 10, false};
10.     b.display();
11.    
12.     cout << "\nRemoving Gems" << endl;
13.     try {
14.       b -= "Ruby";
15.       b -= "Emerald";
16.       b -= "Diamond";
17.       b.display();
18.     }
19.     catch (string c) {
20.       cout << c << endl;
21.     }
22.    
23.     cout << "\nPolishing Gems" << endl;
24.     b.process();
25.     b.display();
26.    
27.    
28.     cout << "\nVector of Boxes" << endl;
29.     vector<Box*> boxes;
30.     boxes.push_back(new Box());
31.     boxes.push_back(new Box());
32.     boxes.push_back(new Box());
33.    
34.     for (auto x : boxes) {
35.       x->operator+=(Gem{ "Emerald", "Green", 20, false });
36.       x->operator+=(Gem{ "Ruby", "Red", 90, false });
37.       x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
38.     }
39.    
40.     for (auto x : boxes) {
41.       delete x;
42.     }
43.   }
 

As an extra task, modify the Box class to instead have a container of Gem pointers and apply the use of smart pointers to the solution.
*/

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