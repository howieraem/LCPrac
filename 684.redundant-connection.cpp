/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
#include <vector>

using std::vector;

// @lc code=start
class UF {
    vector<int> parent, rank;

public:
    UF(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // a node's parent is itself initially
        }
    }

    bool connect(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ)  return false;  // already connected

        // Re-balance height by connecting the smaller graph to the larger graph,
        // to avoid building a linked list
        if (rank[rootP] > rank[rootQ]) {
            parent[rootQ] = rootP;
            rank[rootP] += rank[rootQ];
        } else {
            parent[rootP] = rootQ;
            rank[rootQ] += rank[rootP];
        }
        return true;
    }

private:
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
    // T: O(n), n := len(edges)
    // S: O(n)
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf(edges.size() + 1);    // 1-indexed vertices
        for (const auto &e : edges) {
            if (!uf.connect(e[0], e[1])) {
                return e;
            }
        }
        return {};
    }
};
// @lc code=end

