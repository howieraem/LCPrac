/*
 * @lc app=leetcode id=1913 lang=cpp
 *
 * [1913] Maximum Product Difference Between Two Pairs
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Math
    // T: O(n)
    // S: O(1)
    int maxProductDifference(vector<int>& nums) {
        if ((nums.size()) < 4) {
            return 0;   // sanity check
        }

        int top1 = INT_MIN;
        int top2 = INT_MIN;
        int bottom1 = INT_MAX;
        int bottom2 = INT_MAX;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > top1) {
                top2 = top1;
                top1 = nums[i];
            } else if (nums[i] > top2) {
                top2 = nums[i];
            }

            if (nums[i] < bottom1) {
                bottom2 = bottom1;
                bottom1 = nums[i];
            } else if (nums[i] < bottom2) {
                bottom2 = nums[i];
            }
        }

        return (top1 * top2) - (bottom1 * bottom2);
    }
};
// @lc code=end

