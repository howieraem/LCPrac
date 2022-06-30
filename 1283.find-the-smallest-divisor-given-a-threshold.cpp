/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Binary search (lower bound)
    // T: O(n * (max(nums) - 1))
    // S: O(1)
    int smallestDivisor(const vector<int>& nums, const int& threshold) {
        int l = 1, r = 1e6; // or *std::max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = l + ((r - l) >> 1);
            int sum = 0;
            for (const int& x : nums) {
                // divide before sum to avoid overflow
                sum += (x + m - 1) / m;
            }
            if (sum > threshold) l = m + 1;
            else r = m;
        }
        return l;
    }
};
// @lc code=end

