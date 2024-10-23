/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Variant of sorted two sum Q167
    // Two pointers and pre-computed powers
    // T: O(n * log(n))
    // S: O(n) avoid pow overflow
    int numSubseq(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        const int MOD = 1000000007;
        const int n = nums.size();
        
        // precompute pow with MOD to avoid dtype overflow
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) {
            pows[i] = (pows[i - 1] << 1) % MOD;
        }

        int l = 0;
        int r = n - 1;
        int ans = 0;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                --r;
            } else {
                // There are 2^(r - l) subsequences eligible,
                // e.g. [l], [l, l + 1], ..., [l, l + 1, ..., r]
                ans = (ans + pows[r - l++]) % MOD;
            }
        }
        return ans;
    }
};
// @lc code=end

