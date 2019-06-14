// https://stackoverflow.com/questions/15278343/c11-thread-safe-queue
#pragma once

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class SafeQueue {
public:
	SafeQueue() :q(), m(), cv() {}
	virtual ~SafeQueue() {}

	void enqueue(T t) {
		std::unique_lock<std::mutex> lck(m);

		q.push(t);
#ifdef _DEBUG
		std::cout << "Push " << t << " into queue\n";
#endif

		cv.notify_all();
	}

	T dequeue() {
		std::unique_lock<std::mutex> lck(m);
		cv.wait(lck, [this]() {return !(this->q.empty()); });

		T val = q.front();
		q.pop();
#ifdef _DEBUG
		std::cout << "Pop " << val << " out of queue\n";
#endif

		cv.notify_all();
		return val;
 	}

private:
	std::queue<T> q;
	std::mutex m;
	std::condition_variable cv;
};