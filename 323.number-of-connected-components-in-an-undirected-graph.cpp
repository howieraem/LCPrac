/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Plain DFS solution without union find (can also replace DFS with BFS)
    // T: O(V + E)
    // S: O(V + E)
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<uint8_t> vis(n, 0);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += !vis[i] && dfs(i, adj, vis);
        }
        return ans;
    }

    int dfs(int u, const vector<vector<int>>& adj, vector<uint8_t>& vis) {
        for (const int& v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dfs(v, adj, vis);
            }
        }
        return 1;
    }
};
// @lc code=end

