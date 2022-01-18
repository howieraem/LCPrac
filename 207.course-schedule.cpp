/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int inDeg[numCourses];
        memset(inDeg, 0, sizeof(inDeg));
        vector<vector<int>> A(numCourses);
        for (auto &edge : prerequisites) {
            ++inDeg[edge[0]];
            A[edge[1]].push_back(edge[0]);
            // Directed, do not write `A[edge[0]].push_back(edge[1]);`
        }

        // Topological sort using BFS
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!inDeg[i]) {
                q.push(i);
            }
        }

        while (q.size()) {
            for (int sz = q.size(); sz > 0; --sz) {
                int pre = q.front(); q.pop();
                --numCourses;

                for (const int &cur : A[pre]) {
                    if (!(--inDeg[cur]))  q.push(cur);
                }
            }
        }
        // If not all courses (node) have been visited, then 
        // there must exist a loop.
        return numCourses == 0;
    }
};
// @lc code=end

