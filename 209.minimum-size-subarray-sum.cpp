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
        int ans = n + 1, windowSum = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            windowSum += nums[r];
            while (windowSum >= target) {
                ans = min(ans, r - l + 1);
                windowSum -= nums[l++];
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};
// @lc code=end

