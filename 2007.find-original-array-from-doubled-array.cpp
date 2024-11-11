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
    // Hash map + sorting + greedy
    // T: O(n + k*log(k)), k := the number of unique numbers
    // S: O(n)
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() & 1) {
            return {};  // array length must be even
        }
        unordered_map<int, int> cnts;
        for (const int& x : changed) {
            ++cnts[x];
        }

        vector<int> unival_elements;
        unival_elements.reserve(cnts.size());
        for (const auto& p : cnts) {
            unival_elements.push_back(p.first);
        }
        std::sort(unival_elements.begin(), unival_elements.end(), [](int k1, int k2) { return abs(k1) < abs(k2); });
        
        vector<int> res;
        res.reserve(changed.size() >> 1);

        // Check unival_elements from small to large, as smaller values should not be the doubled values
        for (const int& x : unival_elements) {
            int doubled = (x << 1);
            auto x_cnt_it = cnts.find(x);
            auto doubled_cnt_it = cnts.find(doubled);
            if (cnts[x] > cnts[doubled]) {
                return {}; // not enough doubled elements
            } 
            for (int i = 0; i < cnts[x]; ++i) {
                res.push_back(x);
                // IMPORTANT: consume the doubled elements
                // has to subtract here for edge case x = doubled = 0
                --cnts[doubled];
            }
        }
        return res;
    }
};
// @lc code=end

