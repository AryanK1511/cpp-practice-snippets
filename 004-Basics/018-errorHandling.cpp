// trycatch.cpp
#include <iostream>
#include <exception>
using std::cin;
using std::cout;
using std::endl;

//#define ex1
//#define ex2
#define ex3

void enterNum() {

  int choice = 0;
  cout << "Enter a number: ";
  cin >> choice;
  switch (choice) {
  case 0:
    throw 0;
    break;
  case 1:
    throw 1;
    break;
  case 2:
    throw 'T';
    break;
  default:
    throw "Not 0, 1, 2";
    break;
  }

  cout << "End of enterNum" << endl;
}

void allocate() {
  char* p = nullptr;
  int i = 0;
  //try {
    do {
      p = new char[100000000]; // really big
      i++;
    } while (p != nullptr);
  //}
  //catch(std::bad_alloc){
  //  cout << "Bad  allocation exception" << endl;
  //}
}

int main() {

#ifdef ex1
  try {
    enterNum();
  }
  catch(int e){
    cout << "We caught an int: " << e << endl;
  }
  catch(char e){
    cout << "We caught an char: " << e << endl;
  }
  catch(const char* e){
    cout << "We caught an cstring: " << e << endl;
  }
#endif

#ifdef ex2
  allocate();
#endif

#ifdef ex3
  int i;

  auto funcA = []() {std::cout << "Adios" << std::endl; };
  auto funcB = []() {std::cout << "Ciao" << std::endl; };
  auto funcC = []() {std::cout << "Arrivederci" << std::endl; };

  std::cout << "Return(!=1), Exit(1) ? "; 
  std::cin >> i;
  if (i == 1) {
    std::atexit(funcA);
    std::atexit(funcB);
    std::atexit(funcC);
    std::exit(1);
  }
  return i;
#endif
}