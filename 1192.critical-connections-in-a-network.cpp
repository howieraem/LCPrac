/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * An edge is a critical connection, if and only if it is not in a cycle.
     */
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        // Rank means the path distance from node 0.
        int ranks[n];
        fill_n(ranks, n, NO_RANK);

        vector<vector<int>> res;
        // Nodes are numbered from 0 to n - 1. Start from node 0.
        dfs(graph, n, 0, 0, ranks, res);
        return res;
    }

private:
    static const int NO_RANK = -2;  // not visited

    int dfs(vector<int> graph[], int n, int node, int curRank, int ranks[], vector<vector<int>>& res) {
        if (ranks[node] != NO_RANK)  return ranks[node];
        ranks[node] = curRank;

        int lowestRank = curRank;
        for (auto neighbor : graph[node]) {
            if (ranks[neighbor] == curRank - 1 || ranks[neighbor] == n) {
                // Notes for ranks[neighbor] == curRank - 1:
                // Do NOT go back immediately to parent, this will lead to parent-child-parent circle immediately.
                // This is why NO_RANK is set to -2 instead of -1, because the first node of a recursion has curRank 0.
                continue;
            }
            int neighborRank = dfs(graph, n, neighbor, curRank + 1, ranks, res);
            lowestRank = min(lowestRank, neighborRank);
            if (neighborRank > curRank) {
                if (node > neighbor) {
                    res.push_back({neighbor, node});
                } else {
                    res.push_back({node, neighbor});
                }
            }
        }

        ranks[node] = n;
        return lowestRank;
    }
};

// @lc code=end

