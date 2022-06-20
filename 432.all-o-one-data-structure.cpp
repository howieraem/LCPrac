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

    // maps key to count
    unordered_map<string, int> cnts;

    // maps key count to bucket pointer
    unordered_map<int, Bucket*> mp;

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
            mp.erase(bucket->cnt);
        }
    }

    void change(string k, int diff) {
        int cnt = cnts[k], new_cnt = cnt + diff;
        cnts[k] = new_cnt;
        Bucket* pre_bucket = mp[cnt], *bucket;
        if (mp.find(new_cnt) != mp.end()) {
            bucket = mp[new_cnt];
        } else {
            bucket = new Bucket(new_cnt);
            mp[new_cnt] = bucket;
            if (diff == 1) {
                pre_bucket->add_bucket_after(bucket);
            } else {    // diff == -1
                pre_bucket->pre->add_bucket_after(bucket);
            }
        }
        bucket->keys.insert(k);
        remove_key_from_bucket(pre_bucket, k);
    }

public:
    AllOne() {
        head = new Bucket(INT_MIN);
        tail = new Bucket(INT_MAX);
        head->nxt = tail;
        tail->pre = head;
    }
    
    void inc(string key) {
        if (cnts.find(key) != cnts.end()) {
            change(key, 1);
        } else {
            cnts[key] = 1;
            Bucket* cur;
            if (head->nxt->cnt != 1) {
                cur = new Bucket(1);
                head->add_bucket_after(cur);
            } else {
                cur = head->nxt;
            }
            cur->keys.insert(key);
            mp[1] = cur;
        }
    }
    
    void dec(string key) {
        if (cnts.find(key) != cnts.end()) {
            int cnt = cnts[key];
            if (cnt == 1) {
                cnts.erase(key);
                remove_key_from_bucket(mp[1], key);
            } else {
                change(key, -1);
            }
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

