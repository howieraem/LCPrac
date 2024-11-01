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

    // 2D coordinates flattened neighbor indices
    // i = x * N + y
    static const inline vector<vector<int>> NEXT_IDS = {
        {1, 3},       // (0, 0) can be swapped with (0, 1) -> i = 1, or (1, 0) -> i = 3
        {0, 2, 4},    // (0, 1) can be swapped with (0, 0) -> i = 0, (1, 1) -> i = 4,  or (0, 2) -> i = 2 
        {1, 5},
        {0, 4},
        {3, 1, 5},
        {4, 2}
    };
    static const inline string FINAL_STATE = "123450";  // only works when for numbers less than 10

public:
    // Graph BFS. Graph nodes represent the puzzle states (represented by 1D strings for hashing)
    // Minimum number of moves -> BFS. Need to refactor the data to apply BFS more conveniently.
    // T: O(m * n * (m * n)!)
    // S: O(m * n * (m * n)!)
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert board to 1D string
        string state;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                state.push_back('0' + board[i][j]);
            }
        }

        // Need to check here if inside the BFS loop the check is not 
        // performed right after queue.pop() but before checking visited
        if (state == FINAL_STATE) {
            return 0;
        }

        unordered_set<string> vis;
        queue<string> q;
        q.push(state);
        vis.insert(state);
        int moves = 0;

        while (!q.empty()) {
            int qs = q.size();
            while (qs-- > 0) {
                string s = q.front(); q.pop();
                int idx_0 = s.find('0');
                for (const auto &next : NEXT_IDS[idx_0]) {
                    // do movement
                    string ns = s;
                    swap(ns[idx_0], ns[next]);
                    if (ns == FINAL_STATE) {
                        return moves + 1;
                    }

                    // state not visited
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

/*
// Hash function of a vector (if board size is not constant) of positive ints
size_t operator() (std::vector<uint32_t> const& vec) const {
    std::size_t seed = vec.size();
    for(auto& i : vec) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}
*/
// @lc code=end

