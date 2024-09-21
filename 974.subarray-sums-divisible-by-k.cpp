/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(k)
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> prefix_sum_mod_freq(k);
        prefix_sum_mod_freq[0] = 1;
        int ans = 0, prefix_sum_mod = 0;

        // Math: suppose 0 <= i < j < n, 
        // if sum[0...i] % k == sum[0...j] % k,
        // then sum[i+1...j] is divisible by k.
        for (int x : nums) {
            prefix_sum_mod = (prefix_sum_mod + x) % k;
            if (prefix_sum_mod < 0) {
                // convert negative mod to positive
                // e.g. -2 % 5 = -2 -> 3
                prefix_sum_mod += k;
            }
            ans += prefix_sum_mod_freq[prefix_sum_mod]++;
        }
        return ans;
    }
};
// @lc code=end

