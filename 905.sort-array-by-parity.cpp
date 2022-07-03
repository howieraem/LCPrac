/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (!(nums[i] & 1)) {
                std::swap(nums[j++], nums[i]);
            }
            ++i;
        }
        return nums;
    }
};
// @lc code=end

