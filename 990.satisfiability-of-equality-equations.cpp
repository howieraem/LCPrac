/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
    class UF {
    vector<int> parent, rank;

    public:
        UF(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        bool connect(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ)  return false;  // already connected

            // Re-balance height by connecting the smaller graph to the larger graph,
            // to avoid building a linked list
            if (rank[rootP] > rank[rootQ]) {
                parent[rootQ] = rootP;
                ++rank[rootP];
            } else {
                parent[rootP] = rootQ;
            }
            return true;
        }

        bool connected(int p, int q) {
            return find(p) == find(q);
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

public:
    // T: O(n * a(s)), n := len(equations), s := alphabet size, a() := inverse Ackermann func
    // S: O(s)
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);

        // connect all equal equations
        for (const auto& eqn : equations) {
            if (eqn[1] == '=') {
                uf.connect(eqn[0] - 'a', eqn[3] - 'a');
            }
        }

        // check if there exist an inequality conflict
        for (const auto& eqn : equations) {
            if (eqn[1] == '!' && uf.connected(eqn[0] - 'a', eqn[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

