/*
 * @lc app=leetcode id=294 lang=cpp
 *
 * [294] Flip Game II
 */
#include <bits/stdc++.h>

using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // Memoized DFS + backtracking
    // T: O(2 ^ n)
    // S: O(2 ^ n)
    bool canWin(string currentState) {
        unordered_map<string, bool> memo;
        return backtrack(currentState, memo);
    }

    bool backtrack(string state, unordered_map<string, bool>& memo) {
        auto cache_it = memo.find(state);
        if (cache_it != memo.end()) {
            return cache_it->second;
        }
        const int last = (int)state.size() - 2;
        for (int i = 0; i <= last; ++i) {
            if (state[i] == '+' && state[i + 1] == '+') {
                state[i] = '-';
                state[i + 1] = '-';
                // take turn, so need to negate every time
                bool current_turn_win = !backtrack(state, memo);
                state[i] = '+';
                state[i + 1] = '+';

                // IMPORTANT: must undo change before returning
                // to account for all possibilities
                if (current_turn_win) {
                    memo[state] = true;
                    return true;
                }
            }
        }
        memo[state] = false;
        return false;
    }
};
// @lc code=end

