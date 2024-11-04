/*
 * @lc app=leetcode id=2184 lang=cpp
 *
 * [2184] Number of Ways to Build Sturdy Brick Wall
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // 2D DP + backtracking + bit manipulation (because total width <= 10, small)
    // 1. Find all the valid rows to build a row of bricks, use bitmask to represent the boundaries
    // 2. Find all valid transitions from one row to another, which is easy to do with bitmasks. Adjacent rows r1 and r2 should have r1 & r2 == 0
    // 3. Build the wall bottom-up using the valid transitions
    // T: O(h * the number of row patterns), the number of row patterns is proportional to len(bricks)! ?
    // S: O(the number of row patterns ^ 2)
    int buildWall(int height, int width, vector<int>& bricks) {
        const long long MOD = 1000000007LL;
        
        // generate all possible permutations of bricks on one row 
        vector<int> row_masks;
        build_rows(0, width, bricks, 0, row_masks);

        // dp[x] means the number of ways of building the wall, with final row's pattern being bit mask x
        unordered_map<int, long long> dp;
        for (const int& mask : row_masks) {
            dp[mask] = 1LL;
        }

        // get possible next rows
        unordered_map<int, vector<int>> trans;
        for (const int& from : row_masks) {
            for (const int& to : row_masks) {
                // If from & to != 0, there is at least one common brick gap
                if (!(from & to)) {
                    trans[from].push_back(to);
                }
            }
        }

        // build wall row by row
        while (--height > 0) {
            unordered_map<int, long long> next_dp;
            for (const int& cur_row : row_masks) {
                long long cnt = 0;
                for (const int next_row : trans[cur_row]) {
                    cnt = (cnt + dp[next_row]) % MOD;
                }
                next_dp[cur_row] = cnt;
            }
            dp.swap(next_dp);
        }

        // Sum all possibilities of final row's count up
        long long ans = 0LL;
        for (const auto& p : dp) {
            ans = (ans + p.second) % MOD;
        }
        return (int) ans;
    }

private:
    // Backtracking
    // The i-th bit of the mask is 1 if there is a brick gap there, otherwise 0
    void build_rows(int cur_w, const int& max_w, const vector<int>& bricks, int cur_mask, vector<int>& masks) {
        for (const int& brick_w : bricks) {
            int new_w = cur_w + brick_w;
            if (new_w == max_w) {
                // Reached end of row
                masks.push_back(cur_mask);
            } else if (new_w < max_w) {
                // Extend the row with more bricks
                // Each type of brick has unlimited supply
                build_rows(new_w, max_w, bricks, cur_mask | (1 << new_w), masks);
            }
        }
    }
};
// @lc code=end
