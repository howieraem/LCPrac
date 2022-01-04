/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class LFUCache {
    int cap, sz, curLeastFreq = 0;

    // (frequency, list of keys with that frequency)
    unordered_map<int, list<int>> freqs;
    
    // (key, iterator that points to the key's position in the corresponding frequency list)
    unordered_map<int, list<int>::iterator> iters;

    // (key, (value, frequency))
    unordered_map<int, pair<int, int>> vals;

    void update(int key) {
        int freq = vals[key].second;
        auto iter = iters[key];

        // Increment the frequency of the key
        ++vals[key].second;
        freqs[freq].erase(iter);
        freqs[freq + 1].push_back(key);

        // Make the key's iterator point to the last added frequency list item 
        iters[key] = --freqs[freq + 1].end();

        if (freqs[curLeastFreq].empty()) {
            ++curLeastFreq;
        }
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        sz = 0;
    }
    
    // O(1)
    int get(int key) {
        if (vals.find(key) == vals.end())  return -1;
        update(key);
        return vals[key].first;
    }
    
    // O(1)
    void put(int key, int value) {
        if (!cap)  return;
        if (vals.find(key) != vals.end()) {
            // Updates value of an existing key
            vals[key].first = value;
            update(key);    // increment frequency
        } else {
            if (sz == cap) {    // full, need to pop the least frequent data
                int evict = freqs[curLeastFreq].front(); freqs[curLeastFreq].pop_front();
                vals.erase(evict);
                iters.erase(evict);
            } else {
                ++sz;
            }

            // Insert new k-v pair
            vals[key] = {value, 1};
            freqs[1].push_back(key);
            iters[key] = --freqs[1].end();
            curLeastFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

