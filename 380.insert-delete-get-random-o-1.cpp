/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class RandomizedSet {
    unordered_map<int, int> val2Idx;
    vector<int> vals;

public:
    RandomizedSet() {}
    
    // T: O(1)
    bool insert(int val) {
        if (val2Idx.find(val) != val2Idx.end())  return false;
        // Since a set cannot contain duplicates, it is fine to overwrite its index
        val2Idx[val] = vals.size(); 
        vals.push_back(val);
        return true;
    }
    
    // T: O(1)
    bool remove(int val) {
        if (val2Idx.find(val) == val2Idx.end())  return false;
        int back = vals.back(), idx = val2Idx[val];
        // When a value is being removed, replace it with the back of
        // the value collection and update the corresponding index.
        // Then, this back value can be safely popped from the value
        // collection and the value being removed can be erased from
        // the map.
        vals[idx] = back;
        val2Idx[back] = idx;
        vals.pop_back();
        val2Idx.erase(val);
        return true;
    }
    
    // T: O(1)
    int getRandom() {
        // std::rand() returns a pseudo-random integral value 
        // between ​0​ and RAND_MAX (​0​ and RAND_MAX included).
        return vals[rand() % vals.size()];
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

