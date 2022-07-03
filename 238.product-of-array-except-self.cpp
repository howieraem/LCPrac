/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        int left_product = 1, right_product = 1;
        vector<int> res(n, 1);

        // res[i] = product of nums on the left * product of nums on the right
        for (int i = 0; i < n; ++i) {
            res[i] *= left_product;
            left_product *= nums[i];
            res[n - i - 1] *= right_product;
            right_product *= nums[n - i - 1];
        }
        return res;
    }
};
// @lc code=end

