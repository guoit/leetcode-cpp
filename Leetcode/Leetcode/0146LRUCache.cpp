/*
146 LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 // capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
#include <list>
#include <unordered_map>
#include <iostream>
#include <utility>

using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		if (!m_map.count(key)) {
			return -1;
		}

		auto it = m_map[key];	// find the iterator of m_list which points to the key's value
		m_list.splice(m_list.begin(), m_list, it);	// use splice to move *it from its original position to beginning, and it has the same effect as below THREE lines!
		/*
		m_list.push_front(make_pair(it->first, it->second));	// push the key's value into front of list
		m_list.erase(it);	// remove the current node from list
		m_map[key] = m_list.begin();	// update m_map for key so it points to the new iterator in m_list
		*/

		return it->second;
	}

	void put(int key, int value) {
		if (m_map.count(key)) {
			// update existing record
			m_map[key]->second = value;
			m_list.splice(m_list.begin(), m_list, m_map[key]);
		}
		else {
			// create new record
			if (m_list.size() == m_capacity) {
				int k = m_list.back().first;
				m_map.erase(k);
				m_list.pop_back();
			}
			m_list.push_front({ key, value });
			m_map[key] = m_list.begin();
		}
	}

private:
	unordered_map<int, list<pair<int, int>>::iterator> m_map;
	list<pair<int, int>> m_list;
	int m_capacity;
};

//int main() {
//	LRUCache cache(2);
//	cache.put(1, 1);
//	cache.put(2, 2);
//	cout<<cache.get(1)<<" expect 1"<<endl;       // returns 1
//	cache.put(3, 3);    // evicts key 2
//	cout<<cache.get(2)<<" expect -1"<<endl;       // returns -1 (not found)
//	cache.put(4, 4);    // evicts key 1
//	cout<<cache.get(1)<<" expect -1"<<endl;       // returns -1 (not found)
//	cout<<cache.get(3)<<" expect 3"<<endl;       // returns 3
//	cout<<cache.get(4)<<" expect 4"<<endl;       // returns 4
//
//	cin.get();
//	return 0;
//}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */