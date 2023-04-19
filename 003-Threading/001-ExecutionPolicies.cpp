// executionpol.cpp
#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <execution>

int main() {
    std::vector<double> x(10000000, 0.5);

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    // reduce is akin to accumulate but can have paralellism applied to it
    double s = std::accumulate(x.begin(), x.end(), 0.0);
    //double s = std::reduce(std::execution::seq, x.begin(), x.end());
    std::cout << "sum = " << s <<  std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "The reduce operation took: " << dur.count() << " milliseconds to complete" << std::endl;
}
