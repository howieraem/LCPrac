/*
 * @lc app=leetcode id=2092 lang=cpp
 *
 * [2092] Find All People With Secret
 */
#include <bits/stdc++.h>

using std::unordered_set;
using std::map;
using std::vector;

// @lc code=start
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

        bool connect(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ)  return false;  // already connected

            // Re-balance height by connecting the smaller graph to the larger graph,
            // to avoid building a linked list
            if (rank[rootP] < rank[rootQ]) {
                parent[rootP] = rootQ;
            } else {
                parent[rootQ] = rootP;
                ++rank[rootP];
            }
            return true;
        }

        bool connected(int p, int q) {
            return find(p) == find(q);
        }

        // IMPORTANT
        void reset(int p) {
            parent[p] = p;
            rank[p] = 0;
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
    // T: O(m * log(m) + (m + n) * a(n)), m := len(meetings), a() := Inverse Ackermann Function
    // S: O(m + n)
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<int>> time_to_meeting_idxs;
        for (int i = 0; i < meetings.size(); ++i) {
            time_to_meeting_idxs[meetings[i][2]].push_back(i);
        }
    
        UF uf(n);
        uf.connect(0, firstPerson);

        unordered_set<int> pool;
        for (const auto& p : time_to_meeting_idxs) {
            pool.clear();
            for (const int& i : p.second) {
                auto meeting = meetings[i];
                uf.connect(meeting[0], meeting[1]);
                pool.insert(meeting[0]);
                pool.insert(meeting[1]);
            }

            // The current meeting shouldn't affect future meetings if people
            // don't know the secret.
            for (const int& i : pool) {
                if (!uf.connected(0, i)) uf.reset(i);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (uf.connected(0, i)) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

