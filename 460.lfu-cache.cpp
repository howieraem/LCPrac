/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
// Solution with std::list
struct Node {
    int v, freq;
    list<int>::iterator iter;

    Node(int _v, int _freq, list<int>::iterator _iter) {
        v = _v;
        freq = _freq;
        iter = _iter;
    }
};

class LFUCache {
    int cap, sz, curLeastFreq = 0;

    // (frequency, list of keys with that frequency)
    unordered_map<int, list<int>> freqs;

    unordered_map<int, Node*> mp;

    void update(int key) {
        Node *node = mp[key];

        // Erase the key from old frequency list
        freqs[node->freq].erase(node->iter);

        // Increment frequency and update corresponding list and iterator
        node->freq++;
        freqs[node->freq].push_back(key);
        node->iter = --freqs[node->freq].end();     // iterator points to the back of the frequency list at which the key is

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
        if (mp.find(key) == mp.end())  return -1;
        update(key);
        return mp[key]->v;
    }
    
    // O(1)
    void put(int key, int value) {
        if (!cap)  return;
        if (mp.find(key) != mp.end()) {
            // Updates value of an existing key
            mp[key]->v = value;
            update(key);    // increment frequency
        } else {
            if (sz == cap) {    // full, need to pop the least frequent data
                int evictKey = freqs[curLeastFreq].front(); freqs[curLeastFreq].pop_front();
                mp.erase(evictKey);
            } else {
                ++sz;
            }

            // Insert new k-v pair
            freqs[1].push_back(key);
            mp[key] = new Node(value, 1, --freqs[1].end());
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

