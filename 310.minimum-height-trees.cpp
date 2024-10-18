/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Topological sort
    // T: O(V + E)
    // S: O(V + E)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0) {
            return {};
        }
        if (n == 1) {
            return {0};
        }

        // The roots of MHT must be the mid point(s) of the longest leaf to leaf path in the tree.
        // To find the longest path, we can first find the farthest leaf from any node, and then find
        // the farthest leaf from the node found above. Then these two nodes we found are the end points
        // of the longest path. And last, we find the centers of the longest path.
        // If there are 3 roots all with shortest path, there has to be a loop and thus 
        // the graph is not a tree.
        vector<int> deg(n);
        vector<vector<int>> adj(n, vector<int>());
        for (const auto& e : edges) {
            // undirected graph
            ++deg[e[0]];
            ++deg[e[1]];
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                // leaf nodes
                q.push(i);
            }
        }

        vector<int> res;

        int remain = n;
        while (remain > 2 && !q.empty()) {
            int sz = q.size();
            remain -= sz;
            while (sz-- > 0) {
                int cur = q.front(); q.pop();
                for (int neighbor : adj[cur]) {
                    if ((--deg[neighbor]) == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};
// @lc code=end

