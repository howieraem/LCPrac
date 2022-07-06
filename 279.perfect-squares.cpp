/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(sqrt(n) ^ 2) = O(n)
    // S: O(n)
    int numSquares(int n) {
        std::queue<int> q;
        std::unordered_set<int> vis;
        q.emplace(0);
        vis.insert(0);

        int depth = 0;
        while (q.size()) {
            int sz = q.size();
            ++depth;
            while (sz-- > 0) {
                int x = q.front(); q.pop();
                for (int i = 1; x + i * i <= n; ++i) {
                    int v = x + i * i;
                    if (v == n) return depth;
                    if (vis.find(v) == vis.end()) {
                        q.emplace(v);
                        vis.insert(v);
                    }
                }
            }
        }
        return depth;
    }
};
// @lc code=end

