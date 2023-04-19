#include <iostream>

class Car {
private:
    static int m_numberOfCars;
    std::string m_color;
    int m_wheels;
public:
    Car(std::string color, int wheels) {
        m_color = color;
        m_wheels = wheels;
        m_numberOfCars++;
    }
    static int getNumberOfCars() {
        return m_numberOfCars;
    }
    void display() {
        std::cout << m_color << " " << m_wheels << std::endl;
    }
};

int Car::m_numberOfCars = 0;

int main() {
    std::cout << Car::getNumberOfCars() << std::endl;
    Car car1("Red", 4);
    std::cout << Car::getNumberOfCars() << std::endl;
    Car car2("Green", 5);
    std::cout << Car::getNumberOfCars() << std::endl;
    car1.display();
    car2.display();
    return 0;
}
