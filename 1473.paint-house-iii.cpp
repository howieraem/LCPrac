/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
 public:
  // T: O(m * n^2 * target)
  // S: O(m * n * target)
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
              int target) {
    // cost[i][j] <= 1e4, m <= 100
    const int MAX = 1000001;

    // m <= 100, n <= 20, target <= m
    int memo[101][21][101] = {};

    std::function<int(int, int, int)> dfs = [&](int i, int color, int tgt) {
      if (i == m || tgt < 0) {
        // Base cases
        return tgt == 0 ? 0 : MAX;
      }

      if (memo[i][color][tgt] != 0) {
        return memo[i][color][tgt];
      }

      int ans = MAX;
      if (houses[i] == 0) {
        // Check all the colors and select the one with minimum cost.
        // If pre_color != cur_color, we have a new neighborhood, so target - 1.
        for (int k = 1; k <= n; ++k) {
          ans =
              std::min(ans, dfs(i + 1, k, tgt - (k != color)) + cost[i][k - 1]);
        }
      } else {
        // House already painted, only need to decide whether it forms a new
        // neighborhood
        ans = dfs(i + 1, houses[i], tgt - (houses[i] != color));
      }
      return memo[i][color][tgt] = ans;
    };

    int ret = dfs(0, 0, target);
    return ret < MAX ? ret : -1;
  }
};
// @lc code=end
