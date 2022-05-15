/*
 * @lc app=leetcode id=1762 lang=cpp
 *
 * [1762] Buildings With an Ocean View
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(N)
    // S: O(1)
    std::vector<int> findBuildings(std::vector<int>& heights) {
        std::vector<int> res;
        int last = INT_MIN;
        for (int i = heights.size() - 1; i >= 0; --i) {
            if (heights[i] > last) {
                res.push_back(i);
                last = heights[i];
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

