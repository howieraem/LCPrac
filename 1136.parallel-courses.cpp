/*
 * @lc app=leetcode id=1136 lang=cpp
 *
 * [1136] Parallel Courses
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
#define NOT_VISITED -1
#define VISITED 1
#define VISITING 0

class Solution {
    static bool dfs(int i, const vector<vector<int>> &A, vector<int> &depth, vector<int> &vis) {
        if (vis[i] == VISITED)  return true;
        else if (vis[i] == VISITING)  return false;   // graph loop found
        vis[i] = VISITING;
        for (const int &next : A[i]) {
            if (!dfs(next, A, depth, vis))  return false;
            depth[i] = max(depth[i], depth[next] + 1);
        }
        vis[i] = VISITED;
        return true;
    }

public:
    // DFS-based topological sort
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> A(n);
        for (const auto &e : relations) {
            A[e[0] - 1].push_back(e[1] - 1);
        }
        vector<int> depth(n, 1);
        vector<int> vis(n, NOT_VISITED);
        for (int i = 0; i < n; ++i) {
            if (!dfs(i, A, depth, vis))  return -1;
        }
        return *max_element(depth.begin(), depth.end());
    }

    /*
    // BFS-based topological sort
    // T: O(V + E)
    // S: O(V + E)
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        int inDeg[n];
        memset(inDeg, 0, sizeof(inDeg));
        vector<vector<int>> A(n);
        for (const auto &e : relations) {
            ++inDeg[e[1] - 1];
            A[e[0] - 1].push_back(e[1] - 1);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!inDeg[i])  q.push(i);
        }

        int nSem = 0;
        while (q.size()) {
            for (int sz = q.size(); sz > 0; --sz) {
                int pre = q.front(); q.pop();
                --n;
                for (const int &next : A[pre]) {
                    // Add to queue if the in-degree of the neighbor node becomes 0
                    if (!--inDeg[next])  q.push(next);
                }
            }
            ++nSem;
        }
        return !n ? nSem : -1;
    }
    */
};
// @lc code=end

