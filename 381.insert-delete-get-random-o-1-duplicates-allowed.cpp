/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class RandomizedCollection {
    unordered_map<int, vector<int>> val2Idxs;
    vector<pair<int, int>> vals;

public:
    RandomizedCollection() {}
    
    // T: O(1)
    bool insert(int val) {
        bool ret = val2Idxs.find(val) == val2Idxs.end();  // || !val2Idxs[val].size();
        val2Idxs[val].push_back(vals.size()); 
        vals.push_back({val, val2Idxs[val].size() - 1});
        return ret;
    }
    
    // T: O(1)
    bool remove(int val) {
        bool ret = val2Idxs.find(val) != val2Idxs.end();  // && val2Idxs[val].size();
        if (ret) {  // val exists
            auto back = vals.back();
            auto *val_idxs = &val2Idxs[val];
            int val_idx = val_idxs->back();
            val2Idxs[back.first][back.second] = val_idx;
            vals[val_idx] = back;
            val_idxs->pop_back();
            if (!val_idxs->size()) {
                // Erasing seems faster overall and saves memory
                // than not erasing when the map value vector 
                // becomes empty.
                val2Idxs.erase(val);
            }
            vals.pop_back();
        } 
        return ret;
    }
    
    // T: O(1)
    int getRandom() {
        // std::rand() returns a pseudo-random integral value 
        // between ​0​ and RAND_MAX (​0​ and RAND_MAX included).
        return vals[rand() % vals.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

