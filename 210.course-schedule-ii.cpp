/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int inDeg[numCourses];
        memset(inDeg, 0, sizeof(inDeg));
        vector<vector<int>> A(numCourses);
        for (auto &edge : prerequisites) {
            ++inDeg[edge[0]];
            A[edge[1]].push_back(edge[0]);
        }

        // Topological sort using BFS
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!inDeg[i]) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int pre = q.front(); q.pop();
            --numCourses;
            res.push_back(pre);

            for (const int &cur : A[pre]) {
                if (!(--inDeg[cur]))  q.push(cur);
            }
        }
        // If not all courses (node) have been visited, then 
        // there must exist a loop.
        return numCourses ? vector<int>() : res;
    }
};
// @lc code=end

