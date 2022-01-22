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
        for (const auto &x : nums) {
            // Either append the current number to the subarray by adding it to the subarray sum,
            // or start a new subarray by assigning the current number to the subarray sum. 
            dp = max(dp + x, x);
            ans = max(ans, dp);
        }
        return ans;
    }
};
// @lc code=end

