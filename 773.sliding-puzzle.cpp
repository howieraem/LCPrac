/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
    // Note: if the grid dimensions are variable, need to programmatically 
    // find the following
    static const int M = 2, N = 3;
    static const inline vector<vector<int>> NEXT_IDS = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {3, 1, 5},
        {4, 2}
    };
    static const inline string FINAL_STATE = "123450";  // only works when for numbers less than 10

public:
    // Minimum number of moves -> BFS. Need to refactor the data to apply BFS more conveniently.
    int slidingPuzzle(vector<vector<int>>& board) {
        string state;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                state.push_back('0' + board[i][j]);
            }
        }

        // Need to check here if inside the BFS loop the check is not 
        // performed right after queue.pop() but before checking visited
        if (state == FINAL_STATE)  return 0;

        unordered_set<string> vis;
        queue<string> q;
        q.push(state);
        vis.insert(state);
        int moves = 0;

        while (!q.empty()) {
            int qs = q.size();
            while (qs--) {
                string s = q.front(); q.pop();
                int idx_0 = 0;
                while (s[idx_0] != '0')  ++idx_0;
                for (const auto &next : NEXT_IDS[idx_0]) {
                    string ns = s;
                    swap(ns[idx_0], ns[next]);
                    if (ns == FINAL_STATE)  return moves + 1;
                    if (vis.find(ns) == vis.end()) {
                        q.push(ns);
                        vis.insert(ns);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};
// @lc code=end

