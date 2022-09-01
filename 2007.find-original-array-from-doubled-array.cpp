/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */
#include <bits/stdc++.h>

using std::vector;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // T: O(n + k*log(k)), k := the number of unique numbers
    // S: O(n)
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() & 1) return {};  // array length must be even
        unordered_map<int, int> cnts;
        for (const int& x : changed) ++cnts[x];

        vector<int> keys;
        keys.reserve(cnts.size());
        for (const auto& p : cnts) {
            keys.push_back(p.first);
        }
        std::sort(keys.begin(), keys.end(), [](int k1, int k2) { return abs(k1) < abs(k2); });
        vector<int> res;
        res.reserve(changed.size() >> 1);

        // Check keys from small to large, as smaller values should not be the doubled values
        for (const int& k : keys) {
            int doubled = (k << 1);
            if (cnts[k] > cnts[doubled]) return {}; // not enough doubled elements
            for (int i = 0; i < cnts[k]; ++i) {
                res.push_back(k);
                --cnts[doubled];
            }
        }
        return res;
    }
};
// @lc code=end

