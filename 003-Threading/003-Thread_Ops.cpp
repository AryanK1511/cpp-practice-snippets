// thread_id.cpp

#include <iostream>
#include <thread>
#include <vector>

const int NT = 10;

void task() {
    std::cout << "Thread id = " <<
              std::this_thread::get_id() << std::endl;
}

void taskwitharg(int i) {
    std::cout << "Value of i: " << i << " Thread id = " <<
              std::this_thread::get_id() << std::endl;
}

class Task {
public:
    Task(){}
    void operator()(int i) {
        std::cout << i << " Thread id = " <<
                  std::this_thread::get_id() << std::endl;
    }
};

int main() {
    // create a vector of threads
    std::vector<std::thread> threads;

//#define ex0
//#define ex1
//#define ex2
//#define ex3
//#define ex4

#ifdef ex0
    std::thread t;
    std::cout << "Is t joinable? : " << (t.joinable() ? "Yes" : "No") << std::endl;
    t = std::thread(task);
    //std::thread t2 = t;
    std::cout << "Is t joinable now? : " << (t.joinable() ? "Yes" : "No") << std::endl;
    t.join();

    std::cout << "How many threads can I have really? " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "What is the current (main) thread's id? " << std::this_thread::get_id() << std::endl;
#endif

#ifdef ex1
    // launch execution of each thread
    for (int i = 0; i < NT; i++)
        threads.push_back(std::thread(task)); // just a func
#endif
#ifdef ex2
    for (int i = 0; i < NT; i++)
        threads.push_back(std::thread(taskwitharg, i));  // func with arg
#endif
#ifdef ex3
    for (int i = 0; i < NT; i++)
         threads.push_back(std::thread([=]() { std::cout << i << " Thread id = " << // lambda
#endif
#ifdef ex4
    for (int i = 0; i < NT; i++)
        threads.push_back(std::thread(Task(), i));  // func object
#endif

    // synchronize their execution here
    for (auto& thread : threads)
        thread.join();
}