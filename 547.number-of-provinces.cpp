/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class UF {
    int cnt;  // number of disjoint sets
    vector<int> parent, size;

public:
    UF(int n) : parent(n), size(n, 1), cnt(n) {
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
        --cnt;
    }

    int count() const {
        return cnt;
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
    // Solution based on union find
    // T: O(V ^ 2) or O(E); Ackermann function can be ignored
    // S: O(V)
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        UF uf(n);
        for (int i = 0; i < n; ++i) {
            // Only need to iterate til i because isConnected[i][j] = isConnected[j][i]
            for (int j = 0; j < i; ++j) {
                if (isConnected[i][j]) {
                    uf.connect(i, j);
                }
            }
        }
        return uf.count();
    }
};
// @lc code=end

