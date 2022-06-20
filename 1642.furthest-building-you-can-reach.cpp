/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Strategy: use bricks for the smaller height differences, and 
    // ladders for the larger height differences.
    // T: O(n * log(n))
    // S: O(n)
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int last = heights.size() - 1;
        std::priority_queue<int, vector<int> , std::greater<int>> min_heap;
        for (int i = 0; i < last; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                min_heap.push(diff);
            }
            if (min_heap.size() > ladders) {
                bricks -= min_heap.top(); min_heap.pop();
            }
            if (bricks < 0) {
                return i;
            }
        }
        return last;
    }
};
// @lc code=end
