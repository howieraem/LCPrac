/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::string;

// @lc code=start
// Since O(1) complexity required, cannot use std::map.
// Implementation similar to LRU cache.
class AllOne {
    // Each bucket contains all keys with the same count
    struct Bucket {
        int cnt;
        std::unordered_set<string> keys;
        Bucket *pre, *nxt;
        Bucket(int _cnt) : cnt(_cnt), pre(nullptr), nxt(nullptr) {}

        void add_bucket_after(Bucket* bucket) {
            bucket->pre = this;
            bucket->nxt = nxt;
            nxt->pre = bucket;
            nxt = bucket;
        }
    };

    Bucket *head, *tail;

    // maps key to bucket pointer
    unordered_map<string, Bucket*> mp;

    void remove_bucket(Bucket* bucket) {
        bucket->nxt->pre = bucket->pre;
        bucket->pre->nxt = bucket->nxt;
        bucket->nxt = nullptr;
        bucket->pre = nullptr;
    }

    void remove_key_from_bucket(Bucket* bucket, string k) {
        bucket->keys.erase(k);
        if (bucket->keys.empty()) {
            remove_bucket(bucket);
        }
    }

public:
    AllOne() {
        head = new Bucket(INT_MIN);
        tail = new Bucket(INT_MAX);
        head->nxt = tail;
        tail->pre = head;
    }
    
    void inc(string key) {
        if (mp.find(key) != mp.end()) {
            Bucket* bucket = mp[key];
            if (bucket->cnt == bucket->nxt->cnt - 1) {
                mp[key] = bucket->nxt;
                bucket->nxt->keys.insert(key);
            } else {    // counts not contiguous
                Bucket* new_bucket = new Bucket(bucket->cnt + 1);
                new_bucket->keys.insert(key);
                mp[key] = new_bucket;
                bucket->add_bucket_after(new_bucket);
            }
            remove_key_from_bucket(bucket, key);
        } else {
            Bucket* cur = head->nxt;
            if (cur->cnt != 1) {
                cur = new Bucket(1);
                head->add_bucket_after(cur);
            }
            cur->keys.insert(key);
            mp[key] = cur;
        }
    }
    
    void dec(string key) {
        if (mp.find(key) != mp.end()) {
            Bucket* bucket = mp[key];
            if (bucket->cnt == 1) {
                mp.erase(key);
            } else if (bucket->cnt == bucket->pre->cnt + 1) {
                bucket->pre->keys.insert(key);
                mp[key] = bucket->pre;
            } else {
                Bucket* new_bucket = new Bucket(bucket->cnt - 1);
                new_bucket->keys.insert(key);
                mp[key] = new_bucket;
                bucket->pre->add_bucket_after(new_bucket);
            }
            remove_key_from_bucket(bucket, key);
        }
    }
    
    string getMaxKey() {
        return tail->pre == head ? "" : *tail->pre->keys.begin();
    }
    
    string getMinKey() {
        return head->nxt == tail ? "" : *head->nxt->keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

