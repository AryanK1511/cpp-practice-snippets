// Algorithms Revision
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct Car {
    string model;
    string color;
    double price;
    double horsePower;
    bool used;
    void display() {
        cout << model << " | " << color << " | " << price << " | " << horsePower << " | " << used << endl;
    }
};

int main() {
    // => Create a showroom of cars
    vector<Car> showroom;

    // Q1. Add some cars to the showroom
    cout << "========== QUESTION 1 ==========" << endl;

    showroom.push_back(Car{"Tesla", "Black", 100000, 3000, false});
    showroom.push_back(Car{"BMW", "White", 75000, 4000, false});
    showroom.push_back(Car{"Merc", "Red", 50000, 3500, true});
    showroom.push_back(Car{"Honda", "Silver", 20000, 2000, true});
    showroom.push_back(Car{"Toyota", "Matte Black", 45000, 2500, false});

    for (auto& car: showroom) {
        car.display();
    }
    cout << "******************************\n" << endl;

    // Q2. Sort the cars in the showroom by price in ascending order
    cout << "========== QUESTION 2 ==========" << endl;
    sort(showroom.begin(), showroom.end(), [](const Car& car1, const Car& car2) {
        return car1.price < car2.price;
    });

    for (auto& car: showroom) {
        car.display();
    }
    cout << "******************************\n" << endl;

    // Q3. Print the car which has the least and the most horsepower
    cout << "========== QUESTION 3 ==========" << endl;

    auto leastHPCar = min_element(showroom.begin(), showroom.end(), [](const Car& car1, const Car& car2) {
        return car1.horsePower < car2.horsePower;
    });

    auto mostHPCar = min_element(showroom.begin(), showroom.end(), [](const Car& car1, const Car& car2) {
        return car1.horsePower > car2.horsePower;
    });

    cout << "CAR with most HP: ";
    mostHPCar->display();
    cout << "CAR with least HP: ";
    leastHPCar->display();

    cout << "******************************\n" << endl;

    // Q4. Remove from the showroom all the cars that are used
    cout << "========== QUESTION 4 ==========" << endl;
    auto itr = remove_if(showroom.begin(), showroom.end(), [](const Car& car) {
        return car.used;
    });
    showroom.resize(itr - showroom.begin());
    for (auto& car: showroom) {
        car.display();
    }
    cout << "+++++++++" << endl;

    // Remove all cars from the showroom and add them again
    showroom.erase(showroom.begin(), showroom.end());
    cout << "Removing all Cars" << endl;
    for (auto& car: showroom) {
        car.display();
    }
    cout << "+++++++++" << endl;

    cout << "Adding all Cars again" << endl;
    showroom.push_back(Car{"Tesla", "Black", 100000, 3000, false});
    showroom.push_back(Car{"BMW", "White", 75000, 4000, false});
    showroom.push_back(Car{"Merc", "Red", 50000, 3500, true});
    showroom.push_back(Car{"Honda", "Silver", 20000, 2000, true});
    showroom.push_back(Car{"Toyota", "Black", 45000, 2500, false});
    for (auto& car: showroom) {
        car.display();
    }
    cout << "+++++++++" << endl;
    cout << "******************************\n" << endl;

    // Q5. Find the average cost of all cars in the showroom
    cout << "========== QUESTION 5 ==========" << endl;
    double sumOfPrices = accumulate(showroom.begin(), showroom.end(), 0, [](int sum, const Car& car) {
        return sum += car.price;
    });
    double avg = sumOfPrices / (double) showroom.size();
    cout << "AVERAGE PRICE: " << avg << endl;
    cout << "******************************\n" << endl;

    // Q6. Changed all the items to used and reduce price by 20% and save this to a new vector
    cout << "========== QUESTION 6 ==========" << endl;
    vector<Car> usedShowroom;
    transform(showroom.begin(), showroom.end(), back_inserter(usedShowroom), [](Car& car) {
        if (!car.used) {
            car.used = true;
            car.price *= 0.8;
        }
        return car;
    });
    for (auto& car: usedShowroom) {
        car.display();
    }
    cout << "******************************\n" << endl;

    // Q7. Check how many cars are black in color
    cout << "========== QUESTION 7 ==========" << endl;
    int count = count_if(showroom.begin(), showroom.end(), [](const Car& car) {
        return car.color == "Black";
    });
    cout << "COUNT OF BLACK CARS: " << count << endl;
    cout << "******************************\n" << endl;

    // Q8.
    cout << "========== QUESTION 8 ==========" << endl;
    vector<Car> showroom2;

    showroom2.push_back(Car{"Car1", "Black", 100000, 3000, false});
    showroom2.push_back(Car{"Car2", "White", 75000, 4000, false});
    showroom2.push_back(Car{"Car3", "Red", 50000, 3500, true});
    showroom2.push_back(Car{"Car4", "Silver", 20000, 2000, true});
    showroom2.push_back(Car{"Car5", "Matte Black", 45000, 2500, false});

    vector<Car> merged;
    sort(showroom.begin(), showroom.end(), [](const Car& car1, const Car& car2) {
        return car1.price < car2.price;
    });
    sort(showroom2.begin(), showroom2.end(), [](const Car& car1, const Car& car2) {
        return car1.price < car2.price;
    });
    merge(showroom.begin(), showroom.end(), showroom2.begin(), showroom2.end(), back_inserter(merged), [](const Car& car1, const Car& car2) {
        return car1.price < car2.price;
    });
    for (auto& car: merged) {
        car.display();
    }
    cout << "******************************\n" << endl;

    return 0;
}