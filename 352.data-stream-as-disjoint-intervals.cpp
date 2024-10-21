/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
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
        int l = *nums.begin();
        int r = *nums.begin();
        for (const int& x : nums) {
            if (x > r + 1) {
                res.push_back({l, r});
                l = x;
            }
            r = x;
        }
        // do NOT forget last interval
        res.push_back({l, r});
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

