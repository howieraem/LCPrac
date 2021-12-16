/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n), S: O(1)
    int singleNumber(vector<int>& nums) {
        int mask = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            mask ^= nums[i];
        }
        return mask;
    }
};
// @lc code=end

