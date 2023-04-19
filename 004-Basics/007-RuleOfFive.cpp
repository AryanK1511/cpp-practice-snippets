#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* m_model;
    string m_color;
    int m_passengers;
    double m_speed;
public:
    Car() = default;
    Car(const char* model, string color, int passengers, double speed) {
        if (model) {
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
        }
        m_color = color;
        m_speed = speed;
        m_passengers = passengers;
    }

    Car(const Car& car) {
        cout << "Copying car\n" << endl;
        *this = car;
    }

    Car& operator=(const Car& car) {
        cout << "Calling copy assignment\n" << endl;
        if (this != &car) {
            delete[] m_model;

            if (car.m_model) {
                m_model = new char[strlen(car.m_model) + 1];
                strcpy(m_model, car.m_model);
            } else {
                m_model = nullptr;
            }
            m_color = car.m_color;
            m_passengers = car.m_passengers;
            m_speed = car.m_speed;
        }
        return *this;
    }

    Car(Car&& car) noexcept {
        cout << "Moving Car\n" << endl;
        *this = move(car);
    }

    Car& operator=(Car&& car) noexcept {
        cout << "Calling Move Assignment\n" << endl;
        if (this != &car) {
            delete[] m_model;
            m_model = car.m_model;
            car.m_model = nullptr;
            m_color = car.m_color;
            car.m_color = "";
            m_passengers = car.m_passengers;
            car.m_passengers = 0;
            m_speed = car.m_speed;
            car.m_speed = 0;
        }

        return *this;
    }

    void display() const {
        cout << "Car Details: " << endl;
        cout << "Model: " << m_model << endl;
        cout << "Color: " << m_color << endl;
        cout << "Passengers: " << m_passengers << endl;
        cout << "Speed: " << m_speed << endl;
    }
//    ~Car() {
//        cout << "Deleting car " << m_model << "\n" << endl;
//        delete[] m_model;
//    }
};

int main() {
    Car car1 {"Tesla", "Red", 5, 220.20};
    car1.display();
    cout << endl;

    Car car2 = car1;
    car2.display();
    cout << endl;

    Car car3 {"Ferrari", "Black", 2, 450.30};
    car3.display();
    cout << endl;

    car1 = car3;

    car1.display();
    cout << endl;

    Car car4 = {"Hummer", "Yellow", 7, 220};
    car4.display();
    cout << endl;

    car3 = move(car4);
    car3.display();
    cout << endl;
    return 0;
}