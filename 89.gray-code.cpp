/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Bit manipulation + Greedy
    // T: O(2 ^ n)
    // S: O(1)
    vector<int> grayCode(int n) {
        if (n < 0) {
            return {};
        }

        vector<int> res;
        res.reserve(1 << n);

        res.push_back(0);
        for (int i = 0; i < n; ++i) {
            int sz = res.size();

            for (int j = sz - 1; j >= 0; --j) {
                // Add a new bit to the results of the previous iteration:
                // Case 1: Add a leading (most significant) bit 1 via bit manipulation.
                // Case 2: "Add" a leading bit 0, no need to do bit manipulation (e.g., 0b001 = 0b01).
                // This ensures adjacent numbers only differ by 1 bit.
                res.push_back(res[j] | 1 << i);
            }
        }

        return res;
    }
};
// @lc code=end

