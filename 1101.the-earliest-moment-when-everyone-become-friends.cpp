/*
 * @lc app=leetcode id=1101 lang=cpp
 *
 * [1101] The Earliest Moment When Everyone Become Friends
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
    class UF {
        int cnt;
        vector<int> parent, size;

    public:
        UF(int n) : cnt(n), parent(n), size(n, 1) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;  // a node's parent is itself initially
            }
        }

        bool connect(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ)  return false;  // already connected

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
            return true;
        }

        bool all_connected() {
            return cnt == 1;
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

public:
    // T: O(V + E * (log(E) + a(V))), V := n, E := len(logs), a() := Inverse Ackermann Function (grows slowly, can be treated as a constant and thus ignored)
    // S: O(V)
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // sort by timestamp
        std::sort(logs.begin(), logs.end(), [] (const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; } );

        UF uf(n);
        for (const auto& log : logs) {
            uf.connect(log[1], log[2]);
            if (uf.all_connected()) return log[0];
        }
        return -1;
    }
};
// @lc code=end

