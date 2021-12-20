/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
#define UNCOLORED 0
#define BLUE 1
#define GREEN 2

class Solution {
public:
    /**
     * We can represent this scenario as a graph (undirected), with people being the vertices 
     * and dislike-pairs being the edges of this graph.
     * We have to find out if the vertices can be divided into two sets such that 
     * there aren't any edges between vertices of the same set. 
     * A graph satisfying this condition is called a bipartite graph.
     */
    // T: O(V + E)
    // S: O(V + E)
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> A(n + 1);
        vector<int> colors(n + 1, UNCOLORED);
        vector<bool> vis(n + 1, false);

        // Build adjacency
        for (const auto &e : dislikes) {
            A[e[0]].push_back(e[1]);
            A[e[1]].push_back(e[0]);
        }

        // BFS
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                colors[i] = BLUE;
                q.push(i);

                while (q.size()) {
                    int u = q.front(); q.pop();
                    if (vis[u])  continue;
                    vis[u] = true;
                    for (const auto v : A[u]) {
                        if (colors[u] == colors[v]) {
                            // Conflict edge found, return false
                            return false;
                        }
                        colors[v] = colors[u] == BLUE ? GREEN : BLUE;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

