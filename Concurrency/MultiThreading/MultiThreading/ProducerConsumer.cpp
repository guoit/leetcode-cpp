#include "ThreadSafeQueue.h"
#include <thread>
#include <iostream>

using namespace std;
void produce(SafeQueue<int> &sq) {
	int count = 0;
	while (count < 10) {
		sq.enqueue(count);
		++count;
	}
}

void consume(SafeQueue<int> &sq) {

}

//int main() {
//	SafeQueue<int> q;
//	thread t1(produce, ref(q));
//	thread t2(consume, ref(q));
//	t1.join();
//	t2.join();
//	cin.get();
//	return 0;
//}