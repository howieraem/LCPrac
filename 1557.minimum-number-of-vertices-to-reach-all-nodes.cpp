/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Find the minimum set of nodes that can reach all other nodes
    // The answer is the nodes with 0 in-degree for a DAG.
    // T: O(V + E)
    // S: O(V)
    vector<int> findSmallestSetOfVertices(int n, const vector<vector<int>>& edges) {
        vector<uint8_t> nonzero_in_deg(n);
        for (const auto& e : edges) {
            nonzero_in_deg[e[1]] = 1;
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!nonzero_in_deg[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

