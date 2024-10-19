/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class UF {
    vector<int> parent, size;

public:
    UF(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // a node's parent is itself initially
        }
    }

    void connect(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ)  return;  // already connected

        // Re-balance height by connecting the smaller graph to the larger graph,
        // to avoid building a linked list
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }

    int find(int x) {
        while (parent[x] != x) {
            // path compression
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

class Solution {
public:
    // T: O(V + E)
    // S: O(V)
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        UF uf(n);

        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                if (uf.find(i) == uf.find(j)) {
                    return false;
                }
                // Put all the nodes which are reachable from index i in one set
                uf.connect(graph[i][0], j);

                // Example: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
                // For index 0: 
                // The edges are 0-1, 0-2, 0-3, so we put the nodes 1, 2 and 3 in one set
                // and make 1 as the parent, and we put 0 in another set.
                // 
                // For index 1: 
                // Edge 1-0 is fine because parent(1) = 1 and parent(0) = 0 
                // so it still follows the rule of edge across 2 sets.
                // Edge 1-2 is not fine because parent(1) = 1 and parent(2) = 1 
                // since both parents are same we are sure that we have this edge 
                // within a set.
            }
        }
        return true;
    }
};
// @lc code=end

