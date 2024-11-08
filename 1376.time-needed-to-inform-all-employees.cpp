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
        // N-ary tree / Directed graph
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                // edge: manager -> employee
                graph[manager[i]].push_back(i);
            }
        }
        return dfs(graph, headID, informTime);
    }

private:
    // post-order traversal of n-ary tree
    int dfs(const vector<vector<int>>& graph, int node, const vector<int>& informTime) {
        int ans = 0;
        for (const int& child : graph[node]) {
            ans = std::max(ans, dfs(graph, child, informTime));
        }
        return ans + informTime[node];  // cost to visit current node and all children (worst of all children)
    }
};
// @lc code=end

