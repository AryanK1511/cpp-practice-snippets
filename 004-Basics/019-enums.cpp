#include <iostream>
using namespace std;

enum traffic_light1 {
    red,
    yellow,
    green
};

enum class traffic_light2 {
    red,
    yellow,
    green
};

int main() {
    // Plain enum
    cout << traffic_light1::red << endl;
    cout << traffic_light1::yellow << endl;
    cout << traffic_light1::green << endl;

    // Class enum
    cout << traffic_light2::red << endl; // Won't work without an overload
    cout << traffic_light2::yellow << endl;
    cout << traffic_light2::green << endl;
    return 0;
}