/*
 * @lc app=leetcode id=1827 lang=cpp
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, pre = 0;
        for (const auto &cur : nums) {
            if (cur > pre) {
                pre = cur;
            } else {
                ++pre;  // add 1 for strictly increasing
                ans += (pre - cur);
            }
        }
        return ans;
    }
};
// @lc code=end

