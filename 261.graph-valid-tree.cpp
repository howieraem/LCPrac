/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // Solution based on Union-Find
    // T: O(n * a(n)) ~= O(n), a(n) := Inverse Ackermann Function (grows slowly, can be treated as a constant)
    // S: O(n)
    bool validTree(int n, vector<vector<int>>& edges) {
        // Check if any nodes not connected or if there exist duplicate edge(s)
        if (edges.size() != (n - 1))  return false;

        vector<int> nodes(n, 0);
        for (int i = 0; i < n; ++i)  nodes[i] = i;
        for (const auto &e : edges) {
            int v1 = e[0], v2 = e[1];
            while (nodes[v1] != v1) {
                nodes[v1] = nodes[nodes[v1]];   // path compression
                v1 = nodes[v1];
            }
            while (nodes[v2] != v2) { 
                nodes[v2] = nodes[nodes[v2]];   // path compression
                v2 = nodes[v2];
            }
            if (nodes[v1] == nodes[v2])  return false;  // cycle found
            nodes[v2] = v1;     // might consider rank/weight/size here
        }
        return true;
    }
};
// @lc code=end

