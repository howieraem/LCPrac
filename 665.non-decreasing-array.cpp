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
                if ((incr_cnt++ > 0) ||   // Case 1: more than 1 anti-pattern
                    (i > 1 && i < nums.size() - 1 && nums[i] < nums[i - 2] && nums[i + 1] < nums[i - 1])) {
                    // Case 2: If only one modification is allowed, it's impossible to fix the following: 
                    // nums[i - 2] > nums[i] && nums[i] < nums[i - 1] && nums[i - 1] > nums[i + 1]
                    // Example: nums[i - 2:i + 2] = [3, 4, 2, 3]
                    // https://i.imgur.com/IKOSWmR.png
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

