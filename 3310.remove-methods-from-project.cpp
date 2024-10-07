#include <bits/stdc++.h>

using std::vector;

class Solution {
    void dfs(int node, const vector<vector<int>>& adj, vector<uint8_t>& vis) {
        vis[node] = 1;
        for (const int& child : adj[node]) {
            if (vis[child] == 0) {
                dfs(child, adj, vis);
            }
        }
    }

    bool check_extern_invoke(const vector<vector<int>>& adj, vector<uint8_t>& vis) {
        for (int i = 0; i < adj.size(); ++i) {
            if (vis[i] == 0) {
                for (const auto& child : adj[i]) {
                    if (vis[child] == 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    // T: O(V + E)
    // S: O(V + E)
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n, vector<int>());
        for (const auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<uint8_t> vis(n);

        // find all methods invoked by k
        dfs(k, adj, vis);

        vector<int> res;
        if (check_extern_invoke(adj, vis)) {
            // cannot remove suspicious node group if it is invoked by any external nodes
            res.reserve(n);
            for (int i = 0; i < n; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};