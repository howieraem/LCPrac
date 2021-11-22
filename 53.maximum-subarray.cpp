/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = 0, ans = INT_MIN;
        for (auto &x : nums) {
            ans = max(ans, dp = max(dp + x, x));
        }
        return ans;
    }
};
// @lc code=end

