/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
// Interval + Sorted Set 
// S: O(n)
class SummaryRanges {
    std::set<int> nums;

public:
    SummaryRanges() {}
    
    // T: O(log(n))
    void addNum(int value) {
        nums.emplace(value);
    }
    
    // T: O(n), works for integer values
    vector<vector<int>> getIntervals() {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> res;
        int cur_start = *nums.begin();
        int cur_end = *nums.begin();
        for (const int& start : nums) {
            if (start > cur_end + 1) {
                res.push_back({cur_start, cur_end});
                cur_start = start;
                cur_end = start;
            } else {
                cur_end = start;
            }
        }
        // do NOT forget last interval
        res.push_back({cur_start, cur_end});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

