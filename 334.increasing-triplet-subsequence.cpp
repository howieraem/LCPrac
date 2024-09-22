/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        long long xi = LONG_LONG_MAX;
        long long xj = LONG_LONG_MAX;
        for (long long x : nums) {
            if (x <= xi) {
                xi = x;
            } else if (x <= xj) {
                xj = x;
            } else {  
                // x > xj, and xj should not be the default max at this stage
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

