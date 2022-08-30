/*
 * @lc app=leetcode id=1272 lang=cpp
 *
 * [1272] Remove Interval
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for (auto& interval : intervals) {
            if (interval[1] <= toBeRemoved[0] || interval[0] >= toBeRemoved[1]) {
                // no overlap
                res.push_back(std::move(interval));
            } else {
                if (interval[0] < toBeRemoved[0]) {
                    // left end no overlap
                    res.push_back({interval[0], toBeRemoved[0]});
                }
                if (interval[1] > toBeRemoved[1]) {
                    // right end no overlap
                    res.push_back({toBeRemoved[1], interval[1]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

