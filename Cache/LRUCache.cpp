#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> mp_;

    void makeCacheWarm(int key, int val) {
        cache_.push_back({ key, val });
        cache_.erase(mp_[key]);
        mp_[key] = prev(cache_.end());
    }

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        if (mp_.count(key)) {
            int val = (*mp_[key]).second;
            makeCacheWarm(key, val);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        // key found: make cache warm
        if (mp_.count(key)) {
            makeCacheWarm(key, value);
        }
        // key not found
        else {
            // if we hit the capacity: evict the last cache entry
            if (capacity_ == mp_.size()) {
                mp_.erase(cache_.front().first);
                cache_.pop_front();
            }
            cache_.push_back({ key, value });
            mp_[key] = prev(cache_.end());
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */