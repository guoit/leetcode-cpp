// https://stackoverflow.com/questions/15278343/c11-thread-safe-queue
#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class SafeQueue {
public:
	SafeQueue() :q(), m(), cv() {}
	virtual ~SafeQueue() {}

	void enqueue(T t) {
		std::unique_lock<std::mutex> lock(m);
		q.push(t);
		cv.notify_one();
	}

	void dequeue() {
		std::unique_lock<std::mutex> lock(m);
		while (q.empty()) {
			cv.wait();
		}
		T val = q.front();
		q.pop();
		return val;
 	}

private:
	std::queue<T> q;
	std::mutex m;
	std::condition_variable cv;
};