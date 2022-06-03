/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */
#include <bits/stdc++.h>

// @lc code=start
// Intuitive approach: count each element with a map and then count 
// the unique frequencies with a set. This can be space-expensive.

class Solution {
public:
    // Specific approach: since the value range and the maximum possible 
    // occurances are known, we can use counting sort.
    // T: O(n)
    // S: O(1) (or O(max(n) - min(n)))
    bool uniqueOccurrences(std::vector<int>& arr) {
        uint16_t c[2001] = {}, cnt_c[1000] = {};
        for (const auto &a : arr) {
            ++c[a + 1000];  // range of a is [-1000, 1000]
        }

        for (int i = 0; i < 2001; ++i) {
            if (c[i] && ++cnt_c[c[i]] > 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
