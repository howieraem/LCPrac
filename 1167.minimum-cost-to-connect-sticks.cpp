/*
 * @lc app=leetcode id=1167 lang=cpp
 *
 * [1167] Minimum Cost to Connect Sticks
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Since some sticks' lengths are counted more than others when 
    // calculating the total loss, we should use short sticks first.
    // T: O(n * log(n))
    // S: O(n)
    int connectSticks(vector<int>& sticks) {
        int ans = 0;
        /*
        std::make_heap(sticks.begin(), sticks.end(), std::greater<int>());
        while (sticks.size() > 1) {
            std::pop_heap(sticks.begin(), sticks.end(), std::greater<int>());
            int shortest1 = sticks.back(); sticks.pop_back();
            std::pop_heap(sticks.begin(), sticks.end(), std::greater<int>());
            int shortest2 = sticks.back(); sticks.pop_back();
            int new_stick = shortest1 + shortest2;
            ans += new_stick;
            sticks.push_back(new_stick);
            std::push_heap(sticks.begin(), sticks.end(), std::greater<int>());
        }
        */

        std::priority_queue<int, vector<int> , std::greater<int>> min_heap(
                sticks.begin(), sticks.end());
        while (min_heap.size() > 1) {
            int shortest1 = min_heap.top(); min_heap.pop();
            int shortest2 = min_heap.top(); min_heap.pop();
            int new_stick = shortest1 + shortest2;
            ans += new_stick;
            min_heap.push(new_stick);
        }
        return ans;
    }
};
// @lc code=end

