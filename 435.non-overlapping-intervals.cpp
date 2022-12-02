/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // The problem is equivalent to "Given a collection of intervals, 
    // find the maximum number of non-overlapping intervals."
    // T: O(n * log(n))
    // S: O(log(n)) for sorting
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();

        // Sort by interval ends ascending. Given two overlapping intervals, 
        // we can only keep one, the question is which one should we keep?
        // Obviously we want to keep the one with smaller end, because we'll 
        // have higher chance of putting more non-overlapping intervals behind it.
        std::sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
                return interval1[1] < interval2[1];
        });

        /*
        int& cur_end = intervals[0][1];
        int non_overlap_cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (cur_end <= intervals[i][0]) {
                cur_end = intervals[i][1];
                ++non_overlap_cnt;
            }
        }

        // Prove n - n_max_compatible_intervals = n_minimum_deletions: 
        // Suppose interval x in the latter max compatible set B and x causes two other intervals be deleted. 
        // If we delete x instead and insert those two deleted intervals to B, we can obtain a larger set, 
        // then it contradicts that B is the max compatible intervals.
        return n - non_overlap_cnt;
        */

        // Alternative solution without subtraction
        int& cur_end = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (cur_end > intervals[i][0]) {
                // has overlap, remove the one ends earlier
                ++ans;
            } else {
                // no overlap, update end point
                cur_end = intervals[i][1];
            }
        }
        return ans;
    }
};
// @lc code=end

