// rawpointers.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstddef>
using std::cout;
using std::endl;

//#define ex1
//#define ex2
//#define ex3
// #define ex4
//#define ex5

int main(){

#ifdef ex1
    char str[] { "Apples"};
  cout << std::hex;
  for (int i = 0; i < str[i]; ++i)
    cout << (int*)&str[i] << " : " << str[i] << endl;
    //cout << &str[i] << " : " << str[i] << endl;
#endif

#ifdef ex2
    char str[15]{ "Apple" };
  const char* str2 = "Bananas";
  strcpy(str, str2);

  cout << std::hex;
  cout << (int*)str << " : " << str << endl;
  cout << (int*)str2 << " : " << str2 << endl;

  // Attempt to modify the string literal
  //str2[0] = 'C';

#endif

#ifdef ex3
    int arr1[]{ 1, 2, 3, 4, 5, 6 };
  int* ptr = &arr1[1];
  cout << "arr1: ";
  for (auto& x : arr1)
    cout << x << ", ";
  cout << endl;

  cout << std::hex;
  cout << "arr1[1]: " << arr1[1] << " : " << &arr1[1] << endl;
  cout << "ptr: " << *ptr << " : " << ptr << endl;
  cout << "arr1[2]: " << arr1[2] << " : " << &arr1[2] << endl;
  cout << "ptr + 1: " << *(ptr + 1) << " : " << ptr + 1 << endl;
  cout << "arr1[0]: " << arr1[0] << " : " << &arr1[0] << endl;
  cout << "ptr - 1: " << *(ptr - 1) << " : " << ptr - 1 << endl;

  ptrdiff_t diff = (&arr1[2] - &arr1[1]);
  cout << "diff: " << diff << endl;

#endif

#ifdef ex4
    int arr1[]{ 1, 2, 3, 4, 5, 6 };
  int* ptr = &arr1[1];
  cout << "arr1: ";
  for (auto& x : arr1)
    cout << x << ", ";
  cout << endl;
  cout << "ptr++: " << *(ptr++) << " : " << ptr << endl;
#endif

#ifdef ex5

    int x, y;
  int* p = &x;
  int* q = &y;

  cout << "p : " << p << endl;
  cout << "q : " << q << endl;

  auto change = [](int*& a, int*& b) {
    int* c = a;
    a = b;
    b = c;
  };

  change(p, q);
  cout << "p : " << p << endl;
  cout << "q : " << q << endl;

#endif

}
