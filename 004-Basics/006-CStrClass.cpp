#include <iostream>
using namespace std;

class Cstr {
public:
    static void cpy(char* des, const char* src) {
        while ((*des++ = *src++));
    }

    static int len(const char* str) {
        const char* end = str;
        while(*end++);
        return static_cast<int>(end - str) - 1;
    }

    static void allocNcpy(char*& des, const char* src) {
        des = new char[len(src) + 1];
        cpy(des, src);
    }
};

int main() {
    const char* x = "Hello";
    char* xCpy = nullptr;
    Cstr::allocNcpy(xCpy, x);
    cout << x << endl;
    cout << xCpy << endl;
    return 0;
}