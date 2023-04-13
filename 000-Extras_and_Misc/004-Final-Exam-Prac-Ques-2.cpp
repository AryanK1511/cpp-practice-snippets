/*
 Given the following code snippet, complete the tasks listed below:

1. #include <iostream>
2. #include <string>
3. #include <algorithm>
4. #include <numeric>
5. #include <vector>
6. using namespace std;
7.  
8. struct ComputerParts {
9.   string partType;
10.   string model;
11.   double price;
12.   double powerConsumption;
13.   bool used;
14. };
15.  
16. int main() {
17.  
18.   vector<ComputerParts> wishList;
19.  
20. } 
Task 1. Add to the wishLish some number of desired Computer Parts 
Eg. GPU, RTX 3080, 1000, 300, false

Task 2. Sort the wishList by price in ascending order

Task 3. Print to the screen the part in the wishList the part that has the most and least powerConsumption

Task 4. Remove from the wishList all the parts that are 'used'

Task 5. Find the average cost of all the parts in the wishList

Task 6. Change all the items in the wishList to 'used' and reduce their price by 20% and save this result to a new vector

Task 7. Figure out how many of a given part type is in the wishList eg. how many CPUs and print to the screen

Task 8. Create new wishList of computer parts and add parts to it. Combine it with the original wishList
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct ComputerParts {
    string partType;
    string model;
    double price;
    double powerConsumption;
    bool used;
};

int main() {
    vector<ComputerParts> wishList;

    auto display = [&wishList]() {
        for (auto& x: wishList) {
            cout << x.model << " | " << x.partType << endl;
            cout << x.price << " | " << x.powerConsumption << " | " << x.used << endl;
        }
    };

    // Task 1
    wishList.push_back(ComputerParts{ "CPU", "AMD 7950X3D", 800, 200, false});
    wishList.push_back(ComputerParts{ "GPU", "NVIDIA 3070", 500, 250, false});
    wishList.push_back(ComputerParts{ "RAM", "Ripjaws 32GB", 120, 50, true});
    wishList.push_back(ComputerParts{ "PSU", "Corsair SFX70", 200, 750, true});
    wishList.push_back(ComputerParts{ "Motherboard", "ASRock", 150, 100, false});

    // Task 2
    std::sort(wishList.begin(), wishList.end(), [=](const ComputerParts& cp1, const ComputerParts& cp2) {
        return cp1.price < cp2.price;
    });

    // Task 3
    auto max_item = max_element(wishList.begin(), wishList.end(), [](const ComputerParts& cp1, const ComputerParts& cp2) {
        return cp1.price < cp2.price;
    });

    auto min_item = min_element(wishList.begin(), wishList.end(), [](const ComputerParts& cp1, const ComputerParts& cp2) {
        return cp1.price < cp2.price;
    });

    // Task 4
    auto itr = remove_if(wishList.begin(), wishList.end(), [](const ComputerParts& c) {
        return c.used;
    });
    wishList.resize(itr - wishList.begin());
//    wishList.erase(itr, wishList.end());

    // Task 5
    double sum = accumulate(wishList.begin(), wishList.end(), 0.0, [](double& sum, const ComputerParts& c) {
        return sum += c.price;
    });
    double average = sum / wishList.size();

    // Task 6
//    vector<ComputerParts> res;
//    for_each(wishList.begin(), wishList.end(), [&res](ComputerParts& c) {
//        if (!c.used) {
//            c.used = true;
//            c.price += 0.8;
//            res.push_back(c);
//        }
//    });

    vector<ComputerParts> res(wishList.size());
    transform(wishList.begin(), wishList.end(), res.begin(), [](ComputerParts& c) {
        if (!c.used) {
            c.used = true;
            c.price *= 0.8;
        }
        return c;
    });

    // Task 7
    auto cnt = count_if(wishList.begin(), wishList.end(), [](const ComputerParts& c) {
        return c.partType == "GPU";
    });
    cout << cnt << endl;

    // Task 8
    vector<ComputerParts> wl2;

    wl2.push_back(ComputerParts{ "CPU", "AMD 7950X3D", 800, 200, false});
    wl2.push_back(ComputerParts{ "GPU", "NVIDIA 3070", 500, 250, false});
    wl2.push_back(ComputerParts{ "RAM", "Ripjaws 32GB", 120, 50, true});
    wl2.push_back(ComputerParts{ "PSU", "Corsair SFX70", 200, 750, true});
    wl2.push_back(ComputerParts{ "Motherboard", "ASRock", 150, 100, false});

    std::sort(wishList.begin(), wishList.end(), [=](const ComputerParts& cp1, const ComputerParts& cp2) {
        return cp1.price < cp2.price;
    });

    std::sort(wl2.begin(), wl2.end(), [=](const ComputerParts& cp1, const ComputerParts& cp2) {
        return cp1.price < cp2.price;
    });

    vector<ComputerParts> mergedList(wishList.size() + wl2.size());
    merge(wishList.begin(), wishList.end(), wl2.begin(), wl2.end(), mergedList.begin(), [](const ComputerParts& c1, const ComputerParts& c2) {
        return c1.price < c2.price;
    });

    for (auto& x: mergedList) {
        cout << x.partType << " " << x.price << endl;
    }
}