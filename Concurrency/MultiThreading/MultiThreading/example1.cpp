// https://thispointer.com/c-11-multithreading-part-1-three-different-ways-to-create-threads/
// create threads from (1) function pointer (2) function object (3) lambda function
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

std::mutex m;
void thread_function()	// function pointer
{
	for (int i = 0; i < 100; i++) {
		unique_lock<mutex> locker(m);
		cout << "[Thread 1] prints " << i << "\n";
		locker.unlock();
		this_thread::sleep_for(std::chrono::milliseconds(10));
	}		
}

class DisplayThread {	// function object
public:
	void operator()() {
		for (int i = 0; i < 100; i++) {
			unique_lock<mutex> locker(m);
			cout << "[Thread 2] prints " << i << "\n";
			locker.unlock();
			this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
};

auto fn3 = [] {
	for (int i = 0; i < 100; i++) {
		unique_lock<mutex> locker(m);
		cout << "[Thread 3] prints " << i << "\n";
		locker.unlock();
		this_thread::sleep_for(std::chrono::milliseconds(10));
	}
};

//int main()
//{
//	cout << "Main starts";
//	thread t1(thread_function);
//
//	auto fn2 = DisplayThread();
//	thread t2(fn2);
//	// or use below
//	// thread t2((DisplayThread()));
//
//	thread t3(fn3);
//	t1.join(); 
//	t2.join();
//	t3.join();
//	cout << "Exit of Main function" << endl;
//	cin.get();
//	return 0;
//}