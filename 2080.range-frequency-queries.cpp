/*
 * @lc app=leetcode id=2080 lang=cpp
 *
 * [2080] Range Frequency Queries
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
// Hash map + binary search
// S: O(n)
class RangeFreqQuery {
    unordered_map<int, vector<int>> val_to_idxs;  // idxs should be sorted ASC

public:
    // T: O(n)
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            val_to_idxs[arr[i]].push_back(i);
        }
    }
    
    // T: O(log(n))
    int query(int left, int right, int value) {
        auto it = val_to_idxs.find(value);
        if (it == val_to_idxs.end()) {
            return 0;
        }
        const auto& idxs = it->second;

        // The count is the difference between two binary searches over the idxs array (indexes of `idxs`)
        return std::upper_bound(idxs.begin(), idxs.end(), right) - 
                std::lower_bound(idxs.begin(), idxs.end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

