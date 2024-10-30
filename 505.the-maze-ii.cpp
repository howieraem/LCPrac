/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
 */
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    static constexpr int D[5] {-1, 0, 1, 0, -1};

public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        // if (start == dest)  return 0;
        const int m = maze.size(), n = maze[0].size();

        // this also help checking if a cell is visited
        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<vector<int>> q;
        q.push(start);
        dist[start[0]][start[1]] = 0;

        while (q.size()) {
            int qs = q.size();

            while (qs-- > 0) {
                auto p = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int i = p[0], j = p[1];

                    // Different from normal BFS: the ball keep rolling in the current direction.
                    // Thus, it should be modelled as a graph traversal problem rather than a grid
                    // search problem.
                    int curDist = dist[i][j];
                    while (0 <= i + D[d] && i + D[d] < m && 
                        0 <= j + D[d + 1] && j + D[d + 1] < n && 
                        !maze[i + D[d]][j + D[d + 1]]) {
                        i += D[d];
                        j += D[d + 1];
                        ++curDist;
                    }

                    if (dist[i][j] == -1 || curDist < dist[i][j]) {
                        // Dijkstra's algorithm: take the shorter distance
                        dist[i][j] = curDist;
                        q.push({i, j});
                    }
                }
            }
        }
        return dist[dest[0]][dest[1]];
    }
};
// @lc code=end

