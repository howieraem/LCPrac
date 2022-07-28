/*
 * @lc app=leetcode id=2217 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(1) inplace modification
    int triangularSum(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 1; --i) {
            for (int j = 0; j < i; ++j) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }
        return nums[0];
    }
};
// @lc code=end
