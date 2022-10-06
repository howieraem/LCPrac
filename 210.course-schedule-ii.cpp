/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1: BFS
    // T: O(V + E), V := numCourses, E := len(prerequisites)
    // S: O(V + E)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int inDeg[numCourses];
        memset(inDeg, 0, sizeof(inDeg));
        vector<vector<int>> A(numCourses);
        for (const auto &edge : prerequisites) {
            // src: edge[1], dst: edge[0]
            ++inDeg[edge[0]];
            A[edge[1]].push_back(edge[0]);
        }

        // Topological sort using BFS
        queue<int> q;
        // Start with the courses without prerequisites (in degree is 0)
        for (int i = 0; i < numCourses; ++i) {
            if (!inDeg[i]) {
                q.push(i);
            }
        }

        vector<int> res;
        res.reserve(numCourses);
        while (q.size()) {
            for (int sz = q.size(); sz > 0; --sz) {
                int pre = q.front(); q.pop();
                --numCourses;
                res.push_back(pre);

                for (const int &nxt : A[pre]) {
                    if (!(--inDeg[nxt])) {
                        // All prerequisites fulfilled
                        q.push(nxt);
                    }
                }
            }
        }
        // If not all courses (node) have been visited, then 
        // there must exist a cycle, i.e. unable to complete
        // all courses.
        return numCourses == 0 ? res: vector<int>();
    }
    */

    // Solution 2: DFS
    // T: O(V + E)
    // S: O(V + E)
#define UNVISITED 0
#define VISITING 1
#define VISITED 2
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (const auto &edge : prerequisites) {
            // src: edge[1], dst: edge[0]
            g[edge[1]].push_back(edge[0]);
        }

        vector<uint8_t> vis(numCourses, UNVISITED);
        vector<int> res;

        for (int i = 0; i < numCourses; ++i) {
            if (vis[i] != VISITED && !dfs(g, vis, i, res)) {
                return {};
            }
        }

        reverse(res.begin(), res.end());    // required for DFS solution
        return res;
    }

private:
    static bool dfs(const vector<vector<int>> &g, vector<uint8_t> &vis, int i, vector<int> &res) {
        if (vis[i] == VISITING)  return false;    // cycle found
        else if (vis[i] == VISITED)  return true;

        vis[i] = VISITING;
        for (const int &nxt : g[i]) {
            if (!dfs(g, vis, nxt, res)) {
                return false;
            }
        }
        vis[i] = VISITED;

        res.push_back(i);
        return true;
    }
};
// @lc code=end

