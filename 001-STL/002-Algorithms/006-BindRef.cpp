// BindRef.cpp

#include <iostream>
#include <functional>
using namespace std;

double multiply(double x, double y) { return x * y; }
void increment(int& x, int& y) { ++x, ++y; }

//#define ex1
//#define ex2
//#define ex3

bool biggerthan50(function<double()> func) {
  bool ret = false;
  if (func() > 50.0) ret = true;
  return ret;
}

int main() {
// placeholders::_1
#ifdef ex1
  auto p = std::bind(multiply, 10, 3);
  std::cout << "p() is actually multiply(10, 3): " << p() << std::endl;

  if (biggerthan50(p))
    std::cout << "p > 50" << std::endl;
  else
    std::cout << "p < 50" << std::endl;
#endif

#ifdef ex2
  auto p = std::bind(multiply, placeholders::_1, 3);
  std::cout << "p() is actually multiply(2, 3): " << p(2) << std::endl;
#endif

#ifdef ex3
  int a = 10, b = 20;
  auto inc = bind(increment, std::ref(a), std::ref(b));
  inc();
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
#endif

}