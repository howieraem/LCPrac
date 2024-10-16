/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // lists already sorted and disjoint
        const int m = firstList.size();
        const int n = secondList.size();
        if (m == 0 || n == 0) {
            return {};
        }
        
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];
            int s2 = secondList[j][0];
            int e2 = secondList[j][1];

            // check intersection
            int s = std::max(s1, s2);
            int e;
            if (e1 > e2) {
                e = e2;
                ++j;
            } else {
                e = e1;
                ++i;
            }
            if (s <= e) {
                res.push_back({s, e});
            }
        }
        return res;
    }
};
// @lc code=end

