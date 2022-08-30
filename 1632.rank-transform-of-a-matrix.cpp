/*
 * @lc app=leetcode id=1632 lang=cpp
 *
 * [1632] Rank Transform of a Matrix
 */
#include <bits/stdc++.h>

using std::map;
using std::unordered_map;
using std::vector;

// @lc code=start
using pos = std::pair<int, int>;

class Solution {
    class UF {
        vector<int> parent, rank;

    public:
        UF(int n) {
            parent = vector<int>(n);
            rank = vector<int>(n);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;  // a node's parent is itself initially
            }
        }

        pos connect(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP != rootQ) {
                // Re-balance height by connecting the smaller graph to the larger graph,
                // to avoid building a linked list
                if (rank[rootP] < rank[rootQ]) {
                    parent[rootP] = rootQ;
                } else {
                    parent[rootQ] = rootP;
                    ++rank[rootP];
                    return {rootQ, rootP};  // IMPORTANT
                }
            }
            return {rootP, rootQ};
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
    // T: O(m * n * (log(m * n) + (m + n) + a(m + n))), a() := Inverse Ackermann Function
    // S: O(m * n)
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size(), tot = m + n;
        map<int, vector<pos>> value_to_pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                value_to_pos[matrix[i][j]].push_back({i, j});
            }
        }
        
        vector<int> rank(tot, 0);
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (const auto& p : value_to_pos) {
            UF uf(tot);

            vector<int> tmp(rank);
            for (const auto& [r, c] : p.second) {
                pos parents = uf.connect(r, c + m);  // Offset column by m so that it's unique in UF
                // Update the ranks on a temporary copy instead
                tmp[parents.second] = std::max(tmp[parents.first], tmp[parents.second]);
            }

            for (const auto& [r, c] : p.second) {
                // Update rank and res[r][c] with the maximum rank value of parent + 1 which is the next minimum possible rank
                rank[r] = rank[c + m] = res[r][c] = tmp[uf.find(r)] + 1;  // same as tmp[uf.find(c + m)] + 1
            }
        }
        return res;
    }
};
// @lc code=end

