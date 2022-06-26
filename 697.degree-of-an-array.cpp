/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> cnts, first_idx;
        int deg = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first_idx.find(nums[i]) == first_idx.end()) {
                first_idx[nums[i]] = i;
            }
            if (++cnts[nums[i]] > deg) {
                deg = cnts[nums[i]];
                ans = i - first_idx[nums[i]] + 1;
            } else if (cnts[nums[i]] == deg) {
                ans = std::min(ans, i - first_idx[nums[i]] + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

