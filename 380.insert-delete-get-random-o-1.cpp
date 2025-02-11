/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
// Hash Map + Array
// S: O(n)
class RandomizedSet {
    unordered_map<int, int> val2Idx;
    vector<int> vals;   // Contains distinct values for O(1) GetRandom()
    std::mt19937 gen;

public:
    RandomizedSet() : gen((std::random_device())()) {}
    
    // T: O(1)
    bool insert(int val) {
        if (val2Idx.find(val) != val2Idx.end()) {
            return false;
        }
        val2Idx[val] = vals.size(); 
        vals.push_back(val);
        return true;
    }
    
    // T: O(1)
    bool remove(int val) {
        auto it = val2Idx.find(val);
        if (it == val2Idx.end()) {
            return false;
        }
        int back = vals.back(); 
        int original_idx = it->second;
        // When a value is being removed, replace it with the back of
        // the value collection and update the corresponding index.
        // Then, the duplicate back value can be safely popped from the value
        // collection and the target value can also be erased from the map. 
        vals[original_idx] = back;
        val2Idx[back] = original_idx;
        vals.pop_back();
        val2Idx.erase(val);
        return true;
    }
    
    // T: O(1)
    int getRandom() {
        // may need to handle empty set case
        std::uniform_int_distribution<> dis(0, vals.size() - 1);
        return vals[dis(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

