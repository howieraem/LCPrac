/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (const int& n: nums)  sum += n;
        if (abs(S) > abs(sum))  return 0;
        int len = nums.size();
        int bound = sum*2 + 1;  // [-sum, sum] incl. 0
        vector<vector<int>> dp(len, vector<int>(bound));
        
        // base
        if (nums[0] == 0)
            dp[0][sum] = 2;
        else {
            dp[0][sum+nums[0]] = 1;
            dp[0][sum-nums[0]] = 1;
        }
        
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < bound; ++j) {
                int left = (j-nums[i]) >= 0 ? j-nums[i] : 0;
                int right = (j+nums[i]) < bound ? j+nums[i] : 0;
                dp[i][j] = dp[i-1][left] + dp[i-1][right];
            }
        }
        return dp[len-1][sum+S];
    }
};
// @lc code=end
int main() {
    vector<int> inp = {2, 107, 109, 113, 127, 131, 137, 3, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 47, 53};
    cout << Solution().findTargetSumWays(inp, 33) << endl;
}
