/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1
    // T: O(n * k)
    // S: O(n)
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();

        // dp[i] means the maximum sum after partitioning for arr[:i+1]
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            int cur_max_num = 0, cur_max_sum = 0;
            for (int j = 1; j <= k && j <= i; ++j) {
                cur_max_num = max(cur_max_num, arr[i - j]);
                cur_max_sum = max(cur_max_sum, dp[i - j] + cur_max_num * j);
            }
            dp[i] = cur_max_sum;
        }
        return dp[n];
    }
    */

    // Solution 2: same time complexity as solution 1 (bit more time for modulus computation),
    // but better space complexity.
    // T: O(n * k)
    // S: O(k)
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();

        // Find the prefix maximum sum at each interval/subarray instead of at each element.
        vector<int> dp(k);

        for (int i = 1; i <= n; ++i) {
            int cur_max_num = 0, cur_max_sum = 0;
            for (int j = 1; j <= k && j <= i; ++j) {
                cur_max_num = max(cur_max_num, arr[i - j]);
                cur_max_sum = max(cur_max_sum, dp[(i - j) % k] + cur_max_num * j);
            }
            dp[i % k] = cur_max_sum;
        }
        return dp[n % k];
    }
};
// @lc code=end

