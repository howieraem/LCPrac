/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // Solution based on sliding window (only works if nums are all positive)
    // T: O(n)
    // S: O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int ans = n + 1;  // default to an impossible length
        int window_sum = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            window_sum += nums[r];

            while (window_sum >= target) {
                ans = min(ans, r - l + 1);
                window_sum -= nums[l++];
            }
        }
        return ans == n + 1 ? 0 : ans;
    }

    /*
    // Follow-up, requiring T: O(n * log(n))
    // S: O(n)
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int ans = n + 1;
        vector<int> prefix_sums(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1];
        }

        for (int i = n; i >= 0 && prefix_sums[i] >= target; --i) {
            int j = std::upper_bound(
                    prefix_sums.begin(), prefix_sums.end(), prefix_sums[i] - target) - prefix_sums.begin();
            ans = std::min(ans, i - j + 1);
        }
        return ans == n + 1 ? 0 : ans;
    }
    */

    // Follow-up: negative numbers exist, see Q862
};
// @lc code=end

