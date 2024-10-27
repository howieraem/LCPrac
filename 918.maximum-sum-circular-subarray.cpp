/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */
#include <bits/stdc++.h>

using std::max;
using std::min;
using std::vector;

// @lc code=start
class Solution {
public:
    // Kadane's algorithm / DP
    // nums contain negative numbers, cannot use sliding window
    // T: O(n)
    // S: O(1)
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Note: As the subarray may only include each element of  
        // the fixed buffer nums at most once, it is not feasible 
        // to use the modulo index trick i % n here.

        // Instead, there are two cases:
        // Case 1: subarr is not circular. Same as Q53.
        // Case 2: subarr is circular. Find the minimum sum of non-circular 
        // subarrays, so that the rest of the whole array (two subarrays, 
        // one on the left (prefix) and one on the right (suffix)) can form 
        // a circular subarr that has the maximum sum.
        // https://assets.leetcode.com/users/motorix/image_1538888300.png

        int dp_max = 0;  // dp_max[i] means local maximum for all subarrs of nums[:i + 1]
        int dp_min = 0;  // dp_min[i] means local minimum for all subarrs of nums[:i + 1]
        int global_max = INT_MIN;
        int global_min = INT_MAX;
        int sum = 0;

        for (const auto& x : nums) {
            sum += x;

            // Either append the current number to the subarray by adding it to the subarray sum,
            // or start a new subarray by assigning the current number to the subarray sum. 
            dp_max = max(dp_max + x, x);
            global_max = max(global_max, dp_max);

            // Similarly for minimum
            dp_min = min(dp_min + x, x);
            global_min = min(global_min, dp_min);
        }

        // IMPORTANT: an edge case is when all nums are negative, making global_max < 0 and 
        // sum - global_min == 0 (an empty subarr for minimum sum). In this case, we can 
        // only return global_max.
        if (global_max <= 0) {
            return global_max;
        }
        return max(global_max, sum - global_min);
    }
};
// @lc code=end

