/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Solution without modifying the original array
    // T: O(n)
    // S: O(1)
    bool checkPossibility(vector<int>& nums) {
        int incr_cnt = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if ((incr_cnt++ > 0) || 
                    (i > 1 && i < nums.size() - 1 && nums[i] < nums[i - 2] && nums[i + 1] < nums[i - 1])) {
                    // If only one modification is allowed,
                    // it's impossible to fix this case: nums[i - 2] > nums[i] && nums[i - 1] > nums[i + 1]
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

