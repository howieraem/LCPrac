/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 */
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    static constexpr int D[] {-1, 0, 1, 0, -1};

public:
    // T: O(m * n)
    // S: O(1) (or O(m * n) if it is not allowed to modify maze)
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // if (start == destination)  return true;
        const int m = maze.size(), n = maze[0].size();
        queue<vector<int>> q;
        q.push(start);
        while (q.size()) {
            int qs = q.size();

            while (qs--) {
                auto p = q.front(); q.pop();        
                int i = p[0], j = p[1];
                maze[i][j] = 2;     // empty space visited
        
                for (int d = 0; d < 4; ++d) {
                    int ni = i + D[d], nj = j + D[d + 1];

                    // MAIN DIFFERENCE FROM NORMAL BFS
                    while (0 <= ni && ni < m && 0 <= nj && nj < n && maze[ni][nj] != 1) {
                        // Keep travelling in one direction (won't stop rolling until hitting a wall)
                        ni += D[d];
                        nj += D[d + 1];
                    }
                    // Undo the last step which is invalid
                    ni -= D[d];
                    nj -= D[d + 1];

                    if (ni == destination[0] && nj == destination[1])  return true;

                    if (!maze[ni][nj]) {
                        // not visited
                        q.push({ni, nj});
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

