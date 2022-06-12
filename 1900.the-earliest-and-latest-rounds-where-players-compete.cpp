/*
 * @lc app=leetcode id=1900 lang=cpp
 *
 * [1900] The Earliest and Latest Rounds Where Players Compete
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Simulate all possible elimination cases
    // T: O(2 ^ n)
    // S: O(log(n)) recursion stack
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int min_round = INT_MAX, max_round = INT_MIN;

        // Since n <= 28, use an integer mask to represent the elimination state.
        std::function<void(int,int,int,int)> dfs = 
                [&](int i, int j, int cur_round, int eliminate_mask) {

            // Linearly skip the eliminated ones
            while (i < j && (eliminate_mask & (1 << i)))  ++i;
            while (i < j && (eliminate_mask & (1 << j)))  --j;

            if (i >= j) {
                // cur_round ends
                dfs(1, n, cur_round + 1, eliminate_mask);
            } else if (i == firstPlayer && j == secondPlayer) {
                min_round = std::min(min_round, cur_round);
                max_round = std::max(max_round, cur_round);
            } else {
                if (i != firstPlayer && i != secondPlayer) {
                    // Case 1: i fails and j wins
                    dfs(i + 1, j - 1, cur_round, eliminate_mask | (1 << i));
                }

                if (j != firstPlayer && j != secondPlayer) {
                    // Case 2: i wins and j fails
                    dfs(i + 1, j - 1, cur_round, eliminate_mask | (1 << j));
                }
            }
        };

        dfs(1, n, 1, 0);
        return {min_round, max_round};
    }
};
// @lc code=end

