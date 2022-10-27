/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(V + E)
    // S: O(V + E)
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            dfs(i, i, adj, res);
        }
        return res;
    }

    void dfs(int u, const int& s, const vector<vector<int>>& adj, vector<vector<int>>& res) {
        for (const auto& v : adj[u]) {
            if (res[v].empty() || res[v].back() != s) {  // avoid infinite stack if there's a cycle
                res[v].push_back(s);
                dfs(v, s, adj, res);
            }
        }
    }
};
// @lc code=end
