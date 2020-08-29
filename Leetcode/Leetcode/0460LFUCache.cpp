/*
460 LFU Cache

Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

put(key, value) - Set or insert the value if the key is not already present.
When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item.
For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;
class LFUCache {
public:
	LFUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (!m.count(key)) return -1;
		int value = m[key].first, f = m[key].second; // get value and original frequency
		m[key].second++; // increment frequency

		list<int>& update = freq[f+1]; // new frequency's list. A new list will be created if f+1 frequency list does not exist.
		update.splice(update.end(), freq[f], iter[key]); // move old frequency node to new frequency list's back
		if (freq[minFreq].empty()) minFreq = f + 1; // if above operation caused freq[minFreq] list empty, then we should update minFreq to f + 1

		return value;
	}

	void put(int key, int value) {
		if (cap < 1) return;
		if (get(key) != -1) {
			// key exists
			// trick: use get(key) to update the frequency
			m[key].first = value;
			return;
		}

		// key doesn't exist, create new records
		if (m.size() == cap) {
			// evict least frequency node
			int least_key = freq[minFreq].front();
			m.erase(least_key);
			iter.erase(least_key);
			freq[minFreq].pop_front();
		}
		m[key] = { value, 1 };
		freq[1].push_back(key);
		iter[key] = --freq[1].end();
		minFreq = 1;

	}
private:
	int cap, minFreq;
	unordered_map<int, pair<int, int>> m;	// key -> (value, freq)
	unordered_map<int, list<int>> freq;		// freq -> list of keys. For same frequency keys: front - least used, back - recent used.
	unordered_map<int, list<int>::iterator> iter; // key -> iterator of the list node with key
};

//int main() {
//	LFUCache cache(2);
//
//	cache.put(1, 1);
//	cache.put(2, 2);
//	cout<<cache.get(1)<<" expect 1"<<endl;       // returns 1
//	cache.put(3, 3);    // evicts key 2
//	cout<<cache.get(2)<<" expect -1"<<endl;       // returns -1 (not found)
//	cout <<cache.get(3)<<" expect 3"<<endl;       // returns 3.
//	cache.put(4, 4);    // evicts key 1.
//	cout<<cache.get(1)<<" expect -1"<<endl;       // returns -1 (not found)
//	cout<<cache.get(3)<<" expect 3"<<endl;       // returns 3
//	cout<<cache.get(4)<<" expect 4"<<endl;       // returns 4
//
//	cin.get();
//	return 0;
//}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */