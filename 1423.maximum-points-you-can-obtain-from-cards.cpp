/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Sliding window + prefix sum
    // The problem is equivalent to finding the subarray with the minimum sum.
    // The actual answer is sum(cardPoints) - sum of that subarray. 
    // Unlike Q918, the window size is fixed here, and points are positive.
    // T: O(n)
    // S: O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        const size_t N = cardPoints.size();
        int subarr_sz = N - k;
        int min_subarr_sum = INT_MAX; 
        int cur_subarr_sum = 0; 
        int sum = 0;

        // Sliding-window (only works if all card points are non-negative)
        int l = 0;
        for (int r = 0; r < N; ++r) {
            sum += cardPoints[r];
            cur_subarr_sum += cardPoints[r];
            int cur_window_sz = r - l + 1;
            if (cur_window_sz > subarr_sz) {
                cur_subarr_sum -= cardPoints[l++];
                --cur_window_sz;
            }
            if (cur_window_sz == subarr_sz) {
                min_subarr_sum = std::min(min_subarr_sum, cur_subarr_sum);
            }
        }
        return sum - min_subarr_sum;
    }

    // Alternative approach: calculate prefix and suffix sums for cardPoints,
    // and maximize prefix_sum[i] + suffix_sum[k - i] for i in range k.
};
// @lc code=end

