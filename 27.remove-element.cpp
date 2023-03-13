/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int x : nums) {
            if (x != val) {
                nums[i++] = x;
            }
        }
        return i;
    }
};
// @lc code=end

