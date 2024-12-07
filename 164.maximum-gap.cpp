/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Variant of bucket sort
    // T: O(n)
    // S: O(n)
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        // Get the value range of nums
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < n; ++i) {
            min = std::min(min, nums[i]);
            max = std::max(max, nums[i]);
        }

        if (max == min) {
            // IMPORTANT edge case: all nums equal
            return 0;
        }
        
        int bucket_width = static_cast<int>(std::ceil((max - min) / (n - 1.0)));
        vector<int> bucket_mins(n, INT_MAX);
        vector<int> bucket_maxs(n, INT_MIN);
        
        // Update max and min for each bucket
        for (const int& x: nums) {
            int bucket_idx = (x - min) / bucket_width;
            bucket_mins[bucket_idx] = std::min(bucket_mins[bucket_idx], x);
            bucket_maxs[bucket_idx] = std::max(bucket_maxs[bucket_idx], x);
        }

        int ans = bucket_width;  // the lower bound of gap must equal bucket width
        int pre_max = bucket_maxs[0];  // the first bucket must be involved and not empty because of min
        for (int i = 1; i < n; ++i) {
            if (bucket_mins[i] == INT_MAX) {
                // bucket not updated by any nums, empty bucket
                continue;
            }

            ans = std::max(ans, bucket_mins[i] - pre_max);
            pre_max = bucket_maxs[i];
        }

        return ans;
    }
};
// @lc code=end

