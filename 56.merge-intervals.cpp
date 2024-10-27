/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(log(n)) (introsort space complexity)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Sort by start time and then end time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        int cur_start = intervals[0][0],
            cur_end = intervals[0][1];        
        for (int i = 1; i < intervals.size(); ++i) {
            int start = intervals[i][0], 
                end = intervals[i][1];
            if (start > cur_end) {
                // No overlap, start a new interval
                res.push_back({cur_start, cur_end});
                cur_start = start;
                cur_end = end;
            } else if (end > cur_end) {
                // Partly overlap, extend the current interval
                cur_end = end;
            } 
            // else: intervals[i] is entirely covered by 
            // [cur_start, cur_end]. Do nothing.
        }
        // Do NOT forget the final interval
        res.push_back({cur_start, cur_end});
        return res;
    }
};
// @lc code=end

