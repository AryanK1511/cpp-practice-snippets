#include <iostream>

int main(int argc, char* argv[], char* env[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    for (int i = 0; env[i]; i++) {
        std::cout << (i + 1) << "- " << env[i] << std::endl;
    }
}