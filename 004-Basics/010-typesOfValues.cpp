#include <iostream>

class Container {
    int m_data;
public:
    Container(int d = 0) {
        m_data = d;
    }

    Container& operator=(int d) {
        m_data = d;
        return *this;
    }

    int& value() {
        std::cout << "Setting data" << std::endl;
        return m_data;
    }

    void display() {
        std::cout << m_data;
    }
};

int main() {
    Container C;

    // lvalue
    C.value() = 23;
    C.display();

    // Container is an xvalue here on the left side
    Container(10).value() = 25;
    (Container(10) = 35).display();

    // xvalue on the right side
    // prvalues are xvalues that could not be put on the left side
    C = Container(34);
    C.display();
    return 0;
}
