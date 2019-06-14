// https://austingwalters.com/multithreading-semaphores/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
int current = 0;

void print_num(int num, int max) {
	std::unique_lock<std::mutex> lck(mtx);
	cv.wait(lck, [&num]() {return num == current && ready; });

	current++;
	std::cout << "Thread: ";
	std::cout << num + 1 << "/" << max;
	std::cout << " current count is: ";
	std::cout << current << std::endl;

	cv.notify_all();
}

void run() {
	std::unique_lock<std::mutex> lck(mtx);

	ready = true;

	cv.notify_all();
}

int main() {
	int threadnum = 15;
	std::thread threads[15];

	for (int id = 0; id < threadnum; ++id) {
		threads[id] = std::thread(print_num, id, threadnum);
	}

	std::cout << "\nRunning " << threadnum;
	std::cout << " in parallel: \n" << std::endl;

	run();

	for (int id = 0; id < threadnum; ++id) {
		threads[id].join();
	}

	std::cout << "\nCompleted semaphore example!\n" << std::endl;
	std::cin.get();
	return 0;
}