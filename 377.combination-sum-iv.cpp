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
        // while Q518 asks for unique combinations
        for (int i = 1; i <= target; ++i) {
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
};
// @lc code=end

