/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int sz = 1;
        int cnt = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++cnt;
            } else {
                cnt = 1;
            }

            if (cnt <= 2) {
                // copy and overwrite if count is less than threshold
                nums[sz++] = nums[i];
            } // ignore numbers with a higher cnt 
        }
        return sz;
    }
};
// @lc code=end

