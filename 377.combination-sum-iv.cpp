/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Knapsack problem (with replacements).
    // T: O(n * target)
    // S: O(target)
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t> dp((size_t)target + 1, 0);  // be aware of signed int overflow
        dp[0] = 1; // base case ensures dp[num] = 1 for num in nums

        // IMPORTANT Difference from Q518: This asks for unique permutations, 
        // while Q518 asks for unique combinations (e.g., [1, 2] and [2, 1] 
        // are considered the same in Q518 but not here)
        for (int i = 1; i <= target; ++i) {
            // Trying every possible way to add to the sum, and each sequence matters.
            for (const int& num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }

        /*
        // Possible optimization: if min(nums) is large and len(nums) is much less than target
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for (const int& num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        */

        return dp[target];
    }

    // Follow-up: What if nums contain negative numbers?
    // There should be extra constraint added to the problem:
    // Each number should be used once only, or either positive number 
    // or negative number should be used only once, otherwise there 
    // would be infinite possible combinations for some target number
};
// @lc code=end

