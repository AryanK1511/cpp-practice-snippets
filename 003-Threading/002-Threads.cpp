// Thread Class
// thread.cpp

#include <iostream>
#include <thread>

void task() {
    std::cout << "task says Hi" << std::endl;
}

void tasktwo() {
    std::cout << "tasktwo says Hi" << std::endl;
}

int main() {
    // spawn a child thread
    std::thread t1(task);
    // spawn another child thread
    std::thread t2(tasktwo);
    // continue executing the main thread
    std::cout << "main says Hi" << std::endl;

    // Print the thread's id
    std::cout << "t1's thread id: " << t1.get_id() << std::endl;
    std::cout << "t2's thread id: " << t2.get_id() << std::endl;

    // synchronize - IMPORTANT!
    t2.join();
    t1.join();
}