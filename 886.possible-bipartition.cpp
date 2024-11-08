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
    // Graph coloring + Bipartition
    // T: O(V + E)
    // S: O(V + E)
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> A(n + 1);
        vector<int> colors(n + 1, UNCOLORED);

        // Build adjacency
        for (const auto &e : dislikes) {
            // undirected
            A[e[0]].push_back(e[1]);
            A[e[1]].push_back(e[0]);
        }

        // Do BFS at each node
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (colors[i] == UNCOLORED) {
                colors[i] = BLUE;
                q.push(i);

                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (const auto& v : A[u]) {
                        if (colors[v] == colors[u]) {
                            // Conflict edge found, return false
                            return false;
                        }

                        if (colors[v] != UNCOLORED) {
                            // visited
                            continue;
                        }

                        // Assign a different color for adjacent/child nodes
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

