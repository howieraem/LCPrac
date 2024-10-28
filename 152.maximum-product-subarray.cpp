/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // 1D DP, variant of Kadane's algo
    // T: O(n)
    // S: O(1)
    int maxProduct(vector<int>& nums) {
        int prefix_product = 1, suffix_product = 1;

        // IMPORTANT: The lower bound of ans is not 0. If nums only contain a negative value, ans will be negative.
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            ans = std::max(ans, prefix_product *= nums[i]);
            if (prefix_product == 0) {  // or nums[i] == 0
                prefix_product = 1;
            }
        }

        // IMPORTANT: Prefix products may miss the optimum. Need to consider suffix products as well.
        // Example: nums = [-3, -1, -10], prefix products = [-3, 3, -30], suffix products = [-30, 10, -10]
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans = std::max(ans, suffix_product *= nums[i]);
            if (suffix_product == 0) {  // or nums[i] == 0
                suffix_product = 1;
            }
        }

        return ans;
    }
};
// @lc code=end

