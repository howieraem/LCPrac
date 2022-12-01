/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1) if not considering space required for output
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Although we can use binary search to find where to insert the new interval,
        // this question asks for all intervals after the insertion (and possible merges),
        // so we can't do better than O(n) overall.
        const int n = intervals.size();

        vector<vector<int>> res;
        res.reserve(n);

        int i = 0;

        // Intervals in front of the new interval (no overlap)
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(std::move(intervals[i++]));
        }

        // Merge intervals into the new interval if needed
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            ++i;
        }

        // Insert the new interval
        res.push_back(std::move(newInterval));

        // Intervals behind the new interval (no overlap)
        while (i < n) {
            res.push_back(std::move(intervals[i++]));
        }

        return res;
    }
};
// @lc code=end

