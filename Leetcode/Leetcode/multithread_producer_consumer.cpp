/*
Multi-threading producer and consumer
https://austingwalters.com/multithreading-producer-consumer-problem/
*/
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;

mutex mtx;
condition_variable cv;

int meal = 0;

void producer() {

}

void consumer() {
	unique_lock<mutex> lck(mtx);
	while (meal == 0)	cv.wait(lck);
}