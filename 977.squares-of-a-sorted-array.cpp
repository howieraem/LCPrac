/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);

        // Accumulate results from the largest square (or largest abs value)
        int p = n - 1;
        int l = 0;
        int r = n - 1;
        while (l <= r) {  // IMPORTANT: l <= r, not l < r, in case either pointer has never changed
            if (std::abs(nums[l]) < std::abs(nums[r])) {
                res[p] = nums[r] * nums[r];
                --r;
            } else {
                res[p] = nums[l] * nums[l];
                ++l;
            }
            --p;
        }
        return res;
    }
};
// @lc code=end

