/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */
#include <unordered_map>
#include <vector>

using std::unordered_map;
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
    /**
     * Properties of the directed tree after one edge removed:
     * 1. one and only one root, and root does not have parent;
     * 2. each non-root node has exactly one parent;
     * 3. there is no cycle, which means any path will reach the end by moving at most (n-1) steps along the path.
     */
    // T: O(n), n := len(edges)
    // S: O(n)
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // If we can remove exactly 1 edge to achieve the tree structure, 
        // a single node can have at most two parents. Denote the corresponding
        // edges as candidates 1 and 2.
        vector<int> cand1, cand2;
        unordered_map<int, vector<int>> pointTo;    // key is a vertex, value is an incoming edge to that vertex

        for (const auto &e : edges) {
            if (pointTo.find(e[1]) != pointTo.end()) {
                cand1 = pointTo[e[1]];
                cand2 = e;
                break;
            }
            pointTo[e[1]] = e;
        }

        // If there is a cycle and dual parents, then one of the candidate edges is on the cycle. 
        // If you can complete the cycle without the second candidate, then it must be the first, 
        // if you can't then it must be the second. If there is no cycle, you want the second 
        // candidate anyway, so the answer is the same as if the cycle included the second candidate.
        UF uf(edges.size() + 1);
        for (const auto &e : edges) {
            if (e == cand2) {
                continue;
            }
            if (!uf.connect(e[0], e[1])) {
                return cand1.size() ? cand1 : e;
            }
        }
        return cand2;
    }
};
// @lc code=end

