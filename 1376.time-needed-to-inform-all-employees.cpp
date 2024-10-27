/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // DFS
    // T: O(n)
    // S: O(n)
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        // Directed graph
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        return dfs(graph, headID, informTime);
    }

private:
    int dfs(const vector<vector<int>>& graph, int u, const vector<int>& informTime) {
        int ans = 0;
        for (const int& v : graph[u]) {
            ans = std::max(ans, dfs(graph, v, informTime));
        }
        return ans + informTime[u];  // cost to visit current node and all children
    }
};
// @lc code=end

