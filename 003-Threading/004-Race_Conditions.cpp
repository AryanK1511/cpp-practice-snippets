// Thread Class
 // threadrace.cpp

 #include <iostream>
 #include <thread>
using namespace std;

int x = 0;

void funcA() {
  for (int i = 0; i < 10000; ++i) {
    x++;
  }
}

int main() {

  thread t1(funcA);
  thread t2(funcA);
  thread t3(funcA);
  thread t4(funcA);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  cout << "What is the value of x now: " << x << endl;
}