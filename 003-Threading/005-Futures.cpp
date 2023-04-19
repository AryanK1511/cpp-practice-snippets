// futures.cpp

#include <future>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric> 
#include <chrono>
using namespace std;

double accum(double* beg, double* end, double init){
  return  accumulate(beg, end, init);
}

void task(promise<double>& p, double* beg, double* end, double init) {
  p.set_value(accum(beg, end, init));
}

int main() {

  //chrono::steady_clock::time_point vstart = chrono::steady_clock::now();
  vector<double> vec(10000000, 0.5);
  //chrono::steady_clock::time_point vend = chrono::steady_clock::now();
  //auto vdur = chrono::duration_cast<chrono::milliseconds>(vend - vstart);
  //cout << "It took: " << vdur.count() << " milliseconds to complete" << endl;

  double* first = &vec[0];
  double* half = first + vec.size() / 2;
  double* last = first + vec.size();

//#define ex0
//#define ex1
//#define ex2
#define ex3

  cout << "Waiting for the result..." << endl;
  chrono::steady_clock::time_point start = chrono::steady_clock::now();

  // No threads
#ifdef ex0
  cout << "Accumlate Value = " << accumulate(vec.begin(), vec.end(), 0.0) << endl; 
#endif

  // Futures and Promises
#ifdef ex1

  //promise<double> p;
  //future<double> f = p.get_future();
  //thread t(task, ref(p), first, last, 0.0);
  //cout << "Task Value = " << f.get()<< endl; 
  //t.join();

  //promise<double> p1, p2;
  //future<double> f1 = p1.get_future();
  //future<double> f2 = p2.get_future();
  //thread t1(task, ref(p1), first, half, 0.0);
  //thread t2(task, ref(p2), half, last, 0.0);
  //cout << "Task Value = " << f1.get()<< endl; 
  //cout << "Task Value = " << f2.get()<< endl; 
  //t1.join();
  //t2.join();

#endif

  // Packaged_tasks
#ifdef ex2
  //packaged_task<double(double*, double*, double)> pt1(accum);
  //packaged_task<double(double*, double*, double)> pt2(accum);
  //auto f1 = pt1.get_future();
  //auto f2 = pt2.get_future();
  //pt1(first, half, 0.0);
  //pt2(half, last, 0.0);
  //double result = f1.get() + f2.get();
  //cout << "The value of result is: " << result << endl;

  packaged_task<double(double*, double*, double)> pt1(accum);
  packaged_task<double(double*, double*, double)> pt2(accum);
  auto f1 = pt1.get_future();
  auto f2 = pt2.get_future();
  thread t1(std::move(pt1), first, half, 0.0);
  thread t2(std::move(pt2), half, last, 0.0);
  double result = f1.get() + f2.get();
  t1.join();
  t2.join();
  cout << "The value of result is: " << result << endl;

#endif

  // async()
#ifdef ex3

  auto f1 = std::async(accum, first, half, 0.0);
  auto f2 = std::async(accum, half, last, 0.0);
  double result = f1.get() + f2.get();
  cout << "The value of result is: " << result << endl;

#endif

  chrono::steady_clock::time_point end = chrono::steady_clock::now();
  auto dur = chrono::duration_cast<chrono::milliseconds>(end - start);
  cout << "It took: " << dur.count() << " milliseconds to complete" << endl;

}