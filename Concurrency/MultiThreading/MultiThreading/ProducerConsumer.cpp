#include "ThreadSafeQueue.h"
#include <thread>
#include <iostream>

using namespace std;
void produce(SafeQueue<int> &sq) {
	for (int i = 0; i < 10; ++i)
		sq.enqueue(i);
}

void consume(SafeQueue<int> &sq) {
	for (int i = 0; i < 10; ++i)
		sq.dequeue();
}

int main() {
	SafeQueue<int> q;
	thread t1(produce, ref(q));
	thread t2(consume, ref(q));
	t1.join();
	t2.join();
	cin.get();
	return 0;
}