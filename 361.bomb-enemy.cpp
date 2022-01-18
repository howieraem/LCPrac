/*
 * @lc app=leetcode id=361 lang=cpp
 *
 * [361] Bomb Enemy
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(n)
    int maxKilledEnemies(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int ans = 0, rowCnt, colCnt[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                // If left is wall:
                //   1. reset rowCount
                //   2. scan rightwards to count enemies
                //   3. update rowCount
                if (!j || grid[i][j - 1] == 'W') {
                    rowCnt = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k) {
                        rowCnt += (grid[i][k] == 'E');
                    }
                }

                // If above is wall:
                //   1. reset colCount[c]
                //   2. scan downwards to count enemies
                //   3. update colCount[c]
                if (!i || grid[i - 1][j] == 'W') {
                    colCnt[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k) {
                        colCnt[j] += (grid[k][j] == 'E');
                    }
                }

                // If this grid is neither a wall nor an enemy, update result
                if (grid[i][j] == '0') {
                    ans = max(ans, rowCnt + colCnt[j]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

